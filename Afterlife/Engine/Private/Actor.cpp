#include "Actor.h"

#include "Application.h"
#include "Sprite.h"

Actor::Actor(std::string path)
    : location(Vector2(0, 0)), collider()
{
    sprite = new Sprite(path);
}

Actor::~Actor()
{
    delete sprite;
}

void Actor::Tick(float deltaTime)
{
    for (const Actor* actor : actors.iterator)
    {
        if (IsOverlapping(actor))
        {
            printf("Currently overlapping.\n");
        }
    }
}

void Actor::OnEvent(SDL_Event& event)
{
}

void Actor::Render(Camera* camera)
{
    collider = {
        location.x - camera->GetLocation().x,
        location.y - camera->GetLocation().y,
        sprite->GetWidth(),
        sprite->GetHeight()
    };

    sprite->Render(location - camera->GetLocation());

    SDL_RenderDrawRect(Application::Get()->GetRenderer(), &collider);
}

void Actor::AddActorForOverlap(Actor* actor)
{
    actors.AddUnique(actor);
}

void Actor::SetLocation(Vector2 inLocation)
{
    location = inLocation;
}

bool Actor::IsOverlapping(const Actor* actor) const
{
    const SDL_Rect other = actor->GetCollider();

    return !(other.y + other.h <= collider.y
        || other.y >= collider.y + collider.h
        || other.x + other.w <= collider.x
        || other.x >= collider.x + collider.w);
}
