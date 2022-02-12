#include "Actor.h"

#include "Application.h"
#include "Sprite.h"

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

void Actor::Render(Camera* camera)
{
    if (camera == nullptr)
    {
        sprite->Render(location);
        return;
    }

    printf("render with camera");
    sprite->Render(location - camera->GetLocation());
}

void Actor::SetLocation(Vector2 inLocation)
{
    location = inLocation;
}
