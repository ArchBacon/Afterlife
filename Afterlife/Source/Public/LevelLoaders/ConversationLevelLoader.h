#pragma once

#include "Application.h"
#include "Interactable.h"
#include "Levels/ConversationLevel.h"

class ConversationLevelLoader final : public Interactable
{
public:
    ConversationLevelLoader(Vector2 size = Vector2(256, 256))
        : Interactable(size) {}
    
    void Interact() const override
    {
        Interactable::Interact();
    
        Application::Get()->LoadLevel(new ConversationLevel());
    }
};
