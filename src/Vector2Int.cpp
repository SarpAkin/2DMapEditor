#include "Vector2Int.h"

#include "Vector2.h"


Vector2Int::Vector2Int(int x,int y)
{
    this->x = x;
    this->y = y;
}

Vector2Int::Vector2Int()
{
    //leave empty
}

Vector2 Vector2Int::ToVector2()
{
    return Vector2(x,y);
}