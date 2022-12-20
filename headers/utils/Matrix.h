#pragma once

#include <memory.h>
#include "MathAux.h"

template <typename T>
class Matrix4
{
public:
	// member variables
	T entries[16];
	Matrix4()
	{
		LoadIdentity();
	}
	Matrix4(T e0, T e1, T e2, T e3,
			T e4, T e5, T e6, T e7,
			T e8, T e9, T e10, T e11,
			T e12, T e13, T e14, T e15)
	{
		entries[0] = e0;
		entries[1] = e1;
		entries[2] = e2;
		entries[3] = e3;
		entries[4] = e4;
		entries[5] = e5;
		entries[6] = e6;
		entries[7] = e7;
		entries[8] = e8;
		entries[9] = e9;
		entries[10] = e10;
		entries[11] = e11;
		entries[12] = e12;
		entries[13] = e13;
		entries[14] = e14;
		entries[15] = e15;
	}

	Matrix4(const T *rhs)
	{
		memcpy(entries, rhs, 16 * sizeof(T));
	}

	Matrix4(const Matrix4<T> &rhs)
	{
		memcpy(entries, rhs.entries, 16 * sizeof(float));
	}

	~Matrix4() {} // empty

	void SetEntry(int position, T value)
	{
		if (position >= 0 && position <= 15)
			entries[position] = value;
	}
	T GetEntry(int position) const
	{
		if (position >= 0 && position <= 15)
			return entries[position];

		return (T)0;
	}

	Vec4<T> GetRow(int position) const
	{
		if (position == 0)
			return Vec4<T>(entries[0], entries[4], entries[8], entries[12]);

		if (position == 1)
			return Vec4<T>(entries[1], entries[5], entries[9], entries[13]);

		if (position == 2)
			return Vec4<T>(entries[2], entries[6], entries[10], entries[14]);

		if (position == 3)
			return Vec4<T>(entries[3], entries[7], entries[11], entries[15]);

		return Vec4<T>(0.0f, 0.0f, 0.0f, 0.0f);
	}

	Vec4<T> GetColumn(int position) const
	{
		if (position == 0)
			return Vec4<T>(entries[0], entries[1], entries[2], entries[3]);

		if (position == 1)
			return Vec4<T>(entries[4], entries[5], entries[6], entries[7]);

		if (position == 2)
			return Vec4<T>(entries[8], entries[9], entries[10], entries[11]);

		if (position == 3)
			return Vec4<T>(entries[12], entries[13], entries[14], entries[15]);

		return Vec4<T>(0.0f, 0.0f, 0.0f, 0.0f);
	}

	void LoadIdentity(void)
	{
		memset(entries, 0, 16 * sizeof(T));
		entries[0] = 1.0f;
		entries[5] = 1.0f;
		entries[10] = 1.0f;
		entries[15] = 1.0f;
	}
	void LoadZero(void)
	{
		memset(entries, 0, 16 * sizeof(T));
	}

	// binary operators
	Matrix4<T> operator+(const Matrix4<T> &rhs) const // overloaded operators
	{
		return Matrix4<T>(entries[0] + rhs.entries[0],
						  entries[1] + rhs.entries[1],
						  entries[2] + rhs.entries[2],
						  entries[3] + rhs.entries[3],
						  entries[4] + rhs.entries[4],
						  entries[5] + rhs.entries[5],
						  entries[6] + rhs.entries[6],
						  entries[7] + rhs.entries[7],
						  entries[8] + rhs.entries[8],
						  entries[9] + rhs.entries[9],
						  entries[10] + rhs.entries[10],
						  entries[11] + rhs.entries[11],
						  entries[12] + rhs.entries[12],
						  entries[13] + rhs.entries[13],
						  entries[14] + rhs.entries[14],
						  entries[15] + rhs.entries[15]);
	}

