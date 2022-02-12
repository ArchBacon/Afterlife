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
    for (const Actor* actor : actors)
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
    actors.push_back(actor);
}

void Actor::SetLocation(Vector2 inLocation)
{
    location = inLocation;
}

bool Actor::IsOverlapping(const Actor* actor) const
{
    const SDL_Rect otherCollider = actor->GetCollider();

    return otherCollider.y + otherCollider.h > collider.y
        || otherCollider.y < collider.y + collider.h
        || otherCollider.x + otherCollider.w > collider.x
        || otherCollider.x < collider.x + collider.w;
}
