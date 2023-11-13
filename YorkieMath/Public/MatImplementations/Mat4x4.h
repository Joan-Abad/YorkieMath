#pragma once

#include "../YorkieMath.h"
#include "VecImplementations/Vector4D.h"

template <typename T>
struct matrix <T, 4, 4>
{
	using Vec4 = vector<T, 4>;
	using Mat4x4 = matrix <T, 4, 4>;
public:
	
	matrix() 
	{
			rows[0].x = 0; rows[0].y = 0; rows[0].z = 0, rows[0].w = 0;
			rows[1].x = 0; rows[1].y = 0; rows[1].z = 0, rows[1].w = 0;
			rows[2].x = 0; rows[2].y = 0; rows[2].z = 0, rows[2].w = 0;
			rows[3].x = 0; rows[3].y = 0; rows[3].z = 0, rows[3].w = 0;
	}

	matrix(
		const Vec4& v1,
		const Vec4& v2,
		const Vec4& v3,
		const Vec4& v4
		)
	{
		rows[0] = v1;
		rows[1] = v2;
		rows[2] = v3;
		rows[3] = v4;
	}

	matrix(
		T& x0, T& y0, T& z0, T& w0,
		T& x1, T& y1, T& z1, T& w1,
		T& x2, T& y2, T& z2, T& w2,
		T& x3, T& y3, T& z3, T& w3)
	{
		rows[0].x = x0;
		rows[1].x = x1;
		rows[2].x = x2;
		rows[3].x = x3;

		rows[0].y = y0;
		rows[1].y = y1;
		rows[2].y = y2;
		rows[3].y = y3;

		rows[0].z = z0;
		rows[1].z = z1;
		rows[2].z = z2;
		rows[3].z = z3;

		rows[0].w = w0;
		rows[1].w = w1;
		rows[2].w = w2;
		rows[3].w = w3;
	}

	// Constructor from an initializer list
	matrix(std::initializer_list<std::initializer_list<T>> list) {
		if (list.size() != 4) {
			// Handle an incorrect number of rows as needed
			// You may want to throw an exception or handle it differently
		}
		else {
			int i = 0;
			for (const auto& row : list) {
				if (row.size() != 4) {
					// Handle an incorrect number of elements in a row as needed
					// You may want to throw an exception or handle it differently
				}
				else {
					int j = 0;
					for (const T& element : row) {
						rows[i][j] = element;
						++j;
					}
				}
				++i;
			}
		}
	}

	Mat4x4 operator + (const Mat4x4& other) const
	{
		return Mat4x4
		(
			Vec4(rows[0].x + other.rows[0].x, rows[0].y + other.rows[0].y, rows[0].z + other.rows[0].z, rows[0].w + other.rows[0].w),
			Vec4(rows[1].x + other.rows[1].x, rows[1].y + other.rows[1].y, rows[1].z + other.rows[1].z, rows[1].w + other.rows[1].w),
			Vec4(rows[2].x + other.rows[2].x, rows[2].y + other.rows[2].y, rows[2].z + other.rows[2].z, rows[2].w + other.rows[2].w),
			Vec4(rows[3].x + other.rows[3].x, rows[3].y + other.rows[3].y, rows[3].z + other.rows[3].z, rows[3].w + other.rows[3].w)
		);
	}

	Mat4x4 operator - (const Mat4x4& other) const
	{
		return Mat4x4
		(
			Vec4(rows[0].x - other.rows[0].x, rows[0].y - other.rows[0].y, rows[0].z - other.rows[0].z, rows[0].w - other.rows[0].w),
			Vec4(rows[1].x - other.rows[1].x, rows[1].y - other.rows[1].y, rows[1].z - other.rows[1].z, rows[1].w - other.rows[1].w),
			Vec4(rows[2].x - other.rows[2].x, rows[2].y - other.rows[2].y, rows[2].z - other.rows[2].z, rows[2].w - other.rows[2].w),
			Vec4(rows[3].x - other.rows[3].x, rows[3].y - other.rows[3].y, rows[3].z - other.rows[3].z, rows[3].w - other.rows[3].w)
		);
	}

