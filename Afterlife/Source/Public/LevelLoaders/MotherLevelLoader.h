#pragma once

#include "Application.h"
#include "Interactable.h"
#include "Levels/MotherLevel.h"

class MotherLevelLoader final : public Interactable
{
public:
    MotherLevelLoader(Vector2 size = Vector2(256, 256))
        : Interactable(size) {}
    
    void Interact() const override
    {
        Interactable::Interact();
    
        Application::Get()->LoadLevel(new MotherLevel());
    }
};
