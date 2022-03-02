#pragma once

#include "Application.h"
#include "Interactable.h"
#include "Levels/AfterlifeLevel.h"

class AfterlifeLevelLoader final : public Interactable
{
public:
    AfterlifeLevelLoader(Vector2 size = Vector2(256, 256))
        : Interactable(size) {}
    
    void Interact() const override
    {
        Interactable::Interact();
    
        Application::Get()->LoadLevel(new AfterlifeLevel());
    }
};
