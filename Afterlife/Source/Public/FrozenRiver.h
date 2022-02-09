#pragma once

#include "Level.h"

class FrozenRiver final : public Level
{
public:
    FrozenRiver();
    ~FrozenRiver() override;
    
    void Render() override;
    void OnEvent(const SDL_Event& event) override;
    void Tick(float deltaTime) override;
};
