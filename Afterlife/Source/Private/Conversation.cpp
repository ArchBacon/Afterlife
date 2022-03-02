#include "Conversation.h"

#include "Sprite.h"

Conversation::Conversation(Vector2 size, Player* player)
    : Interactable(size), player(player)
{
    speechBubble = new Sprite("Assets/speech_bubble.png");
    convoEndFunc = []() -> void {};
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
    Sentence sentence = sentences[index];
    
    if (player != nullptr && sentence.playerSentence)
    {
        sentence.location.x = player->GetLocation().x - 200;

        return sentence;
    }
    
    return sentence;
}

void Conversation::Next()
{
    index += 1;
}

void Conversation::OnConversationEnd(std::function<void()> func)
{
    convoEndFunc = func;
}

void Conversation::EndConversation()
{
    convoEndFunc();
}
