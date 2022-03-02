#include "Levels/ConversationLevel.h"

#include "Application.h"
#include "Conversation.h"
#include "Player.h"
#include "Sprite.h"

ConversationLevel::ConversationLevel()
{
    // Create objects
    size = Vector2(1280, 720);
    border = Vector2(0, 0);
    camera = new Camera();

    player = new Player("Assets/Convo/transparent.png");

    // Create sprites
    background = new Sprite("Assets/Convo/background.png");
    boat = new Sprite("Assets/Convo/boat.png");

    conversation = new Conversation();
    conversation->SetLocation(Vector2(512, 420));
    conversation->Add({"Are you really satisfied with merely that wish~?", Vector2(370, 320), SDL_FLIP_NONE});
    conversation->Add({"You may still ask for a proper wish now, you know?", Vector2(370, 320), SDL_FLIP_NONE});
    conversation->Add({"...", Vector2(630, 380), SDL_FLIP_HORIZONTAL});
    conversation->Add({"Ah, i know!", Vector2(370, 320), SDL_FLIP_NONE});
    conversation->Add({"Let us make those bastards suffer!", Vector2(370, 320), SDL_FLIP_NONE});
    conversation->Add({"A curse upon them!", Vector2(370, 320), SDL_FLIP_NONE});
    conversation->Add({"Or perhaps you prefer resurrection to take revenge directly-", Vector2(370, 320), SDL_FLIP_NONE});
    conversation->Add({"I've always wanted to die.", Vector2(630, 380), SDL_FLIP_HORIZONTAL});
    conversation->Add({"However, i'd hate it if i trouble anyone with my death...", Vector2(630, 380), SDL_FLIP_HORIZONTAL});
    conversation->Add({"But nothing like that happened.", Vector2(630, 380), SDL_FLIP_HORIZONTAL});
    conversation->Add({"I'm glad that i died.", Vector2(630, 380), SDL_FLIP_HORIZONTAL});
    conversation->Add({"...", Vector2(370, 320), SDL_FLIP_NONE});
    conversation->Add({"Is that so?", Vector2(370, 320), SDL_FLIP_NONE});

    player->AddInteractable(conversation);
}

ConversationLevel::~ConversationLevel()
{
    // Delete objects
    delete camera;
    delete background;
    delete boat;
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
    boat->Render();

    conversation->Render();
    
    player->Render();
    if (player->IsInConversation())
    {
        conversation->RenderSentence();
    }
}
