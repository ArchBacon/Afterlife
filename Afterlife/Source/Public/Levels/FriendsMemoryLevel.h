#pragma once

#include "Conversation.h"
#include "Level.h"
#include "Player.h"

class FriendsMemoryLevel : public Level
{
    Camera* camera;
    Player* player;
    
    Sprite* background;
    Sprite* electricityPole;
    Sprite* charon;
    Sprite* friends;

    Conversation* conversation;
    Interactable* levelLoader;
    
public:
    FriendsMemoryLevel();
    ~FriendsMemoryLevel() override;
    
    void OnEvent(SDL_Event& event) override;
    void Tick(float deltaTime) override;
    void Render() override;
    
    Camera* GetCamera() const override { return camera; };
};
