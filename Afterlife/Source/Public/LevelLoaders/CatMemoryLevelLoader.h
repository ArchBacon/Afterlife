#pragma once

#include "Application.h"
#include "Interactable.h"
#include "Levels/CatMemoryLevel.h"

class CatMemoryLevelLoader final : public Interactable
{
public:
    CatMemoryLevelLoader(Vector2 size = Vector2(256, 256))
        : Interactable(size) {}
    
    void Interact() const override
    {
        Interactable::Interact();
    
        Application::Get()->LoadLevel(new CatMemoryLevel());
    }
};
