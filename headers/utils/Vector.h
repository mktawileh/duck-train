#pragma once

/**
 * Vector 2d
 */
template <typename T>
struct Vec2
{
  T x, y;
  Vec2()
  {
    x = 0, y = 0;
  }
  Vec2(T v) : x(v), y(v)
  {
  }
  Vec2(T x, T y) : x(x), y(y)
  {
  }

  void Set(T newX, T newY)
  {
    x = newX;
    y = newY;
  }

  // Accessors kept for compatibility
  void SetX(T newX) { x = newX; }
  void SetY(T newY) { y = newY; }
  T GetX() const { return x; } // public accessor functions
  T GetY() const { return y; } // inline, const
  T GetLength() const
  {
    return (T)sqrt((x * x) + (y * y));
  }

  T GetSquaredLength() const
  {
    return (x * x) + (y * y);
  }
  void Normalize()
  {
    T length;
    T scalefactor;
    length = GetLength();

    if (length == 1 || length == 0) // return if length is 1 or 0
      return;

    scalefactor = (T)1 / length;
    x *= scalefactor;
    y *= scalefactor;
  }

  // linear interpolate
  Vec2<T> lerp(const Vec2<T> &v2, T factor) const
  {
    return (*this) * ((T)1 - factor) + v2 * factor;
  }

  Vec2<T> QuadraticInterpolate(const Vec2<T> &v2, const Vec2<T> &v3, T factor) const
  {
    return (*this) * ((T)1 - factor) * ((T)1 - factor) + 2 * v2 * factor * ((T)1 - factor) + v3 * factor * factor;
  }

  // overloaded operators
  // binary operators
  Vec2<T> operator+(const Vec2<T> &rhs) const
  {
    return Vec2<T>(x + rhs.x, y + rhs.y);
  }

  Vec2<T> operator-(const Vec2<T> &rhs) const
  {
    return Vec2<T>(x - rhs.x, y - rhs.y);
  }

  Vec2<T> operator*(const T rhs) const
  {
    return Vec2<T>(x * rhs, y * rhs);
  }

  Vec2<T> operator/(const T rhs) const
  {
    return (rhs == 0) ? Vec2<T>((T)0, (T)0) : Vec2<T>(x / rhs, y / rhs);
  }

  Vec2<T> GetNormalized() const
  {
    Vec2<T> result(*this);

    result.Normalize();

    return result;
  }

  bool operator==(const Vec2<T> &rhs) const
  {
    if (x == rhs.x && y == rhs.y)
      return true;

    return false;
  }

  operator T *() const { return (T *)this; }
  operator const T *() const { return (const T *)this; }
};
template <typename T>
Vec2<T> operator*(T scaleFactor, const Vec2<T> &rhs)
{
  return rhs * scaleFactor;
}

/**
 * Vector 3d
 */
template <typename T>
struct Vec3
{
  T x, y, z;
  Vec3()
  {
    x = 0, y = 0, z = 0;
  }
  Vec3(T v) : x(v), y(v), z(v)
  {
  }
  Vec3(T x, T y, T z) : x(x), y(y), z(z)
  {
  }

  void Set(T newX, T newY, T newZ)
  {
    x = newX;
    y = newY;
    z = newZ;
  }

  // Accessors kept for compatibility
  void SetX(T newX) { x = newX; }
  void SetY(T newY) { y = newY; }
  void SetZ(T newZ) { z = newZ; }

  T GetX() const { return x; } // public accessor functions
  T GetY() const { return y; } // inline, const
  T GetZ() const { return z; }

  void LoadZero(void)
  {
    x = y = z = (T)0;
  }
  void LoadOne(void)
  {
    x = y = z = (T)1;
  }

