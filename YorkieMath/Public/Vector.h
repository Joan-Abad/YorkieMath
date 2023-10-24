#pragma once



template<typename T>
struct Vector2D
{

	Vector2D(T x, T y) : x(x), y(y) {};

	Vector2D operator + (const Vector2D& lhs, const Vector2D& rhs)
	{
		Vector2D returnValue; 
		returnValue.x = lhs.x + rhs.x;
		returnValue.x = lhs.y + rhs.y;
		return returnValue; 
	}

	Vector2D operator - (const Vector2D& lhs, const Vector2D& rhs)
	{
		Vector2D returnValue;
		returnValue.x = lhs.x - rhs.x;
		returnValue.x = lhs.y - rhs.y;
		return returnValue;
	}

	Vector2D operator -= (const Vector2D& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vector2D operator += (const Vector2D& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	T x;
	T y;
	
};

