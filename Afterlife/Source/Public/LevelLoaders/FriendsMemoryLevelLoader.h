#pragma once

#include "Application.h"
#include "Interactable.h"
#include "Levels/FriendsMemoryLevel.h"

class FriendsMemoryLevelLoader final : public Interactable
{
public:
    FriendsMemoryLevelLoader(Vector2 size = Vector2(256, 256))
        : Interactable(size) {}
    
    void Interact() const override
    {
        Interactable::Interact();
    
        Application::Get()->LoadLevel(new FriendsMemoryLevel());
    }
};
