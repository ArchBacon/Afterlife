#pragma once

#include <SDL_events.h>
#include <string>

#include "Utils.h"

class Camera;
class Sprite;

class Actor
{
protected:
    Vector2 location;
    Sprite* sprite;
    // CollisionBox
    
public:
    Actor(std::string path);
    virtual ~Actor();

    virtual void Tick(float deltaTime);
    virtual void OnEvent(SDL_Event& event);
    virtual void Render(Camera* camera = nullptr);

    void SetLocation(Vector2 location);

    // Relive to center of the window
    Vector2 GetLocation() const { return location; }
    Sprite* GetSprite() const { return sprite; }
};
