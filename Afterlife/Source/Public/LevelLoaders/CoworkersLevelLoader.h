#pragma once

#include "Application.h"
#include "Interactable.h"
#include "Levels/CoworkersLevel.h"

class CoworkersLevelLoader final : public Interactable
{
public:
    CoworkersLevelLoader(Vector2 size = Vector2(256, 256))
        : Interactable(size) {}
    
    void Interact() const override
    {
        Interactable::Interact();
    
        Application::Get()->LoadLevel(new CoworkersLevel());
    }
};
