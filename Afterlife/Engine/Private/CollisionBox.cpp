#include "CollisionBox.h"

#include <SDL_render.h>

#include "Application.h"

CollisionBox::CollisionBox(Vector2 size)
    : size(size)
{
    collider = {0, 0, size.x, size.y};
}

void CollisionBox::Render(Camera* camera)
{
    if (camera == nullptr)
    {
        SDL_RenderDrawRect(Application::Get()->GetRenderer(), &collider);
        return;
    }

    /** render collision box with correction based on camera location */
    const SDL_Rect collisionRect = collider;
    collider.x -= camera->GetLocation().x;
    collider.y -= camera->GetLocation().y;

    SDL_RenderDrawRect(Application::Get()->GetRenderer(), &collisionRect);
}

/**
 * Check if the player's hitbox and the hitbox of the interactble are overlapping
 * @see https://lazyfoo.net/tutorials/SDL/27_collision_detection/index.php
 */
bool CollisionBox::IsOverlapping(const CollisionBox* other) const
{
    const SDL_Rect otherCollider = other->ToRect();
    
    return otherCollider.y + otherCollider.h > collider.y
    || otherCollider.y < collider.y + collider.h
    || otherCollider.x + otherCollider.w > collider.x
    || otherCollider.x < collider.x + collider.w;
}

SDL_Rect CollisionBox::ToRect() const
{
    return collider;
}
