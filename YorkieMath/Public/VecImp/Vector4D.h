#pragma once
#include "../YorkieMath.h"

template <typename T> 
struct vector <T, 4>
{
    using Vec4D = vector <T, 4>;

    T x, y, z, w;
    
    vector() : x(0), y(0), z(0), w(0) {}
    vector(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

    ///////////////////////////
    /// OPERATOR OVERLOADS ///
    //////////////////////////

    Vec4D operator + (const Vec4D& rhs) const
    {
        Vec4D returnValue;
        returnValue.x = x + rhs.x;
        returnValue.y = y + rhs.y;
        returnValue.z = z + rhs.z;
        returnValue.w = w + rhs.w;
        return returnValue;
    }

    Vec4D operator - (const Vec4D& rhs) const
    {
        Vec4D returnValue;
        returnValue.x = x - rhs.x;
        returnValue.y = y - rhs.y;
        returnValue.z = z - rhs.z;
        returnValue.w = w - rhs.w;
        return returnValue;
    }

    Vec4D operator -=(const Vec4D& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        w -= other.w;
        return *this;
    }

    Vec4D operator += (const Vec4D& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;
        return *this;
    }

    Vec4D operator * (T scalar)
    {
        return Vec4D(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    Vec4D operator *= (T scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar; 
        return *this;
    }

    Vec4D operator / (T scalar)
    {
        return Vec4D(x / scalar, y / scalar, z / scalar, w / scalar);
    }

    Vec4D operator /= (T scalar)
    {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        w /= scalar;
        return *this;
    }

    bool operator == (const Vec4D& other) const
    {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    bool operator != (const Vec4D& other) const
    {
        return x != other.x && y != other.y && z != other.z && w != other.w;
    }

    friend std::ostream& operator<<(std::ostream& os, const vector<T, 4>& vec)
    {
        os << "X: " << vec.x << ", Y: " << vec.y << ", Z: " << vec.z << ", W: " << vec.w << std::endl;
        return os;
    }

    //Returns a ZERO vector
    static Vec4D Zero()
    {
        return Vec4D(0, 0, 0, 0);
    }

    //Returns a ONE vector
    static Vec4D One()
    {
        return Vec4D(1, 1, 1, 1);
    }

    //This function might go on math helper
    //Calculates the dot product of both vectors
    static float DotProduct(const Vec4D lhs, const Vec4D rhs)
    {
        return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z) + (lhs.w * rhs.w);
    }

    //This function might go on math helper
    //Calculates the angle between the two vectors
    double CalculateAngle(const Vec4D& other) const 
    {
        double dot = DotProduct(*this, other);
        double lenProduct = Length() * other.Length();
        return acos(dot / lenProduct);
    }
    //Returns the length of the vector (Pythagorean formula)
    float Length()
    {
        return sqrt(x * x + y * y + z * z + w * w);
    }

    //Normalizes the given vector
    static Vec4D Normalize(Vec4D vec)
    {
        float length = vec.Length();
        return Vec4D(vec.x / length, vec.y / length, vec.z / length, vec.w / length);
    }

    //Returns the length of the vector (Pythagorean formula)
    float Length() const
    {
        return sqrt(x * x + y * y + z * z + w * w);
    }

    T& operator[](size_t index) {
        if (index == 0) return x;
        if (index == 1) return y;
        if (index == 2) return z;
        if (index == 3) return w;

        // Handle out of bounds access as needed, or you can throw an exception.
        // Here, I'm returning the 'x' component as a default for invalid indices.
        throw std::out_of_range("Index out of bounds");
    }

    T operator[](size_t index) const {
        if (index == 0) return x;
        if (index == 1) return y;
        if (index == 2) return z;
        if (index == 3) return w;

        throw std::out_of_range("Index out of bounds");
    }
};