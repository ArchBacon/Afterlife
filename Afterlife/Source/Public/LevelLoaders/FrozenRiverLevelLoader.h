#pragma once

#include "Application.h"
#include "Levels/FrozenRiver.h"
#include "Interactable.h"

class FrozenRiverLevelLoader final : public Interactable
{
    std::string option;
    
public:
    FrozenRiverLevelLoader(std::string fromLevel, Vector2 size = Vector2(256, 256))
        : Interactable(size)
    {
        option = fromLevel;
    }
    
    void Interact() const override
    {
        Interactable::Interact();
    
        Application::Get()->LoadLevel(new FrozenRiver(option));
    }
};
