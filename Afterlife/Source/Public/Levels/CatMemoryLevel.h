#pragma once

#include "Level.h"

class Interactable;
class Conversation;
class Player;

class CatMemoryLevel : public Level
{
    Camera* camera;
    Player* player;

    Sprite* background;
    Sprite* charon;
    Sprite* cat;

    Conversation* conversation;
    Interactable* levelLoader;
    
public:
    CatMemoryLevel();
    ~CatMemoryLevel() override;
    
    void OnEvent(SDL_Event& event) override;
    void Tick(float deltaTime) override;
    void Render() override;
    
    Camera* GetCamera() const override { return camera; };
};
