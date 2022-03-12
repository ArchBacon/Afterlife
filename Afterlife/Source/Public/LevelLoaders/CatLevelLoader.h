#pragma once

#include "Application.h"
#include "Interactable.h"
#include "Levels/CatLevel.h"

class CatLevelLoader final : public Interactable
{
public:
    CatLevelLoader(Vector2 size = Vector2(256, 256))
        : Interactable(size) {}
    
    void Interact() const override
    {
        Interactable::Interact();
    
        Application::Get()->LoadLevel(new CatLevel());
    }
};