	Matrix4<T> operator-(const Matrix4<T> &rhs) const // overloaded operators
	{
		return Matrix4<T>(entries[0] - rhs.entries[0],
						  entries[1] - rhs.entries[1],
						  entries[2] - rhs.entries[2],
						  entries[3] - rhs.entries[3],
						  entries[4] - rhs.entries[4],
						  entries[5] - rhs.entries[5],
						  entries[6] - rhs.entries[6],
						  entries[7] - rhs.entries[7],
						  entries[8] - rhs.entries[8],
						  entries[9] - rhs.entries[9],
						  entries[10] - rhs.entries[10],
						  entries[11] - rhs.entries[11],
						  entries[12] - rhs.entries[12],
						  entries[13] - rhs.entries[13],
						  entries[14] - rhs.entries[14],
						  entries[15] - rhs.entries[15]);
	}

	Matrix4<T> operator*(const Matrix4<T> &rhs) const
	{
		// Optimise for matrices in which bottom row is (0, 0, 0, 1) in both matrices
		if (entries[3] == 0.0f && entries[7] == 0.0f && entries[11] == 0.0f && entries[15] == 1.0f &&
			rhs.entries[3] == 0.0f && rhs.entries[7] == 0.0f &&
			rhs.entries[11] == 0.0f && rhs.entries[15] == 1.0f)
		{
			return Matrix4<T>(entries[0] * rhs.entries[0] + entries[4] * rhs.entries[1] + entries[8] * rhs.entries[2],
							  entries[1] * rhs.entries[0] + entries[5] * rhs.entries[1] + entries[9] * rhs.entries[2],
							  entries[2] * rhs.entries[0] + entries[6] * rhs.entries[1] + entries[10] * rhs.entries[2],
							  0.0f,
							  entries[0] * rhs.entries[4] + entries[4] * rhs.entries[5] + entries[8] * rhs.entries[6],
							  entries[1] * rhs.entries[4] + entries[5] * rhs.entries[5] + entries[9] * rhs.entries[6],
							  entries[2] * rhs.entries[4] + entries[6] * rhs.entries[5] + entries[10] * rhs.entries[6],
							  0.0f,
							  entries[0] * rhs.entries[8] + entries[4] * rhs.entries[9] + entries[8] * rhs.entries[10],
							  entries[1] * rhs.entries[8] + entries[5] * rhs.entries[9] + entries[9] * rhs.entries[10],
							  entries[2] * rhs.entries[8] + entries[6] * rhs.entries[9] + entries[10] * rhs.entries[10],
							  0.0f,
							  entries[0] * rhs.entries[12] + entries[4] * rhs.entries[13] + entries[8] * rhs.entries[14] + entries[12],
							  entries[1] * rhs.entries[12] + entries[5] * rhs.entries[13] + entries[9] * rhs.entries[14] + entries[13],
							  entries[2] * rhs.entries[12] + entries[6] * rhs.entries[13] + entries[10] * rhs.entries[14] + entries[14],
							  1.0f);
		}

		// Optimise for when bottom row of 1st matrix is (0, 0, 0, 1)
		if (entries[3] == 0.0f && entries[7] == 0.0f && entries[11] == 0.0f && entries[15] == 1.0f)
		{
			return Matrix4<T>(entries[0] * rhs.entries[0] + entries[4] * rhs.entries[1] + entries[8] * rhs.entries[2] + entries[12] * rhs.entries[3],
							  entries[1] * rhs.entries[0] + entries[5] * rhs.entries[1] + entries[9] * rhs.entries[2] + entries[13] * rhs.entries[3],
							  entries[2] * rhs.entries[0] + entries[6] * rhs.entries[1] + entries[10] * rhs.entries[2] + entries[14] * rhs.entries[3],
							  rhs.entries[3],
							  entries[0] * rhs.entries[4] + entries[4] * rhs.entries[5] + entries[8] * rhs.entries[6] + entries[12] * rhs.entries[7],
							  entries[1] * rhs.entries[4] + entries[5] * rhs.entries[5] + entries[9] * rhs.entries[6] + entries[13] * rhs.entries[7],
							  entries[2] * rhs.entries[4] + entries[6] * rhs.entries[5] + entries[10] * rhs.entries[6] + entries[14] * rhs.entries[7],
							  rhs.entries[7],
							  entries[0] * rhs.entries[8] + entries[4] * rhs.entries[9] + entries[8] * rhs.entries[10] + entries[12] * rhs.entries[11],
							  entries[1] * rhs.entries[8] + entries[5] * rhs.entries[9] + entries[9] * rhs.entries[10] + entries[13] * rhs.entries[11],
							  entries[2] * rhs.entries[8] + entries[6] * rhs.entries[9] + entries[10] * rhs.entries[10] + entries[14] * rhs.entries[11],
							  rhs.entries[11],
							  entries[0] * rhs.entries[12] + entries[4] * rhs.entries[13] + entries[8] * rhs.entries[14] + entries[12] * rhs.entries[15],
							  entries[1] * rhs.entries[12] + entries[5] * rhs.entries[13] + entries[9] * rhs.entries[14] + entries[13] * rhs.entries[15],
							  entries[2] * rhs.entries[12] + entries[6] * rhs.entries[13] + entries[10] * rhs.entries[14] + entries[14] * rhs.entries[15],
							  rhs.entries[15]);
		}

		// Optimise for when bottom row of 2nd matrix is (0, 0, 0, 1)
		if (rhs.entries[3] == 0.0f && rhs.entries[7] == 0.0f &&
			rhs.entries[11] == 0.0f && rhs.entries[15] == 1.0f)
		{
			return Matrix4<T>(entries[0] * rhs.entries[0] + entries[4] * rhs.entries[1] + entries[8] * rhs.entries[2],
							  entries[1] * rhs.entries[0] + entries[5] * rhs.entries[1] + entries[9] * rhs.entries[2],
							  entries[2] * rhs.entries[0] + entries[6] * rhs.entries[1] + entries[10] * rhs.entries[2],
							  entries[3] * rhs.entries[0] + entries[7] * rhs.entries[1] + entries[11] * rhs.entries[2],
							  entries[0] * rhs.entries[4] + entries[4] * rhs.entries[5] + entries[8] * rhs.entries[6],
							  entries[1] * rhs.entries[4] + entries[5] * rhs.entries[5] + entries[9] * rhs.entries[6],
							  entries[2] * rhs.entries[4] + entries[6] * rhs.entries[5] + entries[10] * rhs.entries[6],
							  entries[3] * rhs.entries[4] + entries[7] * rhs.entries[5] + entries[11] * rhs.entries[6],
							  entries[0] * rhs.entries[8] + entries[4] * rhs.entries[9] + entries[8] * rhs.entries[10],
							  entries[1] * rhs.entries[8] + entries[5] * rhs.entries[9] + entries[9] * rhs.entries[10],
							  entries[2] * rhs.entries[8] + entries[6] * rhs.entries[9] + entries[10] * rhs.entries[10],
							  entries[3] * rhs.entries[8] + entries[7] * rhs.entries[9] + entries[11] * rhs.entries[10],
							  entries[0] * rhs.entries[12] + entries[4] * rhs.entries[13] + entries[8] * rhs.entries[14] + entries[12],
							  entries[1] * rhs.entries[12] + entries[5] * rhs.entries[13] + entries[9] * rhs.entries[14] + entries[13],
							  entries[2] * rhs.entries[12] + entries[6] * rhs.entries[13] + entries[10] * rhs.entries[14] + entries[14],
							  entries[3] * rhs.entries[12] + entries[7] * rhs.entries[13] + entries[11] * rhs.entries[14] + entries[15]);
		}

		return Matrix4<T>(entries[0] * rhs.entries[0] + entries[4] * rhs.entries[1] + entries[8] * rhs.entries[2] + entries[12] * rhs.entries[3],
						  entries[1] * rhs.entries[0] + entries[5] * rhs.entries[1] + entries[9] * rhs.entries[2] + entries[13] * rhs.entries[3],
						  entries[2] * rhs.entries[0] + entries[6] * rhs.entries[1] + entries[10] * rhs.entries[2] + entries[14] * rhs.entries[3],
						  entries[3] * rhs.entries[0] + entries[7] * rhs.entries[1] + entries[11] * rhs.entries[2] + entries[15] * rhs.entries[3],
						  entries[0] * rhs.entries[4] + entries[4] * rhs.entries[5] + entries[8] * rhs.entries[6] + entries[12] * rhs.entries[7],
						  entries[1] * rhs.entries[4] + entries[5] * rhs.entries[5] + entries[9] * rhs.entries[6] + entries[13] * rhs.entries[7],
						  entries[2] * rhs.entries[4] + entries[6] * rhs.entries[5] + entries[10] * rhs.entries[6] + entries[14] * rhs.entries[7],
						  entries[3] * rhs.entries[4] + entries[7] * rhs.entries[5] + entries[11] * rhs.entries[6] + entries[15] * rhs.entries[7],
						  entries[0] * rhs.entries[8] + entries[4] * rhs.entries[9] + entries[8] * rhs.entries[10] + entries[12] * rhs.entries[11],
						  entries[1] * rhs.entries[8] + entries[5] * rhs.entries[9] + entries[9] * rhs.entries[10] + entries[13] * rhs.entries[11],
						  entries[2] * rhs.entries[8] + entries[6] * rhs.entries[9] + entries[10] * rhs.entries[10] + entries[14] * rhs.entries[11],
						  entries[3] * rhs.entries[8] + entries[7] * rhs.entries[9] + entries[11] * rhs.entries[10] + entries[15] * rhs.entries[11],
						  entries[0] * rhs.entries[12] + entries[4] * rhs.entries[13] + entries[8] * rhs.entries[14] + entries[12] * rhs.entries[15],
						  entries[1] * rhs.entries[12] + entries[5] * rhs.entries[13] + entries[9] * rhs.entries[14] + entries[13] * rhs.entries[15],
						  entries[2] * rhs.entries[12] + entries[6] * rhs.entries[13] + entries[10] * rhs.entries[14] + entries[14] * rhs.entries[15],
						  entries[3] * rhs.entries[12] + entries[7] * rhs.entries[13] + entries[11] * rhs.entries[14] + entries[15] * rhs.entries[15]);
	}

