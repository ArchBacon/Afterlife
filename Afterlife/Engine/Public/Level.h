#pragma once

#include <SDL_events.h>

#include "Actor.h"
#include "Camera.h"
#include "Utils.h"

class Level
{
protected:
    Vector2 size = Vector2(100, 100);
    Camera* camera = new Camera();
    
public:
    virtual ~Level()
    {
        delete camera;
    }
    
    virtual void OnEvent(SDL_Event& event) {}
    virtual void Tick(float deltaTime) {}
    virtual void Render() = 0;

    int GetWidth() const { return size.x; }
    int GetHeight() const { return size.y; }
    Camera* GetCamera() const { return camera; }
};
