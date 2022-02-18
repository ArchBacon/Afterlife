#pragma once

#include "Interactable.h"

class Conversation : public Interactable
{
    Array<std::string> sentences;
    int currentSentenceIndex = 0;
    
public:
    Conversation( Vector2 size = Vector2(256, 256));
    ~Conversation() override;
    
    void Tick(float deltaTime) override;
    void OnEvent(SDL_Event& event) override;
    void Render(Camera* camera = nullptr) override;
    void Interact() const override;
    void AddSentence(std::string sentence);
    
    bool HasNextSentence() const;
    bool IsEmpty() const;
    std::string GetNextSentence();
    std::string GetSentence() const;
};
