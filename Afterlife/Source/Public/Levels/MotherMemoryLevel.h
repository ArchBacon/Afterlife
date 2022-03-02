#pragma once

#include "Level.h"

class Interactable;
class Conversation;
class Player;

class MotherMemoryLevel : public Level
{
    Camera* camera;
    Player* player;

    Sprite* background;
    Sprite* furniture;
    Sprite* charon;
    Sprite* mother;

    Conversation* conversation;
    Interactable* levelLoader;
    
public:
    MotherMemoryLevel();
    ~MotherMemoryLevel() override;
    
    void OnEvent(SDL_Event& event) override;
    void Tick(float deltaTime) override;
    void Render() override;
    
    Camera* GetCamera() const override { return camera; };
};
