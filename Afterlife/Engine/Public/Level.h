#pragma once

#include <SDL_events.h>

#include "Actor.h"
#include "Camera.h"
#include "Utils.h"

class Level
{
protected:
    Vector2 size = Vector2(100, 100);
    Vector2 border = Vector2(640, 0);
    
public:
    Level() = default;
    virtual ~Level() = default;
    
    virtual void OnEvent(SDL_Event& event) = 0;
    virtual void Tick(float deltaTime) = 0;
    virtual void Render() = 0;

    int GetWidth() const { return size.x; }
    int GetHeight() const { return size.y; }
    int GetBorderWidth() const { return border.x; }
    int GetBorderHeight() const { return border.y; }
    virtual Camera* GetCamera() const = 0;
};