	Matrix4<T> operator*(const T rhs) const
	{
		return Matrix4<T>(entries[0] * rhs,
						  entries[1] * rhs,
						  entries[2] * rhs,
						  entries[3] * rhs,
						  entries[4] * rhs,
						  entries[5] * rhs,
						  entries[6] * rhs,
						  entries[7] * rhs,
						  entries[8] * rhs,
						  entries[9] * rhs,
						  entries[10] * rhs,
						  entries[11] * rhs,
						  entries[12] * rhs,
						  entries[13] * rhs,
						  entries[14] * rhs,
						  entries[15] * rhs);
	}

	Matrix4<T> operator/(const T rhs) const
	{
		if (rhs == 0.0f || rhs == 1.0f)
			return (*this);

		T temp = 1 / rhs;

		return (*this) * temp;
	}

	template <class Type>
	friend Matrix4<Type> operator*(float scaleFactor, const Matrix4<Type> &rhs);

	bool operator==(const Matrix4<T> &rhs) const
	{
		for (int i = 0; i < 16; i++)
		{
			if (entries[i] != rhs.entries[i])
				return false;
		}
		return true;
	}

	bool operator!=(const Matrix4<T> &rhs) const
	{
		return !((*this) == rhs);
	}

	void operator+=(const Matrix4<T> &rhs)
	{
		(*this) = (*this) + rhs;
	}

