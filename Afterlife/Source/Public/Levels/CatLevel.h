#pragma once

#include "Level.h"

class Interactable;
class Conversation;
class Player;

class CatLevel : public Level
{
    Camera* camera;
    Player* player;

    Sprite* background;

    Conversation* conversation;
    Interactable* levelLoader;
    
public:
    CatLevel();
    ~CatLevel() override;
    
    void OnEvent(SDL_Event& event) override;
    void Tick(float deltaTime) override;
    void Render() override;
    
    Camera* GetCamera() const override { return camera; };
};
