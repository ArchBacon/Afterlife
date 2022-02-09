#pragma once

#include <SDL_events.h>

#include "Utils.h"

class Level
{
protected:
    Vector2 size = Vector2(100, 100);
    SDL_Rect camera = {};
    
public:
    virtual ~Level() = default;
    
    virtual void OnEvent(SDL_Event& event) {}
    virtual void Tick(float deltaTime) {}
    virtual void Render() = 0;

    int GetWidth() const { return size.x; }
    int GetHeight() const { return size.y; }
    SDL_Rect GetCamera() const { return camera; }
};
