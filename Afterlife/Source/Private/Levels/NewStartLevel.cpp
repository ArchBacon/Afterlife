#include "Levels/NewStartLevel.h"

#include "Application.h"
#include "Conversation.h"
#include "Player.h"
#include "Sprite.h"
#include "Levels/EndingLevel.h"

NewStartLevel::NewStartLevel()
{
    // Create objects
    size = Vector2(1280, 720);
    border = Vector2(0, 0);
    camera = new Camera();

    player = new Player("Assets/Convo/transparent.png");

    // Create sprites
    background = new Sprite("Assets/Ending/background.png");

    conversation = new Conversation();
    conversation->SetLocation(Vector2(440, 190));
    conversation->OnConversationEnd([]() -> void
    {
        Application::Get()->LoadLevel(new EndingLevel());
    });
    conversation->Add({"Here we are.", Vector2(535, 180), SDL_FLIP_HORIZONTAL});
    conversation->Add({"You'll reach your next life if you go straight forward from here.", Vector2(535, 180), SDL_FLIP_HORIZONTAL});
    conversation->Add({"Afterwards, please follow staff instructions.", Vector2(535, 180), SDL_FLIP_HORIZONTAL});
    conversation->Add({"Thank you very much.", Vector2(250, 80), SDL_FLIP_NONE});
    conversation->Add({"My pleasure.", Vector2(535, 180), SDL_FLIP_HORIZONTAL});
    conversation->Add({"It would be good if we meet again much, much later next time around.", Vector2(535, 180), SDL_FLIP_HORIZONTAL});
    conversation->Add({"It would.", Vector2(250, 80), SDL_FLIP_NONE});
    conversation->Add({"Well then,", Vector2(535, 180), SDL_FLIP_HORIZONTAL});
    conversation->Add({"May a good life await you.", Vector2(535, 180), SDL_FLIP_HORIZONTAL});

    player->AddInteractable(conversation);
}

NewStartLevel::~NewStartLevel()
{
    // Delete objects
    delete camera;
    delete background;
    delete conversation;
}

void NewStartLevel::OnEvent(SDL_Event& event)
{
    player->OnEvent(event);
}

void NewStartLevel::Tick(float deltaTime)
{
    player->Tick(deltaTime);
    camera->Update();
}

void NewStartLevel::Render()
{
    background->Render();
    conversation->Render();
    
    player->Render();
    if (player->IsInConversation())
    {
        conversation->RenderSentence();
    }
}
