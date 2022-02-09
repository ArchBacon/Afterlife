#pragma once

#include "Actor.h"

class Player : public Actor
{
public:
    Player(const std::string& path);
    ~Player() override;
    
    void Tick(float deltaTime) override;
    void OnEvent(SDL_Event& event) override;
    void Render() override;
};
