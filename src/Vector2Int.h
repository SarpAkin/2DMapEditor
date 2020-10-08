#ifndef Vector2Int_H
#define Vector2Int_H

#include <string>
class Vector2;
class Vector2Int
{
public:
    int x = 0;
    int y = 0;
    Vector2Int(int x,int y);
    Vector2Int();
    Vector2 ToVector2();
    inline Vector2Int operator + (Vector2Int v2)
    {
        return Vector2Int(this->x + v2.x,this->y + v2.y);
    }
    inline Vector2Int operator - (Vector2Int v2)
    {
        return Vector2Int(this->x - v2.x,this->y - v2.y);
    }
    inline Vector2Int operator * (Vector2Int v2)
    {
        return Vector2Int(this->x * v2.x,this->y * v2.y);
    }
    inline Vector2Int operator / (Vector2Int v2)
    {
        return Vector2Int(this->x / v2.x,this->y / v2.y);
    }
    inline Vector2Int operator * (int f)
    {
        return Vector2Int(this->x * f,this->y * f);
    }
    inline Vector2Int operator / (int f)
    {
        return Vector2Int(this->x / f,this->y / f);
    }
    inline void operator += (Vector2Int v2)
    {
        *this = *this + v2;
    }
    inline void operator -= (Vector2Int v2)
    {
        *this = *this - v2;
    }
    inline void operator *= (int f)
    {
        *this = *this * f;
    }
    inline void operator /= (int f)
    {
        *this = *this / f;
    }
    inline bool operator == (const Vector2Int v2)
    {
        return v2.x == this->x && v2.y == this->y;
    }
    inline std::string ToString()
    {
        return std::to_string(x) + " " + std::to_string(y);
    }
};

#endif