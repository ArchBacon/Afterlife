#pragma once
#include <SDL_rect.h>

#include "Camera.h"
#include "Utils.h"

class CollisionBox
{
    Vector2 size;
    Vector2 location;

    SDL_Rect collider;
    
public:
    CollisionBox(Vector2 size, Vector2 location);

    void Render(Camera* camera);
    bool IsOverlapping(const CollisionBox* other) const;
    SDL_Rect ToRect() const;
};