  // vector algebra
  Vec3<T> CrossProduct(const Vec3<T> &rhs) const
  {
    return Vec3<T>(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
  }

  T DotProduct(const Vec3<T> &rhs) const
  {
    return x * rhs.x + y * rhs.y + z * rhs.z;
  }

  void Normalize()
  {
    T length = GetLength();

    if (length == 1 || length == 0) // return if length is 1 or 0
      return;

    T scalefactor = (T)1 / length;
    x *= scalefactor;
    y *= scalefactor;
    z *= scalefactor;
  }

  T GetLength() const
  {
    return (T)sqrt((x * x) + (y * y) + (z * z));
  }

  T GetSquaredLength() const
  {
    return (x * x) + (y * y) + (z * z);
  }

  Vec3<T> GetNormalized() const
  {
    Vec3<T> result(*this);

    result.Normalize();

    return result;
  }

  Vec3<T> GetRotatedX(double angle) const
  {
    if (angle == 0.0)
      return (*this);

    T sinAngle = (T)sin(M_PI * angle / 180);
    T cosAngle = (T)cos(M_PI * angle / 180);

    return Vec3<T>(x,
                   y * cosAngle - z * sinAngle,
                   y * sinAngle + z * cosAngle);
  }
  void RotateX(double angle)
  {
    (*this) = GetRotatedX(angle);
  }

  Vec3<T> GetRotatedY(double angle) const
  {
    if (angle == 0.0)
      return (*this);

    T sinAngle = (T)sin(M_PI * angle / 180);
    T cosAngle = (T)cos(M_PI * angle / 180);

    return Vec3<T>(x * cosAngle + z * sinAngle,
                   y,
                   -x * sinAngle + z * cosAngle);
  }
  void RotateY(double angle)
  {
    (*this) = GetRotatedY(angle);
  }

  Vec3<T> GetRotatedZ(double angle) const
  {
    if (angle == 0.0)
      return (*this);

    T sinAngle = (T)sin(M_PI * angle / 180);
    T cosAngle = (T)cos(M_PI * angle / 180);

    return Vec3<T>(x * cosAngle - y * sinAngle,
                   x * sinAngle + y * cosAngle,
                   z);
  }
  void RotateZ(double angle)
  {
    (*this) = GetRotatedZ(angle);
  }

  Vec3<T> GetRotatedAxis(double angle, const Vec3<T> &axis) const
  {
    if (angle == 0.0)
      return (*this);

    Vec3<T> u = axis.GetNormalized();

    Vec3<T> rotMatrixRow0, rotMatrixRow1, rotMatrixRow2;

    T sinAngle = (T)sin(M_PI * angle / 180);
    T cosAngle = (T)cos(M_PI * angle / 180);
    T oneMinusCosAngle = 1.0f - cosAngle;

    rotMatrixRow0.x = (u.x) * (u.x) + cosAngle * (1 - (u.x) * (u.x));
    rotMatrixRow0.y = (u.x) * (u.y) * (oneMinusCosAngle)-sinAngle * u.z;
    rotMatrixRow0.z = (u.x) * (u.z) * (oneMinusCosAngle) + sinAngle * u.y;

    rotMatrixRow1.x = (u.x) * (u.y) * (oneMinusCosAngle) + sinAngle * u.z;
    rotMatrixRow1.y = (u.y) * (u.y) + cosAngle * (1 - (u.y) * (u.y));
    rotMatrixRow1.z = (u.y) * (u.z) * (oneMinusCosAngle)-sinAngle * u.x;

    rotMatrixRow2.x = (u.x) * (u.z) * (oneMinusCosAngle)-sinAngle * u.y;
    rotMatrixRow2.y = (u.y) * (u.z) * (oneMinusCosAngle) + sinAngle * u.x;
    rotMatrixRow2.z = (u.z) * (u.z) + cosAngle * (1 - (u.z) * (u.z));

    return Vec3<T>(this->DotProduct(rotMatrixRow0),
                   this->DotProduct(rotMatrixRow1),
                   this->DotProduct(rotMatrixRow2));
  }

  void RotateAxis(double angle, const Vec3<T> &axis)
  {
    (*this) = GetRotatedAxis(angle, axis);
  }

  void PackTo01()
  {
    (*this) = GetPackedTo01();
  }

  Vec3<T> GetPackedTo01() const
  {
    Vec3<T> temp(*this);

    temp.Normalize();

    temp = temp * (T)0.5 + Vec3<T>((T)0.5, (T)0.5, (T)0.5);

    return temp;
  }

  // linear interpolate
  Vec3<T> lerp(const Vec3<T> &v2, T factor) const
  {
    return (*this) * ((T)1 - factor) + v2 * factor;
  }

  Vec3<T> QuadraticInterpolate(const Vec3<T> &v2, const Vec3<T> &v3, T factor) const
  {
    return (*this) * ((T)1 - factor) * ((T)1 - factor) + 2 * v2 * factor * ((T)1 - factor) + v3 * factor * factor;
  }

  // overloaded operators
  // binary operators
  Vec3<T> operator+(const Vec3<T> &rhs) const
  {
    return Vec3<T>(x + rhs.x, y + rhs.y, z + rhs.z);
  }

  Vec3<T> operator-(const Vec3<T> &rhs) const
  {
    return Vec3<T>(x - rhs.x, y - rhs.y, z - rhs.z);
  }

  Vec3<T> operator*(const T rhs) const
  {
    return Vec3<T>(x * rhs, y * rhs, z * rhs);
  }

  Vec3<T> operator/(const T rhs) const
  {
    return (rhs == 0.0f) ? Vec3<T>(0.0f, 0.0f, 0.0f) : Vec3<T>(x / rhs, y / rhs, z / rhs);
  }

  // Add, subtract etc, saving the construction of a temporary
  void Add(const Vec3<T> &v2, Vec3<T> &result)
  {
    result.x = x + v2.x;
    result.y = y + v2.y;
    result.z = z + v2.z;
  }

  void Subtract(const Vec3<T> &v2, Vec3<T> &result)
  {
    result.x = x - v2.x;
    result.y = y - v2.y;
    result.z = z - v2.z;
  }

  bool operator==(const Vec3<T> &rhs) const
  {
    if (x == rhs.x && y == rhs.y && z == rhs.z)
      return true;

    return false;
  }

  bool operator!=(const Vec3<T> &rhs) const
  {
    return !((*this) == rhs);
  }

  // self-add etc
  void operator+=(const Vec3<T> &rhs)
  {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
  }

  void operator-=(const Vec3<T> &rhs)
  {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
  }

  void operator*=(const T rhs)
  {
    x *= rhs;
    y *= rhs;
    z *= rhs;
  }

  void operator/=(const T rhs)
  {
    if (rhs == 0.0f)
      return;
    else
    {
      x /= rhs;
      y /= rhs;
      z /= rhs;
    }
  }

  // unary operators
  Vec3<T> operator-(void) const { return Vec3<T>(-x, -y, -z); }
  Vec3<T> operator+(void) const { return *this; }

  // cast to pointer to a (float *) for glVertex3fv etc
  operator T *() const { return (T *)this; }
  operator const T *() const { return (const T *)this; }
};

template <typename T>
Vec3<T> operator*(T scaleFactor, const Vec3<T> &rhs)
{
  return rhs * scaleFactor;
}

/**
 * Vector 4d
 */
template <typename T>
struct Vec4
{
  T x, y, z, w;
  Vec4()
  {
    x = 0, y = 0, z = 0, w = 0;
  }
  Vec4(T v) : x(v), y(v), z(v), w(v)
  {
  }
  Vec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w)
  {
  }
  Vec4(const Vec3<T> &vec) : x(vec.x), y(vec.y), z(vec.z), w(1.0f)
  {
  }

