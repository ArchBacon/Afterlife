#include "Levels/GoodbyeLevel.h"

#include "Application.h"
#include "Conversation.h"
#include "Player.h"
#include "Sprite.h"
#include "Levels/EndLevel.h"

GoodbyeLevel::GoodbyeLevel()
{
    camera = new Camera();
    player = new Player("Assets/v2/Common/transparent.png");

    background = new Sprite("Assets/v2/Levels/Goodbye.png");

    constexpr Vector2 grimSpeechLoc = Vector2(439, 103);
    constexpr Vector2 playerSpeechLoc = Vector2(385, 53);

    conversation = new Conversation(Vector2(135, 260));
    conversation->SetLocation(Vector2(416, 247));
    conversation->OnConversationEnd([]() -> void
    {
        Application::Get()->LoadLevel(new EndLevel());
    });
    conversation->Add({"Here we are.", grimSpeechLoc, SDL_FLIP_NONE});
    conversation->Add({"You'll reach your next life if you go straight forward from here.", grimSpeechLoc, SDL_FLIP_NONE});
    conversation->Add({"Afterwards, please follow staff instructions.", grimSpeechLoc, SDL_FLIP_NONE});
    conversation->Add({"Thank you very much.", playerSpeechLoc, SDL_FLIP_NONE});
    conversation->Add({"My pleasure.", grimSpeechLoc, SDL_FLIP_NONE});
    conversation->Add({"It would be good if we meet again much, much later next time around.", grimSpeechLoc, SDL_FLIP_NONE});
    conversation->Add({"It would.", playerSpeechLoc, SDL_FLIP_NONE});
    conversation->Add({"Well then,", grimSpeechLoc, SDL_FLIP_NONE});
    conversation->Add({"May a good life await you.", grimSpeechLoc, SDL_FLIP_NONE});

    player->AddInteractable(conversation);
}

GoodbyeLevel::~GoodbyeLevel()
{
    delete camera;
    delete background;
    delete conversation;
}

void GoodbyeLevel::OnEvent(SDL_Event& event)
{
    player->OnEvent(event);
}

void GoodbyeLevel::Tick(float deltaTime)
{
    player->Tick(deltaTime);
    camera->Update();
}

void GoodbyeLevel::Render()
{
    background->Render();
    conversation->Render();
    
    player->Render();
    if (player->IsInConversation())
    {
        conversation->RenderSentence();
    }
}
