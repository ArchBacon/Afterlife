#pragma once

#include "Interactable.h"
#include "Level.h"
#include "Player.h"

class FrozenRiver : public Level
{
    Camera* camera;
    Player* player;
    Interactable* levelLoaderCoworker;
    Interactable* levelLoaderFriends;
    Interactable* levelLoaderMother;
    Interactable* levelLoaderCat;
    Interactable* levelLoaderConversation;

    Sprite* background;
    
public:
    FrozenRiver();
    ~FrozenRiver() override;
    
    void Render() override;
    void OnEvent(SDL_Event& event) override;
    void Tick(float deltaTime) override;
    
    Camera* GetCamera() const override { return camera; };
};
