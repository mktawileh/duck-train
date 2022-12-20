#pragma once

#include "Math.h"

template <typename T>
struct RGBA
{
  T r, g, b, a;
};

template <typename T>
struct Face4v
{
  T a, b, c, d;
  T normal;
};

class Drawable
{
public:
  virtual void Init() = 0;
  virtual void Draw() = 0;
};
