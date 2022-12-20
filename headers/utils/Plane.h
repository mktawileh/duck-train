#pragma once

#include "MathAux.h"

// constants for ClassifyPoint()
const int POINT_ON_PLANE = 0;
const int POINT_IN_FRONT_OF_PLANE = 1;
const int POINT_BEHIND_PLANE = 2;

template <typename T>
class Plane
{
public:
	// member variables
	Vec3<T> normal; // X.N+intercept=0
	T intercept;

public:
	Plane() : normal(Vec3<T>()), intercept((T)0)
	{
	}
	Plane(Vec3<T> newNormal, T newIntercept) : normal(newNormal), intercept(newIntercept)
	{
	}
	Plane(const Plane<T> &rhs)
	{
		normal = rhs.normal;
		intercept = rhs.intercept;
	}

	~Plane() {}

	void SetNormal(const Vec3<T> &rhs) { normal = rhs; }
	void SetIntercept(T newIntercept) { intercept = newIntercept; }
	void SetFromPoints(const Vec3<T> &p0, const Vec3<T> &p1, const Vec3<T> &p2)
	{
		normal = (p1 - p0).CrossProduct(p2 - p0);

		normal.Normalize();

		CalculateIntercept(p0);
	}

	void CalculateIntercept(const Vec3<T> &pointOnPlane) { intercept = -normal.DotProduct(pointOnPlane); }

	void Normalize()
	{
		T normalLength = normal.GetLength();
		normal /= normalLength;
		intercept /= normalLength;
	}

	Vec3<T> GetNormal() { return normal; }
	T GetIntercept() { return intercept; }

	// find point of intersection of 3 planes
	bool Intersect3(const Plane<T> &p2, const Plane<T> &p3, Vec3<T> &result) // find point of intersection of 3 planes
	{
		T denominator = normal.DotProduct((p2.normal).CrossProduct(p3.normal));
		// scalar triple product of normals
		if (denominator == (T)0) // if zero
			return false;		 // no intersection

		Vec3<T> temp1, temp2, temp3;
		temp1 = (p2.normal.CrossProduct(p3.normal)) * intercept;
		temp2 = (p3.normal.CrossProduct(normal)) * p2.intercept;
		temp3 = (normal.CrossProduct(p2.normal)) * p3.intercept;

		result = (temp1 + temp2 + temp3) / (-denominator);

		return true;
	}

	T GetDistance(const Vec3<T> &point) const
	{
		return point.x * normal.x + point.y * normal.y + point.z * normal.z + intercept;
	}

	int ClassifyPoint(const Vec3<T> &point) const
	{
		T distance = point.x * normal.x + point.y * normal.y + point.z * normal.z + intercept;

		if (distance > EPSILON) //==0.0f is too exact, give a bit of room
			return POINT_IN_FRONT_OF_PLANE;

		if (distance < -EPSILON)
			return POINT_BEHIND_PLANE;

		return POINT_ON_PLANE; // otherwise
	}
	Plane<T> lerp(const Plane<T> &p2, T factor)
	{
		Plane<T> result;
		result.normal = normal * ((T)1 - factor) + p2.normal * factor;
		result.normal.Normalize();

		result.intercept = intercept * ((T)1 - factor) + p2.intercept * factor;

		return result;
	}
	// operators
	bool operator==(const Plane<T> &rhs) const
	{
		if (normal == rhs.normal && intercept == rhs.intercept)
			return true;

		return false;
	}
	bool operator!=(const Plane<T> &rhs) const
	{
		return !((*this) == rhs);
	}

	// unary operators
	Plane<T> operator-(void) const { return Plane<T>(-normal, -intercept); }
	Plane<T> operator+(void) const { return (*this); }
};
