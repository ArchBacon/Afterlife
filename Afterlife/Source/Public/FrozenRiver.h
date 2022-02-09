#pragma once

#include "Level.h"
#include "Sprite.h"

class FrozenRiver : public Level
{
    Sprite* background;
    
public:
    FrozenRiver();
    ~FrozenRiver() override;
    
    void Render() override;
};
