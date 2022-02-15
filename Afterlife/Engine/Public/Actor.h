#pragma once

#include <SDL_events.h>
#include <SDL_render.h>
#include <string>

#include "CollisionBox.h"
#include "Utils.h"

class Camera;
class Sprite;

class Actor
{
protected:
    Vector2 location;
    Sprite* sprite;
    SDL_Rect collider;

    SDL_RendererFlip flip;
    bool updateCollider = true;
    
public:
    Actor(std::string path);
    virtual ~Actor();

    virtual void Tick(float deltaTime);
    virtual void OnEvent(SDL_Event& event);
    virtual void Render(Camera* camera);
    
    void SetLocation(Vector2 location);

    // Relive to center of the window
    Vector2 GetLocation() const { return location; }
    Sprite* GetSprite() const { return sprite; }
    SDL_Rect GetCollider() const { return collider; }
};