	void operator-=(const Matrix4<T> &rhs)
	{
		(*this) = (*this) - rhs;
	}

	void operator*=(const Matrix4<T> &rhs)
	{
		(*this) = (*this) * rhs;
	}

	void operator*=(const T rhs)
	{
		(*this) = (*this) * rhs;
	}

	void operator/=(const T rhs)
	{
		(*this) = (*this) / rhs;
	}
	// unary operators

	Matrix4<T> operator-(void) const
	{
		Matrix4<T> result(*this);

		for (int i = 0; i < 16; i++)
			result.entries[i] = -result.entries[i];

		return result;
	}

	Matrix4<T> operator+(void) const { return (*this); }

	// multiply a vector by this matrix

	Vec4<T> operator*(const Vec4<T> rhs) const
	{
		// Optimise for matrices in which bottom row is (0, 0, 0, 1)
		if (entries[3] == 0.0f && entries[7] == 0.0f && entries[11] == 0.0f && entries[15] == 1.0f)
		{
			return Vec4<T>(entries[0] * rhs.x + entries[4] * rhs.y + entries[8] * rhs.z + entries[12] * rhs.w,

						   entries[1] * rhs.x + entries[5] * rhs.y + entries[9] * rhs.z + entries[13] * rhs.w,

						   entries[2] * rhs.x + entries[6] * rhs.y + entries[10] * rhs.z + entries[14] * rhs.w,

						   rhs.w);
		}

		return Vec4<T>(entries[0] * rhs.x + entries[4] * rhs.y + entries[8] * rhs.z + entries[12] * rhs.w,

					   entries[1] * rhs.x + entries[5] * rhs.y + entries[9] * rhs.z + entries[13] * rhs.w,

					   entries[2] * rhs.x + entries[6] * rhs.y + entries[10] * rhs.z + entries[14] * rhs.w,

					   entries[3] * rhs.x + entries[7] * rhs.y + entries[11] * rhs.z + entries[15] * rhs.w);
	}

