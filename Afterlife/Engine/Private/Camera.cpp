#include "Camera.h"

#include "Application.h"

Camera::Camera()
{
    location = Vector2(0, 0);
    size = Vector2(Application::Get()->GetWindow()->GetWidth(), Application::Get()->GetWindow()->GetHeight());
}

void Camera::Update()
{
    // Follow actor
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
