#pragma once

#include "Level.h"

class EndingLevel : public Level
{
    Camera* camera;
    Sprite* background;
    
public:
    EndingLevel();
    ~EndingLevel() override;
    
    void OnEvent(SDL_Event& event) override;
    void Tick(float deltaTime) override;
    void Render() override;
    
    Camera* GetCamera() const override { return camera; };
};
