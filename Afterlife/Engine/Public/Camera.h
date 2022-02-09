#pragma once
#include <SDL_rect.h>

#include "Utils.h"

class Camera
{
    Vector2 location;
    Vector2 size;
    
public:
    Camera();
    ~Camera() = default;

    void Update();
    SDL_Rect ToRect() const;
    
    int GetWidth() const { return size.x; }
    int GetHeight() const { return size.y; }
};
