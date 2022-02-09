#pragma once

#include <SDL_events.h>

#include "Utils.h"

class Level
{
protected:
    Vector2 size;
    
public:
    virtual ~Level() = default;
    
    virtual void OnEvent(SDL_Event& event) {}
    virtual void Tick(float deltaTime) {}
    virtual void Render() = 0;

    int GetWidth() const { return size.x; }
    int GetHeight() const { return size.y; }
};