	// rotate a 3d vector by rotation part
	void Rotate3v(Vec3<T> &rhs) const
	{
		rhs = GetRotated3v(rhs);
	}

	void InverseRotate3v(Vec3<T> &rhs) const
	{
		rhs = GetInverseRotated3v(rhs);
	}

	Vec3<T> GetRotated3v(const Vec3<T> &rhs) const
	{
		return Vec3<T>(entries[0] * rhs.x + entries[4] * rhs.y + entries[8] * rhs.z,
					   entries[1] * rhs.x + entries[5] * rhs.y + entries[9] * rhs.z,
					   entries[2] * rhs.x + entries[6] * rhs.y + entries[10] * rhs.z);
	}

	Vec3<T> GetInverseRotated3v(const Vec3<T> &rhs) const
	{
		// rotate by transpose:
		return Vec3<T>(entries[0] * rhs.x + entries[1] * rhs.y + entries[2] * rhs.z,
					   entries[4] * rhs.x + entries[5] * rhs.y + entries[6] * rhs.z,
					   entries[8] * rhs.x + entries[9] * rhs.y + entries[10] * rhs.z);
	}

	// translate a 3d vector by translation part
	void Translate3v(Vec3<T> &rhs) const
	{
		rhs = GetTranslated3v(rhs);
	}

	void InverseTranslate3v(Vec3<T> &rhs) const
	{
		rhs = GetInverseTranslated3v(rhs);
	}

	Vec3<T> GetTranslated3v(const Vec3<T> &rhs) const
	{
		return Vec3<T>(rhs.x + entries[12], rhs.y + entries[13], rhs.z + entries[14]);
	}

	Vec3<T> GetInverseTranslated3v(const Vec3<T> &rhs) const
	{
		return Vec3<T>(rhs.x - entries[12], rhs.y - entries[13], rhs.z - entries[14]);
	}

	// Other methods
	void Invert(void)
	{
		*this = GetInverse();
	}

	Matrix4<T> GetInverse(void) const
	{
		Matrix4<T> result = GetInverseTranspose();

		result.Transpose();

		return result;
	}

	void Transpose(void)
	{
		*this = GetTranspose();
	}

	Matrix4<T> GetTranspose(void) const
	{
		return Matrix4<T>(entries[0], entries[4], entries[8], entries[12],
						  entries[1], entries[5], entries[9], entries[13],
						  entries[2], entries[6], entries[10], entries[14],
						  entries[3], entries[7], entries[11], entries[15]);
	}

	void InvertTranspose(void)
	{
		*this = GetInverseTranspose();
	}