  void Set(T newX, T newY, T newZ, T newW)
  {
    x = newX;
    y = newY;
    z = newZ;
    w = newW;
  }

  // accessors kept for compatability
  void SetX(T newX) { x = newX; }
  void SetY(T newY) { y = newY; }
  void SetZ(T newZ) { z = newZ; }
  void SetW(T newW) { w = newW; }

  T GetX() const { return x; } // public accessor functions
  T GetY() const { return y; } // inline, const
  T GetZ() const { return z; }
  T GetW() const { return w; }

  void LoadZero(void)
  {
    x = (T)0;
    y = (T)0;
    z = (T)0;
    w = (T)0;
  }

  void LoadOne(void)
  {
    x = (T)1;
    y = (T)1;
    z = (T)1;
    w = (T)1;
  }

  // vector algebra
  T DotProduct(const Vec4<T> &rhs)
  {
    return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
  }

  void RotateX(double angle)
  {
    (*this) = GetRotatedX(angle);
  }

  Vec4<T> GetRotatedX(double angle) const
  {
    Vec3<T> v3d(x, y, z);

    v3d.RotateX(angle);

    return Vec4<T>(v3d.x, v3d.y, v3d.z, w);
  }

  void RotateY(double angle)
  {
    (*this) = GetRotatedY(angle);
  }

