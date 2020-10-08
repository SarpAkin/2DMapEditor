#include "Vector2.h"

#include <math.h>

#include "Vector2Int.h"

Vector2::Vector2(float x,float y)
{
    this->x = x;
    this->y = y;
}
Vector2::Vector2()
{
    //leave empty
}

float distance(Vector2 a,Vector2 b)
{
    return sqrtf((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

Vector2Int Vector2::ToVector2Int()
{
    return Vector2Int(x < 0 ? (int)x - 1 : (int)x,y < 0 ? (int)y - 1 : (int)y);
}