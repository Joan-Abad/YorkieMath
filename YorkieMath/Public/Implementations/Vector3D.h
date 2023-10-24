#pragma once
#include "../YorkieMath.h"

template <typename T> 
struct vector <T, 3>
{
    using Vec3D = vector <T, 3>;

    T x, y, z;
    
    vector() : x(0), y(0), z(0) {}
    vector(T x, T y, T z) : x(x), y(y), z(z) {}

    ///////////////////////////
    /// OPERATOR OVERLOADS ///
    //////////////////////////

    Vec3D operator + (const Vec3D& rhs) const
    {
        Vec3D returnValue;
        returnValue.x = x + rhs.x;
        returnValue.y = y + rhs.y;
        returnValue.z = z + rhs.z;
        return returnValue;
    }

    Vec3D operator - (const Vec3D& rhs) const
    {
        Vec3D returnValue;
        returnValue.x = x - rhs.x;
        returnValue.y = y - rhs.y;
        returnValue.z = z - rhs.z;
        return returnValue;
    }

    Vec3D operator -=(const Vec3D& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    Vec3D operator += (const Vec3D& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Vec3D operator * (T scalar)
    {
        return Vec3D(x * scalar, y * scalar, z * scalar);
    }

    Vec3D operator *= (T scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    Vec3D operator / (T scalar)
    {
        return Vec3D(x / scalar, y / scalar, z / scalar);
    }

    Vec3D operator /= (T scalar)
    {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

    bool operator == (const Vec3D& other) const
    {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator != (const Vec3D& other) const
    {
        return x != other.x && y != other.y && z != other.z;
    }

    friend std::ostream& operator<<(std::ostream& os, const vector<T, 3>& vec)
    {
        os << "X: " << vec.x << ", Y: " << vec.y << ", Z: " << vec.z << std::endl;
        return os;
    }

    //Returns a ZERO vector
    static Vec3D Zero()
    {
        return Vec3D(1, 1, 1);
    }

    //Returns a ONE vector
    static Vec3D One()
    {
        return Vec3D(1, 1, 1);
    }

    //This function might go on math helper
    //Calculates the dot product of both vectors
    static float DotProduct(const Vec3D lhs, const Vec3D rhs)
    {
        return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
    }

    //Calculates the corss product of two vectors
    Vec3D CrossProduct(const Vec3D& other) const {
        double resultX = (y * other.z) - (z * other.y);
        double resultY = (z * other.x) - (x * other.z);
        double resultZ = (x * other.y) - (y * other.x);

        return Vec3D(resultX, resultY, resultZ);
    }

    //This function might go on math helper
    //Calculates the angle between the two vectors
    double CalculateAngle(const Vec3D& other) const 
    {
        double dot = DotProduct(*this, other);
        double lenProduct = Length() * other.Length();
        return acos(dot / lenProduct);
    }
    //Returns the length of the vector (Pythagorean formula)
    float Length()
    {
        return sqrt(x * x + y * y + z * z);
    }

    //Normalizes the given vector
    static Vec3D Normalize(Vec3D vec)
    {
        float length = vec.Length();
        return Vec3D(vec.x / length, vec.y / length, vec.z / length);
    }

    //Returns the length of the vector (Pythagorean formula)
    float Length() const
    {
        return sqrt(x * x + y * y + z * z);
    }
};