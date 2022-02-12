#include "CollisionBox.h"

#include <SDL_render.h>

#include "Application.h"

CollisionBox::CollisionBox(Vector2 size, Vector2 location)
    : size(), location()
{
    collider = {location.x, location.y, size.x, size.y};
}

void CollisionBox::Render(Camera* camera)
{
    if (camera == nullptr)
    {
        SDL_RenderDrawRect(Application::Get()->GetRenderer(), &collider);
        return;
    }

    const SDL_Rect collisionRect = collider;
    collider.x = location.x - camera->GetLocation().x;
    collider.y = location.y - camera->GetLocation().y;

    SDL_RenderDrawRect(Application::Get()->GetRenderer(), &collisionRect);
}

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
