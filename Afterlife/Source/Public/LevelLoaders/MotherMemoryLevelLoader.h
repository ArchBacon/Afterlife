#pragma once

#include "Application.h"
#include "Interactable.h"
#include "Levels/MotherLevel.h"

class MotherMemoryLevelLoader final : public Interactable
{
public:
    MotherMemoryLevelLoader(Vector2 size = Vector2(256, 256))
        : Interactable(size) {}
    
    void Interact() const override
    {
        Interactable::Interact();
    
        Application::Get()->LoadLevel(new MotherLevel());
    }
};
