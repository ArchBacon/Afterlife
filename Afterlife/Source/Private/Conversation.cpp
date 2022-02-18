#include "Conversation.h"

Conversation::Conversation(Vector2 size)
    : Interactable(size)
{
}

Conversation::~Conversation()
{
}

void Conversation::Tick(float deltaTime)
{
    Interactable::Tick(deltaTime);
}

void Conversation::OnEvent(SDL_Event& event)
{
    Interactable::OnEvent(event);
}

void Conversation::Render(Camera* camera)
{
    Interactable::Render(camera);
}

void Conversation::Interact() const
{
    Interactable::Interact();
}

void Conversation::AddSentence(std::string sentence)
{
    sentences.Add(sentence);
}

void Conversation::Reset()
{
    currentSentenceIndex = 0;
}

bool Conversation::HasNextSentence() const
{
    return sentences.iterator.size() > currentSentenceIndex + 1;
}

bool Conversation::IsEmpty() const
{
    return sentences.iterator.empty();
}

std::string Conversation::GetNextSentence()
{
    currentSentenceIndex += 1;

    return GetSentence();
}

std::string Conversation::GetSentence() const
{
    return sentences.iterator[currentSentenceIndex];
}
