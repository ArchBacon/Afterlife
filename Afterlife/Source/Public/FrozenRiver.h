#pragma once

#include "Actor.h"
#include "Level.h"
#include "Sprite.h"

class FrozenRiver : public Level
{
    Sprite* background;

    Actor* boat;
    
public:
    FrozenRiver();
    ~FrozenRiver() override;
    
    void Render() override;
};
