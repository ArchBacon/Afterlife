#pragma once
#include <SDL_rect.h>

#include "Camera.h"
#include "Utils.h"

class CollisionBox
{
    SDL_Rect collider;
    Vector2 size;
    
public:
    CollisionBox(Vector2 size);

    void Render(Camera* camera = nullptr);
    bool IsOverlapping(const CollisionBox* other) const;
    SDL_Rect ToRect() const;
};
