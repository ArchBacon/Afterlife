#pragma once

#include "Level.h"

class Interactable;
class Conversation;
class Player;

class MotherLevel : public Level
{
    Camera* camera;
    Player* player;

    Sprite* background;
    Sprite* furniture;

    Conversation* conversation;
    Interactable* levelLoader;
    
public:
    MotherLevel();
    ~MotherLevel() override;
    
    void OnEvent(SDL_Event& event) override;
    void Tick(float deltaTime) override;
    void Render() override;
    
    Camera* GetCamera() const override { return camera; };
};
