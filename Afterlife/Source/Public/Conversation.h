#pragma once

#include "Interactable.h"

struct Sentence
{
    std::string text;
    Vector2 location;
    SDL_RendererFlip flip;
};

class Conversation : public Interactable
{
    std::vector<Sentence> sentences;
    int index = 0;

public:
    Conversation(Vector2 size = Vector2(256, 256));
    
    void Add(Sentence sentence);
    void Reset();
    
    bool HasNextSentence() const;
    Sentence GetSentence() const;
    void Next();
};
