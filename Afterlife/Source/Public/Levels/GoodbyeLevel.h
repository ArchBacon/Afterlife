#pragma once

#include "Level.h"

class Player;
class Conversation;

class GoodbyeLevel : public Level
{
    Camera* camera;
    Player* player;

    Sprite* background;
    Conversation* conversation;
    
public:
    GoodbyeLevel();
    ~GoodbyeLevel() override;
    
    void Render() override;
    void OnEvent(SDL_Event& event) override;
    void Tick(float deltaTime) override;
    
    Camera* GetCamera() const override { return camera; };
};
