#pragma once

#include <functional>

#include "Interactable.h"
#include "Player.h"

struct Sentence
{
    std::string text;
    Vector2 location;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    bool playerSentence = false;
};

class Conversation : public Interactable
{
    Sprite* speechBubble;
    std::function<void()> callback;
    
    std::vector<Sentence> sentences;
    int index = 0;

    bool ended = false;

    Player* player;

public:
    Conversation(Vector2 size = Vector2(256, 256), Player* player = nullptr);

    void RenderSentence() const;
    void Add(Sentence sentence);
    void Reset();
    
    bool HasNextSentence() const;
    Sentence GetSentence() const;
    void Next();
    bool HasEnded() const;

    void OnConversationEnd(std::function<void()> func);
    void EndConversation();
};
