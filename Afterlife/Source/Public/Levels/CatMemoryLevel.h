#pragma once

#include "Level.h"
#include "Sprite.h"

class CatMemoryLevel : public Level
{
    Camera* camera;
    Actor* background;
    
public:
    CatMemoryLevel();
    ~CatMemoryLevel() override;
    
    void OnEvent(SDL_Event& event) override;
    void Tick(float deltaTime) override;
    void Render() override;
    
    Camera* GetCamera() const override { return camera; };
};
