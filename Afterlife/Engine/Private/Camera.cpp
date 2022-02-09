#include "Camera.h"
#include "Application.h"

Camera::Camera()
{
    location = Vector2(0, 0);
    size = Vector2(Application::Get()->GetWindow()->GetWidth(), Application::Get()->GetWindow()->GetHeight());
}

void Camera::Update(Actor* player)
{
    // Follow actor
    if (player == nullptr)
    {
        printf("Player is not set");
        return;    
    }
    
    location.x = (player->GetScreenLocation().x) - Application::Get()->GetWindow()->GetWidth() / 2;
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
