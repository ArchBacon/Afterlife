#pragma once

#include "Level.h"
#include "Player.h"

class CoworkersMemoryLevel : public Level
{
    Camera* camera;
    Player* player;
    Sprite* background;
    
public:
    CoworkersMemoryLevel();
    ~CoworkersMemoryLevel() override;
    
    void OnEvent(SDL_Event& event) override;
    void Tick(float deltaTime) override;
    void Render() override;
    
    Camera* GetCamera() const override { return camera; };
};
