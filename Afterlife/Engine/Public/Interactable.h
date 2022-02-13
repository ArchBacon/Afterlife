#pragma once

#include "Actor.h"

class Interactable abstract : public Actor
{
    Vector2 size;
    
public:
    Interactable(const Vector2 size = Vector2(256, 256));

    void Render(Camera* camera) override;
    virtual void Interact() const;
};
