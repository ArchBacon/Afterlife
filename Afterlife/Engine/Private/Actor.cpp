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
    /** Update location of collision box */
    if (updateCollider)
    {
        collider = {
            camera == nullptr ? location.x : location.x - camera->GetLocation().x,
            camera == nullptr ? location.y : location.y - camera->GetLocation().y,
            sprite->GetWidth(),
            sprite->GetHeight()
        };
    }

    sprite->Render(
        camera == nullptr ? location : location - camera->GetLocation(),
        nullptr,
        flip
    );

#ifdef _DEBUG
    SDL_RenderDrawRect(Application::Get()->GetRenderer(), &collider);
#endif
}

/** Flip actor sprite horizontally */
void Actor::Flip()
{
    flip = flip == SDL_FLIP_NONE
    ? SDL_FLIP_HORIZONTAL
    : SDL_FLIP_NONE;
}

void Actor::SetLocation(Vector2 inLocation)
{
    location = inLocation;
}
