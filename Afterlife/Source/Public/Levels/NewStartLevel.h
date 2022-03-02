#pragma once

#include "Level.h"

class Player;
class Conversation;

class NewStartLevel : public Level
{
    Camera* camera;
    Player* player;

    Sprite* background;
    Conversation* conversation;
    
public:
    NewStartLevel();
    ~NewStartLevel() override;
    
    void Render() override;
    void OnEvent(SDL_Event& event) override;
    void Tick(float deltaTime) override;
    
    Camera* GetCamera() const override { return camera; };
};
