#include "Actor.h"

#include "Application.h"
#include "Sprite.h"

Actor::Actor(std::string path)
    : location(Vector2(0, 0)), collider(), flip(SDL_FLIP_NONE)
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
    if (updateCollider)
    {
        collider = {
            location.x - camera->GetLocation().x,
            location.y - camera->GetLocation().y,
            sprite->GetWidth(),
            sprite->GetHeight()
        };
    }

    sprite->Render(location - camera->GetLocation(), nullptr, flip);

#ifdef AE_DEBUG
    SDL_RenderDrawRect(Application::Get()->GetRenderer(), &collider);
#endif
}

void Actor::SetLocation(Vector2 inLocation)
{
    location = inLocation;
}

