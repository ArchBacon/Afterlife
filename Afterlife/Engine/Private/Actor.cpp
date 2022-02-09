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
    sprite->Render(GetLocation());
}

void Actor::SetLocation(Vector2 inLocation)
{
    location = inLocation;
}

Vector2 Actor::GetLocation() const
{
    if (Application::Get()->GetLevel() == nullptr)
    {
    #ifdef AE_DEBUG
            printf("Level is not set");
    #endif
    }
    const SDL_Rect camera = Application::Get()->GetLevel()->GetCamera();

    return location - Vector2(camera.x, camera.y);
}
