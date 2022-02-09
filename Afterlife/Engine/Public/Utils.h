#pragma once

struct Vector2
{
    int x = 0;
    int y = 0;

    Vector2 operator -(const Vector2& other) const
    {
        return Vector2(x - other.x, y - other.y);
    }
};
