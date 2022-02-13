#include "Interactable.h"

Interactable::Interactable(const Vector2 size)
    : Actor("Assets/transparent.png"), size(size)
{
    updateCollider = false;
}

void Interactable::Render(Camera* camera)
{
    collider = {
        location.x - camera->GetLocation().x,
        location.y - camera->GetLocation().y,
        size.x,
        size.y
    };
    
    Actor::Render(camera);
}

void Interactable::Interact() const
{
    printf("Interacted on (%d, %d)\n", location.x, location.y);
}
