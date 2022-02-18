#pragma once

#include "Interactable.h"

class Conversation : public Interactable
{
public:
    void Tick(float deltaTime) override;
    void OnEvent(SDL_Event& event) override;
    void Render(Camera* camera) override;
    void Interact() const override;
    ~Conversation() override;
};
