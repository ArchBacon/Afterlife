#pragma once

#include "Conversation.h"
#include "Level.h"
#include "Player.h"

class AfterlifeLevel : public Level
{
    Camera* camera;
    Player* player;

    Sprite* background;
    Sprite* portal;

    Conversation* conversation;
    Interactable* levelLoader;

public:
    AfterlifeLevel();
    ~AfterlifeLevel() override;

    void OnEvent(SDL_Event& event) override;
    void Tick(float deltaTime) override;
    void Render() override;

    Camera* GetCamera() const override { return camera; }
};
