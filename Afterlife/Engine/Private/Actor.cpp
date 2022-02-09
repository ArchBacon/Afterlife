#include "Actor.h"

#include "Application.h"

Actor::Actor(std::string path)
    : location(Vector2(0, 0))
{
    sprite = new Sprite(path);
}

Actor::~Actor()
{
    delete sprite;
}

void Actor::Tick(float deltaTime)
{
}

void Actor::OnEvent(SDL_Event& event)
{
}

void Actor::Render()
{
    sprite->Render(GetScreenLocation());
}

void Actor::SetLocation(Vector2 inLocation)
{
    location = inLocation;
}

Vector2 Actor::GetWorldLocation() const
{
    const Camera* camera = Application::Get()->GetLevel()->GetCamera();

    return Vector2(location.x - camera->GetWidth(), location.y - camera->GetHeight());
}
