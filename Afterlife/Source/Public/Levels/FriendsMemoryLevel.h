#pragma once

#include "Conversation.h"
#include "Level.h"
#include "Player.h"
#include "SDL_ttf.h"

class FriendsMemoryLevel : public Level
{
    Camera* camera;
    Player* player;
    
    Sprite* background;
    Sprite* electricityPole;
    Sprite* charon;
    Sprite* friends;
    Sprite* speechBubble;

    Conversation* conversation;
    Interactable* levelLoader;

    TTF_Font* font;
    
public:
    FriendsMemoryLevel();
    ~FriendsMemoryLevel() override;
    
    void OnEvent(SDL_Event& event) override;
    void Tick(float deltaTime) override;
    void Render() override;
    
    Camera* GetCamera() const override { return camera; };
};
