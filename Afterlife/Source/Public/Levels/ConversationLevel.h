#pragma once

#include "Level.h"

class Player;
class Conversation;

class ConversationLevel : public Level
{
    Camera* camera;
    Player* player;

    Sprite* background;
    Sprite* boat;

    Conversation* conversation;
    
public:
    ConversationLevel();
    ~ConversationLevel() override;
    
    void Render() override;
    void OnEvent(SDL_Event& event) override;
    void Tick(float deltaTime) override;
    
    Camera* GetCamera() const override { return camera; };
};