	Matrix4<T> GetInverseTranspose(void) const
	{
		Matrix4<T> result;

		T tmp[12]; // temporary pair storage
		T det;	   // determinant

		// calculate pairs for first 8 elements (cofactors)
		tmp[0] = entries[10] * entries[15];
		tmp[1] = entries[11] * entries[14];
		tmp[2] = entries[9] * entries[15];
		tmp[3] = entries[11] * entries[13];
		tmp[4] = entries[9] * entries[14];
		tmp[5] = entries[10] * entries[13];
		tmp[6] = entries[8] * entries[15];
		tmp[7] = entries[11] * entries[12];
		tmp[8] = entries[8] * entries[14];
		tmp[9] = entries[10] * entries[12];
		tmp[10] = entries[8] * entries[13];
		tmp[11] = entries[9] * entries[12];

		// calculate first 8 elements (cofactors)
		result.SetEntry(0, tmp[0] * entries[5] + tmp[3] * entries[6] + tmp[4] * entries[7] - tmp[1] * entries[5] - tmp[2] * entries[6] - tmp[5] * entries[7]);

		result.SetEntry(1, tmp[1] * entries[4] + tmp[6] * entries[6] + tmp[9] * entries[7] - tmp[0] * entries[4] - tmp[7] * entries[6] - tmp[8] * entries[7]);

		result.SetEntry(2, tmp[2] * entries[4] + tmp[7] * entries[5] + tmp[10] * entries[7] - tmp[3] * entries[4] - tmp[6] * entries[5] - tmp[11] * entries[7]);

		result.SetEntry(3, tmp[5] * entries[4] + tmp[8] * entries[5] + tmp[11] * entries[6] - tmp[4] * entries[4] - tmp[9] * entries[5] - tmp[10] * entries[6]);

		result.SetEntry(4, tmp[1] * entries[1] + tmp[2] * entries[2] + tmp[5] * entries[3] - tmp[0] * entries[1] - tmp[3] * entries[2] - tmp[4] * entries[3]);

		result.SetEntry(5, tmp[0] * entries[0] + tmp[7] * entries[2] + tmp[8] * entries[3] - tmp[1] * entries[0] - tmp[6] * entries[2] - tmp[9] * entries[3]);

		result.SetEntry(6, tmp[3] * entries[0] + tmp[6] * entries[1] + tmp[11] * entries[3] - tmp[2] * entries[0] - tmp[7] * entries[1] - tmp[10] * entries[3]);

		result.SetEntry(7, tmp[4] * entries[0] + tmp[9] * entries[1] + tmp[10] * entries[2] - tmp[5] * entries[0] - tmp[8] * entries[1] - tmp[11] * entries[2]);

		// calculate pairs for second 8 elements (cofactors)
		tmp[0] = entries[2] * entries[7];
		tmp[1] = entries[3] * entries[6];
		tmp[2] = entries[1] * entries[7];
		tmp[3] = entries[3] * entries[5];
		tmp[4] = entries[1] * entries[6];
		tmp[5] = entries[2] * entries[5];
		tmp[6] = entries[0] * entries[7];
		tmp[7] = entries[3] * entries[4];
		tmp[8] = entries[0] * entries[6];
		tmp[9] = entries[2] * entries[4];
		tmp[10] = entries[0] * entries[5];
		tmp[11] = entries[1] * entries[4];

		// calculate second 8 elements (cofactors)
		result.SetEntry(8, tmp[0] * entries[13] + tmp[3] * entries[14] + tmp[4] * entries[15] - tmp[1] * entries[13] - tmp[2] * entries[14] - tmp[5] * entries[15]);

		result.SetEntry(9, tmp[1] * entries[12] + tmp[6] * entries[14] + tmp[9] * entries[15] - tmp[0] * entries[12] - tmp[7] * entries[14] - tmp[8] * entries[15]);

		result.SetEntry(10, tmp[2] * entries[12] + tmp[7] * entries[13] + tmp[10] * entries[15] - tmp[3] * entries[12] - tmp[6] * entries[13] - tmp[11] * entries[15]);

		result.SetEntry(11, tmp[5] * entries[12] + tmp[8] * entries[13] + tmp[11] * entries[14] - tmp[4] * entries[12] - tmp[9] * entries[13] - tmp[10] * entries[14]);

		result.SetEntry(12, tmp[2] * entries[10] + tmp[5] * entries[11] + tmp[1] * entries[9] - tmp[4] * entries[11] - tmp[0] * entries[9] - tmp[3] * entries[10]);

		result.SetEntry(13, tmp[8] * entries[11] + tmp[0] * entries[8] + tmp[7] * entries[10] - tmp[6] * entries[10] - tmp[9] * entries[11] - tmp[1] * entries[8]);

		result.SetEntry(14, tmp[6] * entries[9] + tmp[11] * entries[11] + tmp[3] * entries[8] - tmp[10] * entries[11] - tmp[2] * entries[8] - tmp[7] * entries[9]);

		result.SetEntry(15, tmp[10] * entries[10] + tmp[4] * entries[8] + tmp[9] * entries[9] - tmp[8] * entries[9] - tmp[11] * entries[10] - tmp[5] * entries[8]);

		// calculate determinant
		det = entries[0] * result.GetEntry(0) + entries[1] * result.GetEntry(1) + entries[2] * result.GetEntry(2) + entries[3] * result.GetEntry(3);

		if (det == (T)0)
		{
			Matrix4<T> id;
			return id;
		}

		result = result / det;

		return result;
	}

