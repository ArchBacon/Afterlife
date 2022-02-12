#include "Camera.h"
#include "Application.h"
#include "Sprite.h"

Camera::Camera()
{
    location = Vector2(640, 0);
    size = Vector2(Application::Get()->GetWindow()->GetWidth(), Application::Get()->GetWindow()->GetHeight());
}

void Camera::Update(Actor* actorToFollow)
{
    // Follow actor
    if (actorToFollow != nullptr)
    {
        location.x = (actorToFollow->GetLocation().x + actorToFollow->GetSprite()->GetWidth() / 2) - Application::Get()->GetWindow()->GetWidth() / 2;
    }
}

SDL_Rect Camera::ToRect() const
{
    return {
        location.x,
        location.y,
        size.x,
        size.y,
    };
}
