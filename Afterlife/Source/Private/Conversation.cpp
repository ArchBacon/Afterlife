#include "Conversation.h"

#include "Sprite.h"

Conversation::Conversation(Vector2 size, Player* player)
    : Interactable(size), player(player)
{
    speechBubble = new Sprite("Assets/Common/SpeechBubble.png");
    /** callback is an empty statement by default */
    callback = []() -> void {};
}

void Conversation::RenderSentence() const
{
    const Vector2 location = GetSentence().location;
    speechBubble->Render(location, nullptr, GetSentence().flip);
        
    const Sprite* text = new Sprite(GetSentence().text, true);
    text->Render(location + Vector2(20, 10));

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

    /**
     * If the sentence is flagged to be owned by a moving player, then alter
     * the location where the text should be located based on the player's location
     */
    if (player != nullptr && sentence.playerSentence)
    {
        sentence.location.x = player->GetLocation().x + 92;

        return sentence;
    }
    
    return sentence;
}

void Conversation::Next()
{
    index += 1;
}

bool Conversation::HasEnded() const
{
    return ended;
}

void Conversation::OnConversationEnd(std::function<void()> func)
{
    callback = func;
}

void Conversation::EndConversation()
{
    ended = true;
    callback();
}
