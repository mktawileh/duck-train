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
  Face(std::vector<int> &v, std::vector<int> &t, int n) : vertices(v), texcoords(t), normal(n) {}
};

class Model
{
private:
  std::vector<Vec3<GLfloat>> m_vertcies, m_normals, m_texcoords;
  std::vector<Face> m_faces;
  GLuint list;

  void m_ReadFaces(const char *filename)
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
      if (line[0] == 'v' && line[1] == 't') {
        sscanf(line.c_str(), "vt %f %f %f", &a, &b, &c);
        m_texcoords.push_back({a, b, c});
      }
      // Capturing the faces
      if (line[0] == 'f')
      {
        int v[3], t[3], n;
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
    }
  }

  void m_InitDisplayList()
  {
    list = glGenLists(1);
    glNewList(list, GL_COMPILE);
    for (const Face &face : m_faces)
    {

      // Draw vertices, texcoords and normal vector
      if (face.normal != -1 && face.texcoords[0] != -1)
      {
        glBegin(GL_TRIANGLES);
        for (int i = 0; i < 3; i++)
        {
          glTexCoord2fv((GLfloat *)&m_texcoords[face.texcoords[i]]);
          glVertex3fv((GLfloat *)&m_vertcies[face.vertices[i]]);
        }
        glNormal3fv((GLfloat *)&m_normals[face.normal]);
        glEnd();
      }

      // Draw only vertices and normal vecotr
      else if (face.normal != 1 && face.texcoords[0] == -1)
      {
        glBegin(GL_TRIANGLES);
        for (int i = 0; i < 3; i++)
        {
          glVertex3fv((GLfloat *)&m_vertcies[face.vertices[i]]);
        }
        glNormal3fv((GLfloat *)&m_normals[face.normal]);
        glEnd();
      }

      // Draw only vertices and texcoords
      else if (face.normal == -1 && face.texcoords[0] != -1)
      {
        glBegin(GL_TRIANGLES);
        for (int i = 0; i < 3; i++)
        {
          glTexCoord2fv((GLfloat *)&m_texcoords[face.texcoords[i]]);
          glVertex3fv((GLfloat *)&m_vertcies[face.vertices[i]]);
        }
        glEnd();
      }
    }
    glEndList();
    m_vertcies.clear();
    m_normals.clear();
    m_faces.clear();
    m_texcoords.clear();
  }

public:
  void Load(const char *filename)
  {
    m_ReadFaces(filename);
    m_InitDisplayList();
  }

  void Draw()
  {
    glCallList(list);
  }

  void PrintFaces()
  {
    std::cout << "f: " << m_texcoords.size() << " v: " << m_vertcies.size() << " n: " << m_normals.size() << '\n'; 
    for (const Face &f : m_faces)
    {
      std::cout << f.texcoords[0] << " " << f.texcoords[1] << " " << f.texcoords[2] << " n = " << f.normal << '\n';
    }
  }
};