#pragma once

#include "Conversation.h"
#include "Level.h"
#include "Player.h"

class FriendsLevel : public Level
{
    Camera* camera;
    Player* player;
    
    Sprite* background;
    Sprite* electricityPole;

    Conversation* conversation;
    Interactable* levelLoader;
    
public:
    FriendsLevel();
    ~FriendsLevel() override;
    
    void OnEvent(SDL_Event& event) override;
    void Tick(float deltaTime) override;
    void Render() override;
    
    Camera* GetCamera() const override { return camera; };
};
