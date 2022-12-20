#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <array>

#include "Primitives.h"
#include "Utils.h"

class Face
{
public:
  std::vector<int> vertices;
  std::vector<int> texcoords;
  int normal;
  int mat = -1;
  Face(std::vector<int> &v, std::vector<int> &t, int n) : vertices(v), texcoords(t), normal(n), mat(-1) {}
  Face(int mat) : mat(mat) {}
};

class Material
{
public:
  RGBA<GLfloat> ambient;  // Ka
  RGBA<GLfloat> diffuse;  // Kd
  RGBA<GLfloat> specular; // Ks
  RGBA<GLfloat> emissive; // Ke
  GLfloat shininess;      // Ns
  GLuint texture;

  void Use()
  {
  }

  void Init()
  {
  }
};

class Model
{
private:
  std::vector<Vec3<GLfloat>> m_vertcies, m_normals, m_texcoords;
  std::vector<Face> m_faces;
  std::vector<Material> m_materials;
  char mtlfile[40];

  GLuint list;

  void m_LoadFaces(const char *filename)
  {
    std::ifstream file(filename);
    std::string cached_line;
    std::vector<std::string> lines;
    if (!file.is_open())
    {
      std::cout << "[ERROR]: Failed loading the object '" << filename
                << "' :(\n";
      return;
    }
    while (!file.eof())
    {
      std::getline(file, cached_line);
      lines.push_back(cached_line);
    }
    file.close();
    float a, b, c;
    for (std::string &line : lines)
    {
      // Capturing the vertices
      if (line[0] == 'v' && line[1] == ' ')
      {
        sscanf(line.c_str(), "v %f %f %f", &a, &b, &c);
        m_vertcies.push_back({a, b, c});
      }
      // Capturing the normals
      if (line[0] == 'v' && line[1] == 'n')
      {
        sscanf(line.c_str(), "vn %f %f %f", &a, &b, &c);
        m_normals.push_back({a, b, c});
      }
      // Capturing the texcoords
      if (line[0] == 'v' && line[1] == 't')
      {
        sscanf(line.c_str(), "vt %f %f %f", &a, &b, &c);
        m_texcoords.push_back({a, b, c});
      }
      // Capturing the faces
      else if (line[0] == 'f')
      {
        int v[3] = {0, 0, 0}, t[3] = {0, 0, 0}, n = 0;
        // Adding face without texture vertices.
        if (Utils::HasDoubleSlash(line))
        {
          sscanf(line.c_str(), "f %d//%d %d//%d %d//%d", &v[0], &n, &v[1], &n, &v[2], &n);
          t[0] = t[1] = t[2] = -1;
        }
        // Adding face without normal vertices.
        else if (Utils::CountChar(line, '/') == 3)
        {
          sscanf(line.c_str(), "f %d/%d %d/%d %d/%d", &v[0], &t[0], &v[1], &t[1], &v[2], &t[2]);
          n = -1;
        }
        // Adding face with all the vertices.
        else
        {
          sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d", &v[0], &t[0], &n, &v[1], &t[1], &n, &v[2], &t[2], &n);
        }
        v[0]--, v[1]--, v[2]--;
        t[0]--, t[1]--, t[2]--;
        std::vector<int> ver(v, v + 3), tex(t, t + 3);
        m_faces.push_back(Face(ver, tex, n - 1));
      }
      // Capturing mtl files
      if (line[0] == 'm' && line[1] == 't')
      {
        sscanf(line.c_str(), "mtllib %s", &mtlfile);
      }
      // Capturing mtl usese
      if (line[0] == 'u' && line[1] == 's')
      {
        int num;
        sscanf(line.c_str(), "usemtl Material.%d", &num);
        m_faces.push_back(Face(num - 1));
      }
    }
  }

