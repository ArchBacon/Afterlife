#pragma once

#include "Level.h"
#include "Player.h"

class Conversation;

class CoworkersMemoryLevel : public Level
{
    Camera* camera;
    Player* player;
    
    Sprite* background;
    Sprite* charon;
    Sprite* coworkers;

    Conversation* conversation;
    Interactable* levelLoader;
    
public:
    CoworkersMemoryLevel();
    ~CoworkersMemoryLevel() override;
    
    void OnEvent(SDL_Event& event) override;
    void Tick(float deltaTime) override;
    void Render() override;
    
    Camera* GetCamera() const override { return camera; };
};
