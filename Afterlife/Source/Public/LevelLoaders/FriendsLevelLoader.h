#pragma once

#include "Application.h"
#include "Interactable.h"
#include "Levels/FriendsLevel.h"

class FriendsLevelLoader final : public Interactable
{
public:
    FriendsLevelLoader(Vector2 size = Vector2(256, 256))
        : Interactable(size) {}
    
    void Interact() const override
    {
        Interactable::Interact();
    
        Application::Get()->LoadLevel(new FriendsLevel());
    }
};
