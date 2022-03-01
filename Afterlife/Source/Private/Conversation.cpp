#include "Conversation.h"

Conversation::Conversation(Vector2 size)
    : Interactable(size)
{
}

void Conversation::Add(Sentence sentence)
{
    sentences.push_back(sentence);
}

void Conversation::Reset()
{
    index = 0;
}

bool Conversation::HasNextSentence() const
{
    return sentences.size() > index + 1;
}

Sentence Conversation::GetSentence() const
{
    return sentences[index];
}

void Conversation::Next()
{
    index += 1;
}
