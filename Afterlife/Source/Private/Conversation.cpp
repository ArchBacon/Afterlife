#include "Conversation.h"

#include "Sprite.h"

Conversation::Conversation(Vector2 size)
    : Interactable(size)
{
    speechBubble = new Sprite("Assets/speech_bubble.png");
}

void Conversation::RenderSentence() const
{
    const Vector2 location = GetSentence().location;
    speechBubble->Render(location, nullptr, GetSentence().flip);
        
    const Sprite* text = new Sprite(GetSentence().text, true);
    text->Render(location + Vector2(10, 10));

    delete text;
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
