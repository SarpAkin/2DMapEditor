#ifndef Vector2_H
#define Vector2_H

#include <string>

class Vector2;
class Vector2Int;

float distance(Vector2 a,Vector2 b);

class Vector2
{
public:
    float x = 0;
    float y = 0;
    Vector2(float x,float y);
    Vector2();
    Vector2Int ToVector2Int();
    inline Vector2 operator + (const Vector2 v2)
    {
        return Vector2(this->x + v2.x,this->y + v2.y);
    }
    inline Vector2 operator - (const Vector2 v2)
    {
        return Vector2(this->x - v2.x,this->y - v2.y);
    }
    inline Vector2 operator * (const Vector2 v2)
    {
        return Vector2(this->x * v2.x,this->y * v2.y);
    }
    inline Vector2 operator / (const Vector2 v2)
    {
        return Vector2(this->x / v2.x,this->y / v2.y);
    }
    inline Vector2 operator * (float f)
    {
        return Vector2(this->x * f,this->y * f);
    }
    inline Vector2 operator / (float f)
    {
        return Vector2(this->x / f,this->y / f);
    }
    inline void operator += (const Vector2 v2)
    {
        *this = *this + v2;
    }
    inline void operator -= (const Vector2 v2)
    {
        *this = *this - v2;
    }
    inline void operator *= (float f)
    {
        *this = *this * f;
    }
    inline void operator /= (float f)
    {
        *this = *this / f;
    }
    inline bool operator == (const Vector2 v2)
    {
        return v2.x == this->x && v2.y == this->y;
    }
    inline Vector2 normalized()
    {
        return *this / distance(*this,Vector2(0,0));
    }
    inline std::string ToString()
    {
        return std::to_string(x) + " " + std::to_string(y);
    }
};

struct AABB
{
    Vector2 cord;
    Vector2 size;
    AABB(Vector2 c,Vector2 s)
    {
        cord = c;
        size = s;
    }
    AABB()
    {
        
    }
    inline Vector2 GetCenterPoint()
    {
        return cord + size / 2;
    }
    void FixBoundry()
    {
        if(size.x < 0)
        {
            cord.x += size.x;
            size.x = -size.x; 
        }
        if(size.y < 0)
        {
            cord.y += size.y;
            size.y = -size.y; 
        }
    }
};
#endif