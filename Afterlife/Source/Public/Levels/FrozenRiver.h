#pragma once

#include "Interactable.h"
#include "Level.h"
#include "Player.h"
#include "Sprite.h"

class FrozenRiver : public Level
{
    Camera* camera;
    Sprite* background;
    Player* player;

    Interactable* box;
    
public:
    FrozenRiver();
    ~FrozenRiver() override;
    
    void Render() override;
    void OnEvent(SDL_Event& event) override;
    void Tick(float deltaTime) override;
    
    Camera* GetCamera() const override { return camera; };
};
