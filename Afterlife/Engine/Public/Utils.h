#pragma once
#include <SDL_timer.h>

struct Vector2
{
    int x;
    int y;

    Vector2 operator -(const Vector2& other) const
    {
        return Vector2(x - other.x, y - other.y);
    }
};
