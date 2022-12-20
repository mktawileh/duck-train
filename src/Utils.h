#pragma once

#include <string>

namespace Utils
{
  int CountChar(std::string &str, char ch)
  {
    int res = 0;
    for (const char &c : str)
      res += c == ch;
    return res;
  }
  bool HasDoubleSlash(std::string &str)
  {
    char prev = '_';
    for (const char &c : str)
    {
      if (c == '/' && prev == '/')
        return true;
      prev = c;
    }
    return false;
  }

  std::string getFilePath(const char* filename) {
    std::string path = "";
    std::string file = filename;
    int n = file.find_last_of('/');
    if (n > 0)
      path = file.substr(0, n);
    return path;
  }
};