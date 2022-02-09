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
    Actor(Sprite* sprite);
    virtual ~Actor();

    virtual void Tick(float deltaTime);
    virtual void OnEvent(SDL_Event& event);
    virtual void Render();

    void SetLocation(Vector2 location);

    Vector2 GetWorldLocation() const { return location; }
    Vector2 GetLocation() const;
    Sprite* GetSprite() const { return sprite; }
};
