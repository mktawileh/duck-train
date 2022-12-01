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
};