#pragma once

#include "Level.h"

class FriendsMemoryLevel : public Level
{
    Camera* camera;
    Actor* background;
    
public:
    FriendsMemoryLevel();
    ~FriendsMemoryLevel() override;
    
    void OnEvent(SDL_Event& event) override;
    void Tick(float deltaTime) override;
    void Render() override;
    
    Camera* GetCamera() const override { return camera; };
};
