#pragma once

#include "Actor.h"
#include "Interactable.h"
#include "Timer.h"

class Player : public Actor
{
    float speed = 460.f;
    Array<Interactable*> actors;
    Timer interactTimer;
    bool canInteract = true;
    bool listening = false;
    
    Sprite* interactKey;
    bool renderInteractKey = false;
    Vector2 renderLocation;
    
public:
    Player(const std::string& path);
    ~Player() override;
    
    void Tick(float deltaTime) override;
    void OnEvent(SDL_Event& event) override;
    void Render(Camera* camera = nullptr) override;

    void AddInteractable(Interactable* interactable);
    bool IsOverlapping(const Interactable* interactable) const;
    bool IsInConversation() const { return listening; }
};
