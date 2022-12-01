#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Primitives.h";

class Model {
 public:
  std::vector<Vec3<float>> m_vertcies;
  std::vector<Vec3<float>> m_normals;

 public:
  void load(const char *filename) {
    std::ifstream file(filename);
    std::string cached_line;
    std::vector<std::string> lines;
    if (!file.is_open()) {
      std::cout << "[ERROR]: Failed loading the object '" << filename
                << "' :(\n";
      return;
    }
    while (!file.eof()) {
      std::getline(file, cached_line);
      lines.push_back(cached_line);
    }
    file.close();
    float a, b, c;
    for (std::string &line : lines) {
      // Capturing the vertices
      if (line[0] == 'v' && line[1] == ' ') {
        sscanf(line.c_str(), "v %f %f %f", &a, &b, &c);
        m_vertcies.push_back({a, b, c});
      }
      // Capturing the normals
      if (line[0] == 'v' && line[1] == 'n') {
        sscanf(line.c_str(), "vn %f %f %f", &a, &b, &c);
        m_normals.push_back({a, b, c});
      }
    }
  }
};