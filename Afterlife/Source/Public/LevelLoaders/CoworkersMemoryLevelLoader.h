#pragma once

#include "Application.h"
#include "Interactable.h"
#include "Levels/CoworkersMemoryLevel.h"

class CoworkersMemoryLevelLoader final : public Interactable
{
public:
    CoworkersMemoryLevelLoader(Vector2 size = Vector2(256, 256))
        : Interactable(size) {}
    
    void Interact() const override
    {
        Interactable::Interact();
    
        Application::Get()->LoadLevel(new CoworkersMemoryLevel());
    }
};