	Mat4x4 operator += (const Mat4x4& other) 
	{
		rows[0].x += other.rows[0].x; rows[0].y += other.rows[0].y; rows[0].z += other.rows[0].z; rows[0].w += other.rows[0].w;
		rows[1].x += other.rows[1].x; rows[1].y += other.rows[1].y; rows[1].z += other.rows[1].z; rows[1].w += other.rows[1].w;
		rows[2].x += other.rows[2].x; rows[2].y += other.rows[2].y; rows[2].z += other.rows[2].z; rows[2].w += other.rows[2].w;
		rows[3].x += other.rows[3].x; rows[3].y += other.rows[3].y; rows[3].z += other.rows[3].z; rows[3].w += other.rows[3].w;
		
		return *this;
	}

	Mat4x4 operator -= (const Mat4x4& other) 
	{
		rows[0].x -= other.rows[0].x; rows[0].y -= other.rows[0].y; rows[0].z -= other.rows[0].z; rows[0].w -= other.rows[0].w;
		rows[1].x -= other.rows[1].x; rows[1].y -= other.rows[1].y; rows[1].z -= other.rows[1].z; rows[1].w -= other.rows[1].w;
		rows[2].x -= other.rows[2].x; rows[2].y -= other.rows[2].y; rows[2].z -= other.rows[2].z; rows[2].w -= other.rows[2].w;
		rows[3].x -= other.rows[3].x; rows[3].y -= other.rows[3].y; rows[3].z -= other.rows[3].z; rows[3].w -= other.rows[3].w;

		return *this;
	}

	Mat4x4 operator / (const T scalar) const
	{
		return Mat4x4(
		Vec4(rows[0].x / scalar, rows[0].y / scalar, rows[0].z / scalar, rows[0].w / scalar),
		Vec4(rows[1].x / scalar, rows[1].y / scalar, rows[1].z / scalar, rows[1].w / scalar),
		Vec4(rows[2].x / scalar, rows[2].y / scalar, rows[2].z / scalar, rows[2].w / scalar),
		Vec4(rows[3].x / scalar, rows[3].y / scalar, rows[3].z / scalar, rows[3].w / scalar)
		);
	}

	Mat4x4 operator /= (const T scalar) 
	{
		rows[0].x /= scalar; rows[0].y /= scalar; rows[0].z /= scalar; rows[0].w /= scalar;
		rows[1].x /= scalar; rows[1].y /= scalar; rows[1].z /= scalar; rows[1].w /= scalar;
		rows[2].x /= scalar; rows[2].y /= scalar; rows[2].z /= scalar; rows[2].w /= scalar;
		rows[3].x /= scalar; rows[3].y /= scalar; rows[3].z /= scalar; rows[3].w /= scalar;
		return *this;
	}

	Mat4x4 operator * (const T scalar) const
	{
		return Mat4x4(
		Vec4(rows[0].x * scalar, rows[0].y * scalar, rows[0].z * scalar, rows[0].w * scalar),
		Vec4(rows[1].x * scalar, rows[1].y * scalar, rows[1].z * scalar, rows[1].w * scalar),
		Vec4(rows[2].x * scalar, rows[2].y * scalar, rows[2].z * scalar, rows[2].w * scalar),
		Vec4(rows[3].x * scalar, rows[3].y * scalar, rows[3].z * scalar, rows[3].w * scalar)
		);
	}

	Mat4x4 operator *= (const T scalar) 
	{
		rows[0].x *= scalar; rows[0].y *= scalar; rows[0].z *= scalar; rows[0].w *= scalar;
		rows[1].x *= scalar; rows[1].y *= scalar; rows[1].z *= scalar; rows[1].w *= scalar;
		rows[2].x *= scalar; rows[2].y *= scalar; rows[2].z *= scalar; rows[2].w *= scalar;
		rows[3].x *= scalar; rows[3].y *= scalar; rows[3].z *= scalar; rows[3].w *= scalar;
		return *this;
	}

	
	Mat4x4 operator*(const Mat4x4& other) {
		Mat4x4 result;

		for (int row = 0; row < 4; ++row) {
			for (int col = 0; col < 4; ++col) {
				T sum = T(0);
				for (int i = 0; i < 4; ++i) {
					T a = rows[row][i];
					T b = other.rows[i][col];
					sum += a * b;
				}
				result.rows[row][col] = sum;
			}
		}

		return result;
	}

	static Mat4x4 IdentityMatrix()
	{
		return Mat4x4(
			Vec4(1.0f, 0.0f, 0.0f, 0.0f),
			Vec4(0.0f, 1.0f, 0.0f, 0.0f),
			Vec4(0.0f, 0.0f, 1.0f, 0.0f),
			Vec4(0.0f, 0.0f, 0.0f, 1.0f));
	}


private:
	Vec4 rows[4];
};
