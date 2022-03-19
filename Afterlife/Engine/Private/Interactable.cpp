#include "Interactable.h"

Interactable::Interactable(const Vector2 size)
    : Actor("Assets/Common/Transparent.png"), size(size)
{
    updateCollider = false;
}

void Interactable::Render(Camera* camera)
{
    /** Update collision box */
    collider = {
        camera == nullptr ? location.x : location.x - camera->GetLocation().x,
        camera == nullptr ? location.y : location.y - camera->GetLocation().y,
        size.x,
        size.y
    };
    
    Actor::Render(camera);
}

void Interactable::Interact() const
{
}
