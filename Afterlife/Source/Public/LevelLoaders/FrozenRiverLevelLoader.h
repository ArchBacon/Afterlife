#pragma once

#include "Application.h"
#include "Levels/FrozenRiver.h"
#include "Interactable.h"

class FrozenRiverLevelLoader final : public Interactable
{
public:
    FrozenRiverLevelLoader(Vector2 size = Vector2(256, 256))
        : Interactable(size) {}
    
    void Interact() const override
    {
        Interactable::Interact();
    
        Application::Get()->LoadLevel(new FrozenRiver());
    }
};