  Vec4<T> GetRotatedY(double angle) const
  {
    Vec3<T> v3d(x, y, z);

    v3d.RotateY(angle);

    return Vec4<T>(v3d.x, v3d.y, v3d.z, w);
  }

  void RotateZ(double angle)
  {
    (*this) = GetRotatedZ(angle);
  }

  Vec4<T> GetRotatedZ(double angle) const
  {
    Vec3<T> v3d(x, y, z);

    v3d.RotateZ(angle);

    return Vec4<T>(v3d.x, v3d.y, v3d.z, w);
  }

  void RotateAxis(double angle, const Vec3<T> &axis)
  {
    (*this) = GetRotatedAxis(angle, axis);
  }

  Vec4<T> GetRotatedAxis(double angle, const Vec3<T> &axis) const
  {
    Vec3<T> v3d(x, y, z);

    v3d.RotateAxis(angle, axis);

    return Vec4<T>(v3d.x, v3d.y, v3d.z, w);
  }
  bool operator==(const Vec4<T> &rhs) const
  {
    if (x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w)
      return true;

    return false;
  }

  Vec4<T> lerp(const Vec4<T> &v2, T factor) const
  {
    return (*this) * (1.0f - factor) + v2 * factor;
  }

  Vec4<T> QuadraticInterpolate(const Vec4<T> &v2, const Vec4<T> &v3, T factor) const
  {
    return (*this) * (1.0f - factor) * (1.0f - factor) + 2 * v2 * factor * (1.0f - factor) + v3 * factor * factor;
  }

  // binary operators
  Vec4<T> operator+(const Vec4<T> &rhs) const
  {
    return Vec4<T>(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
  }

  Vec4<T> operator-(const Vec4<T> &rhs) const
  {
    return Vec4<T>(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
  }

  Vec4<T> operator*(const T rhs) const
  {
    return Vec4<T>(x * rhs, y * rhs, z * rhs, w * rhs);
  }

  Vec4<T> operator/(const T rhs) const
  {
    return rhs == (T)0 ? Vec4<T>((T)0, (T)0, (T)0, (T)0)
                       : Vec4<T>(x / rhs, y / rhs, z / rhs, w / rhs);
  }

  // multiply by a float, eg 3*v
  template <class Type>
  friend Vec4<Type> operator*(Type scaleFactor, const Vec4<Type> &rhs);

  bool operator!=(const Vec4<T> &rhs) const
  {
    return !((*this) == rhs);
  }

  // self-add etc
  void operator+=(const Vec4<T> &rhs)
  {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    w += rhs.w;
  }

  void operator-=(const Vec4<T> &rhs)
  {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    w -= rhs.w;
  }

  void operator*=(const T rhs)
  {
    x *= rhs;
    y *= rhs;
    z *= rhs;
    w *= rhs;
  }

  void operator/=(const T rhs)
  {
    if (rhs == (T)0)
      return;
    else
    {
      x /= rhs;
      y /= rhs;
      z /= rhs;
      w /= rhs;
    }
  }

  // unary operators
  Vec4<T> operator-(void) const { return Vec4<T>(-x, -y, -z, -w); }
  Vec4<T> operator+(void) const { return (*this); }

  // cast to pointer to float for glVertex4fv etc
  operator T *() const { return (T *)this; }
  operator const T *() const { return (const T *)this; }

  operator Vec3<T>()
  {
    if (w == 0.0f || w == 1.0f)
      return Vec3<T>(x, y, z);
    else
      return Vec3<T>(x / w, y / w, z / w);
  }
};
