#pragma once

#include <SDL_rect.h>

#include "Utils.h"

class Actor;

class Camera
{
    Vector2 location;
    Vector2 size;

public:
    Camera();
    ~Camera() = default;

    void Update(Actor* actorToFollow = nullptr);
    SDL_Rect ToRect() const;

    int GetWidth() const { return size.x; }
    int GetHeight() const { return size.y; }
    Vector2 GetLocation() const { return location; }
};
