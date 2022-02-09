#pragma once

#include <SDL_events.h>

#include "Utils.h"

class Level abstract
{
protected:
    Vector2 size = Vector2();
    
public:
    Level();
    virtual ~Level();

    virtual void OnEvent(const SDL_Event& event) = 0;
    virtual void Tick(float deltaTime) = 0;
    virtual void Render() = 0;

    int GetWidth() const { return size.x; };
    int GetHeight() const { return size.y; };
};
