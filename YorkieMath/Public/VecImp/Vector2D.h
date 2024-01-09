#pragma once
#include "../YorkieMath.h"
#include <iostream>

template <typename T> 
struct vector <T, 2>
{
    using Vec2D = vector <T, 2>;

    T x, y;

    vector() : x(0), y(0) {};
    vector(T x, T y) : x(x), y(y) {}

    ///////////////////////////
    /// OPERATOR OVERLOADS ///
    //////////////////////////

    Vec2D operator + (const Vec2D& rhs) const
    {
        Vec2D returnValue;
        returnValue.x = x + rhs.x;
        returnValue.y = y + rhs.y;
        return returnValue;
    }

    Vec2D operator - (const Vec2D& rhs) const
    {
        Vec2D returnValue;
        returnValue.x = x - rhs.x;
        returnValue.y = y - rhs.y;
        return returnValue;
    }

    Vec2D operator -=(const Vec2D& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vec2D operator += (const Vec2D& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2D operator* (T scalar)
    {
        return Vec2D(x * scalar, y * scalar);
    }

    Vec2D operator*= (T scalar)
    {
        x *= scalar; 
        y *= scalar;
        return *this; 
    }

    Vec2D operator / (T scalar)
    {
        return Vec2D(x / scalar, y / scalar);
    }

    Vec2D operator/= (T scalar)
    {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    bool operator == (const Vec2D& other) const 
    {
        return x == other.x && y == other.y; 
    }

    bool operator != (const Vec2D& other) const 
    {
        return x != other.x && y != other.y;
    }

    friend std::ostream& operator<<(std::ostream& os, const vector<T, 2>& vec)
    {
        os << "X: " << vec.x << ", Y: " << vec.y << std::endl;
        return os;
    }

    //Returns a 2D Zero Vector
    static Vec2D Zero()
    {
        return Vec2D(0, 0);
    }

    //Returns a 2D One Vector
    static Vec2D One()
    {
        return Vec2D(1, 1);
    }

    //This function might go on math helper
    //Calculates the dot product of both vectors
    static float DotProduct(const Vec2D lhs, const Vec2D rhs)
    {
        return (lhs.x * rhs.x) + (lhs.y * rhs.y);
    }
    //This function might go on math helper
    //Calculates the angle between the two vectors
    double CalculateAngle(const Vec2D& other) const
    {
        double dot = DotProduct(*this, other);
        double lenProduct = Length() * other.Length();
        return acos(dot / lenProduct);
    }

    //Normalizes the given vector (length of 1)
    static Vec2D Normalize(Vec2D vec)
    {
        float length = vec.Length();
        return Vec2D(vec.x / length, vec.y / length);   
    }

    //Returns the length of the vector (Pythagorean formula)
    float Length() const
    {
        return sqrt(x * x + y * y);
    }
};