	// Inverse of a rotation/translation only matrix
	// set to perform an operation on space - removes other entries

	// Invert if only composed of rotations & translations
	void AffineInvert(void)
	{
		(*this) = GetAffineInverse();
	}

	Matrix4<T> GetAffineInverse(void) const
	{
		// return the transpose of the rotation part
		// and the negative of the inverse rotated translation part
		return Matrix4<T>(entries[0],
						  entries[4],
						  entries[8],
						  (T)0,
						  entries[1],
						  entries[5],
						  entries[9],
						  (T)0,
						  entries[2],
						  entries[6],
						  entries[10],
						  (T)0,
						  -(entries[0] * entries[12] + entries[1] * entries[13] + entries[2] * entries[14]),
						  -(entries[4] * entries[12] + entries[5] * entries[13] + entries[6] * entries[14]),
						  -(entries[8] * entries[12] + entries[9] * entries[13] + entries[10] * entries[14]),
						  (T)1);
	}

	void AffineInvertTranspose(void)
	{
		(*this) = GetAffineInverseTranspose();
	}

	Matrix4<T> GetAffineInverseTranspose(void) const
	{
		// return the transpose of the rotation part
		// and the negative of the inverse rotated translation part
		// transposed
		return Matrix4<T>(entries[0],
						  entries[1],
						  entries[2],
						  -(entries[0] * entries[12] + entries[1] * entries[13] + entries[2] * entries[14]),
						  entries[4],
						  entries[5],
						  entries[6],
						  -(entries[4] * entries[12] + entries[5] * entries[13] + entries[6] * entries[14]),
						  entries[8],
						  entries[9],
						  entries[10],
						  -(entries[8] * entries[12] + entries[9] * entries[13] + entries[10] * entries[14]),
						  (T)0, (T)0, (T)0, (T)1);
	}

	void SetTranslation(const Vec3<T> &translation)
	{
		LoadIdentity();

		SetTranslationPart(translation);
	}

	void SetScale(const Vec3<T> &scaleFactor)
	{
		LoadIdentity();

		entries[0] = scaleFactor.x;
		entries[5] = scaleFactor.y;
		entries[10] = scaleFactor.z;
	}

	void SetUniformScale(const T scaleFactor)
	{
		LoadIdentity();

		entries[0] = entries[5] = entries[10] = scaleFactor;
	}

	void SetRotationAxis(const double angle, const Vec3<T> &axis)
	{
		Vec3<T> u = axis.GetNormalized();

		T sinAngle = (T)sin(M_PI * angle / 180);
		T cosAngle = (T)cos(M_PI * angle / 180);
		T oneMinusCosAngle = 1.0f - cosAngle;

		LoadIdentity();

		entries[0] = (u.x) * (u.x) + cosAngle * (1 - (u.x) * (u.x));
		entries[4] = (u.x) * (u.y) * (oneMinusCosAngle)-sinAngle * u.z;
		entries[8] = (u.x) * (u.z) * (oneMinusCosAngle) + sinAngle * u.y;

		entries[1] = (u.x) * (u.y) * (oneMinusCosAngle) + sinAngle * u.z;
		entries[5] = (u.y) * (u.y) + cosAngle * (1 - (u.y) * (u.y));
		entries[9] = (u.y) * (u.z) * (oneMinusCosAngle)-sinAngle * u.x;

		entries[2] = (u.x) * (u.z) * (oneMinusCosAngle)-sinAngle * u.y;
		entries[6] = (u.y) * (u.z) * (oneMinusCosAngle) + sinAngle * u.x;
		entries[10] = (u.z) * (u.z) + cosAngle * (1 - (u.z) * (u.z));
	}

	void SetRotationX(const double angle)
	{
		LoadIdentity();

		entries[5] = (T)cos(M_PI * angle / 180);
		entries[6] = (T)sin(M_PI * angle / 180);

		entries[9] = -entries[6];
		entries[10] = entries[5];
	}

