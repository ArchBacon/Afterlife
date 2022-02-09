#pragma once

#include "Level.h"
#include "Player.h"
#include "Sprite.h"

class FrozenRiver : public Level
{
    Sprite* background;
    Player* player;
    
public:
    FrozenRiver();
    ~FrozenRiver() override;
    
    void Render() override;
    void Tick(float deltaTime) override;
};
