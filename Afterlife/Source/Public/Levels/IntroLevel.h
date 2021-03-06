#pragma once

#include "Level.h"

class IntroLevel : public Level
{
    Camera* camera;
    Sprite* background;
    
public:
    IntroLevel();
    ~IntroLevel() override;
    
    void OnEvent(SDL_Event& event) override;
    void Tick(float deltaTime) override;
    void Render() override;
    
    Camera* GetCamera() const override { return camera; };
};