	void SetRotationY(const double angle)
	{
		LoadIdentity();

		entries[0] = (T)cos(M_PI * angle / 180);
		entries[2] = -(T)sin(M_PI * angle / 180);

		entries[8] = -entries[2];
		entries[10] = entries[0];
	}

	void SetRotationZ(const double angle)
	{
		LoadIdentity();

		entries[0] = (T)cos(M_PI * angle / 180);
		entries[1] = (T)sin(M_PI * angle / 180);

		entries[4] = -entries[1];
		entries[5] = entries[0];
	}

	void SetRotationEuler(const double angleX, const double angleY, const double angleZ)
	{
		LoadIdentity();

		SetRotationPartEuler(angleX, angleY, angleZ);
	}

	void SetPerspective(T left, T right, T bottom,
						T top, T n, T f)
	{
		T nudge = (T)0.999; // prevent artifacts with infinite far plane

		LoadZero();

		// check for division by 0
		if (left == right || top == bottom || n == f)
			return;

		entries[0] = (2 * n) / (right - left);

		entries[5] = (2 * n) / (top - bottom);

		entries[8] = (right + left) / (right - left);
		entries[9] = (top + bottom) / (top - bottom);

		if (f != -1)
		{
			entries[10] = -(f + n) / (f - n);
		}
		else // if f==-1, use an infinite far plane
		{
			entries[10] = -nudge;
		}

		entries[11] = -1;

		if (f != -1)
		{
			entries[14] = -(2 * f * n) / (f - n);
		}
		else // if f==-1, use an infinite far plane
		{
			entries[14] = -2 * n * nudge;
		}
	}

	void SetPerspective(T fovy, T aspect, T n, T f)
	{
		T left, right, top, bottom;

		// convert fov from degrees to radians
		fovy *= (T)M_PI / 180;

		top = n * tanf(fovy / (T)2);
		bottom = -top;

		left = aspect * bottom;
		right = aspect * top;

		SetPerspective(left, right, bottom, top, n, f);
	}

	void SetOrtho(T left, T right, T bottom,
				  T top, T n, T f)
	{
		LoadIdentity();

		entries[0] = (T)2 / (right - left);

		entries[5] = (T)2 / (top - bottom);

		entries[10] = -(T)2 / (f - n);

		entries[12] = -(right + left) / (right - left);
		entries[13] = -(top + bottom) / (top - bottom);
		entries[14] = -(f + n) / (f - n);
	}

	// set parts of the matrix

	void SetTranslationPart(const Vec3<T> &translation)
	{
		entries[12] = translation.x;
		entries[13] = translation.y;
		entries[14] = translation.z;
	}

	void SetRotationPartEuler(const double angleX, const double angleY, const double angleZ)
	{
		double cr = cos(M_PI * angleX / 180);
		double sr = sin(M_PI * angleX / 180);
		double cp = cos(M_PI * angleY / 180);
		double sp = sin(M_PI * angleY / 180);
		double cy = cos(M_PI * angleZ / 180);
		double sy = sin(M_PI * angleZ / 180);

		entries[0] = (T)(cp * cy);
		entries[1] = (T)(cp * sy);
		entries[2] = (T)(-sp);

		double srsp = sr * sp;
		double crsp = cr * sp;

		entries[4] = (T)(srsp * cy - cr * sy);
		entries[5] = (T)(srsp * sy + cr * cy);
		entries[6] = (T)(sr * cp);

		entries[8] = (T)(crsp * cy + sr * sy);
		entries[9] = (T)(crsp * sy - sr * cy);
		entries[10] = (T)(cr * cp);
	}
	void SetRotationPartEuler(const Vec3<T> &rotations)
	{
		SetRotationPartEuler((double)rotations.x, (double)rotations.y, (double)rotations.z);
	}

	// cast to pointer to a (float *) for glGetFloatv etc
	operator T *() const { return (T *)this; }
	operator const T *() const { return (const T *)this; }
};

template <typename T>
Matrix4<T> operator*(float scaleFactor, const Matrix4<T> &rhs)
{
	return rhs * scaleFactor;
}
