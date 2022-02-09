#pragma once

#include <SDL_events.h>

#include "Sprite.h"
#include "Utils.h"

class Actor
{
protected:
    Vector2 location;
    Sprite* sprite;
    
public:
    Actor(std::string path);
    virtual ~Actor();

    virtual void Tick(float deltaTime);
    virtual void OnEvent(SDL_Event& event);
    virtual void Render();

    void SetLocation(Vector2 location);

    // Relive to center of the window
    Vector2 GetScreenLocation() const { return location; }
    Vector2 GetWorldLocation() const;
    Sprite* GetSprite() const { return sprite; }
};