  void m_LoadMaterials(const char *filename)
  {
    std::ifstream file(filename);
    std::string cached_line;
    std::vector<std::string> lines;
    if (!file.is_open())
    {
      std::cout << "[ERROR]: Failed loading the object '" << filename
                << "' :(\n";
      return;
    }
    while (!file.eof())
    {
      std::getline(file, cached_line);
      lines.push_back(cached_line);
    }
    file.close();
    float a, b, c;
    int num = -1, index = -1;

    for (std::string &line : lines)
    {
      // Capturing Material Index
      if (line[0] == 'n' && line[1] == 'e')
      {
        sscanf(line.c_str(), "newmtl Material.%d", &num);
        num--;
        if (num != ++index)
          throw "[ERROR]: .mtl format conflict";
        Material m;
        m_materials.push_back(m);
      }
      // Capturing Shininess
      else if (line[0] == 'N' && line[1] == 's')
      {
        sscanf(line.c_str(), "Ns %f", &a);
        m_materials[index].shininess = a;
      }
      // Capturing Abient
      else if (line[0] == 'K' && line[1] == 'a')
      {
        sscanf(line.c_str(), "Ka %f %f %f", &a, &b, &c);
        m_materials[index].ambient = {a, b, c, 1};
      }
      // Capturing Diffuse
      else if (line[0] == 'K' && line[1] == 'd')
      {
        sscanf(line.c_str(), "Kd %f %f %f", &a, &b, &c);
        m_materials[index].diffuse = {a, b, c, 1};
      }
      // Capturing Specular
      else if (line[0] == 'K' && line[1] == 's')
      {
        sscanf(line.c_str(), "Ks %f %f %f", &a, &b, &c);
        m_materials[index].specular = {a, b, c, 1};
      }
      // Capturing Emissive
      else if (line[0] == 'K' && line[1] == 'e')
      {
        sscanf(line.c_str(), "Ke %f %f %f", &a, &b, &c);
        m_materials[index].emissive = {a, b, c, 1};
      }
    }
  }

  void m_InitDisplayList()
  {
    list = glGenLists(1);
    glNewList(list, GL_COMPILE);
    for (int i = 0; i < (int)m_faces.size(); i++)
    {
      const Face &face = m_faces[i];
      // Enabling Materials
      if (face.mat != -1)
      {
        // glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat *)&m_materials[face.mat].ambient);
        // glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat *)&m_materials[face.mat].diffuse);
        // glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat *)&m_materials[face.mat].specular);
        // glMaterialf(GL_FRONT, GL_SHININESS, m_materials[face.mat].shininess);
        // glMaterialfv(GL_FRONT, GL_EMISSION, (GLfloat *)&m_materials[face.mat].emissive);
      }
      // Draw vertices, texcoords and normal vector
      else if (face.normal != -1 && face.texcoords[0] != -1)
      {
        glNormal3fv((GLfloat *)&m_normals[face.normal]);
        glBegin(GL_TRIANGLES);
        for (int i = 0; i < 3; i++)
        {
          glTexCoord2fv((GLfloat *)&m_texcoords[face.texcoords[i]]);
          glVertex3fv((GLfloat *)&m_vertcies[face.vertices[i]]);
        }
        glEnd();
      }

      // Draw only vertices and normal vecotr
      else if (face.normal != 1 && face.texcoords[0] == -1)
      {
        glNormal3fv((GLfloat *)&m_normals[face.normal]);
        glBegin(GL_TRIANGLES);
        for (int i = 0; i < 3; i++)
        {
          glVertex3fv((GLfloat *)&m_vertcies[face.vertices[i]]);
        }
        glEnd();
      }

      // Draw only vertices and texcoords
      else if (face.normal == -1 && face.texcoords[0] != -1)
      {
        glDisable(GL_LIGHTING);
        std::cout << "disableing lighting...\n";
        glBegin(GL_TRIANGLES);
        for (int i = 0; i < 3; i++)
        {
          glTexCoord2fv((GLfloat *)&m_texcoords[face.texcoords[i]]);
          glVertex3fv((GLfloat *)&m_vertcies[face.vertices[i]]);
        }
        glEnd();
        glEnable(GL_LIGHTING);
        std::cout << "enabling lighting...\n";
      }
    }
    glEndList();
    m_vertcies.clear();
    m_normals.clear();
    m_faces.clear();
    m_texcoords.clear();
    // m_materials.clear();
  }

public:
  void Load(const char *filename)
  {
    std::string path = Utils::getFilePath(filename);
    m_LoadFaces(filename);
    std::string mtlFileFullPath = path + "/" + mtlfile;
    m_LoadMaterials(mtlFileFullPath.c_str());
    m_InitDisplayList();
  }

  void Draw()
  {
    glCallList(list);
  }

  void PrintMat()
  {
    std::cout << "num of mats: " << m_materials.size() << std::endl;
  }
};