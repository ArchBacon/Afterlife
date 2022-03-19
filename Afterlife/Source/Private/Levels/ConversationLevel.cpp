#include "Levels/ConversationLevel.h"

#include "Application.h"
#include "Conversation.h"
#include "Player.h"
#include "Sprite.h"
#include "Levels/GoodbyeLevel.h"

ConversationLevel::ConversationLevel()
{
    camera = new Camera();
    player = new Player("Assets/Common/Transparent.png");
    
    background = new Sprite("Assets/Levels/Conversation.png");

    constexpr Vector2 playerSpeechLoc = Vector2(538, 252);
    constexpr Vector2 grimSpeechLoc = Vector2(248, 204);
    
    conversation = new Conversation(Vector2(223, 204));
    conversation->SetLocation(Vector2(376, 345));
    conversation->OnConversationEnd([]() -> void
    {
        Application::Get()->LoadLevel(new GoodbyeLevel());
    });
    conversation->Add({"Are you really satisfied with merely that wish~?", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"You may still ask for a proper wish now, you know?", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"...", playerSpeechLoc});
    conversation->Add({"Ah, i know!", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"Let us make those bastards suffer!", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"A curse upon them!", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"Or perhaps you prefer resurrection to take revenge directly-", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"I've always wanted to die.", playerSpeechLoc});
    conversation->Add({"However, i'd hate it if i trouble anyone with my death...", playerSpeechLoc});
    conversation->Add({"But nothing like that happened.", playerSpeechLoc});
    conversation->Add({"I'm glad that i died.", playerSpeechLoc});
    conversation->Add({"...", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"Is that so?", grimSpeechLoc, SDL_FLIP_HORIZONTAL});

    player->AddInteractable(conversation);
}

ConversationLevel::~ConversationLevel()
{
    delete camera;
    delete background;
    delete conversation;
}

void ConversationLevel::OnEvent(SDL_Event& event)
{
    player->OnEvent(event);
}

void ConversationLevel::Tick(float deltaTime)
{
    player->Tick(deltaTime);
    camera->Update();
}

void ConversationLevel::Render()
{
    background->Render();
    conversation->Render();
    
    player->Render();
    if (player->IsInConversation())
    {
        conversation->RenderSentence();
    }
}
