#include "Levels/CoworkersLevel.h"
#include "Conversation.h"
#include "Sprite.h"
#include "LevelLoaders/FrozenRiverLevelLoader.h"

CoworkersLevel::CoworkersLevel()
{
    camera = new Camera();
    player = new Player("Assets/v2/Characters/Player.png");
    player->SetLocation(Vector2(609, 364));
    player->Flip();
    
    background = new Sprite("Assets/v2/Levels/Coworkers.png");

    levelLoader = new FrozenRiverLevelLoader(Vector2(199, 415));
    levelLoader->SetLocation(Vector2(773, 259));

    constexpr Vector2 coworkerSpeechLoc = Vector2(152, 194);
    constexpr Vector2 grimSpeechLoc = Vector2(625, 146);

    conversation = new Conversation(Vector2(148, 304));
    conversation->SetLocation(Vector2(308, 302));
    conversation->Add({"That is your coworker.", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"He often depended on you.", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"Telling you that you're the only one he could rely on, you said?", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"Say, won't you take this job?", coworkerSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"You're the only one that can do this!", coworkerSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"He says that to anyone, it seems.", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    
    player->AddInteractable(levelLoader);
    player->AddInteractable(conversation);
}

CoworkersLevel::~CoworkersLevel()
{
    delete camera;
    delete player;
    
    delete background;

    delete conversation;
    delete levelLoader;
}

void CoworkersLevel::OnEvent(SDL_Event& event)
{
    player->OnEvent(event);
}

void CoworkersLevel::Tick(float deltaTime)
{
    player->Tick(deltaTime);
    camera->Update();
}

void CoworkersLevel::Render()
{
    background->Render();
    levelLoader->Render();
    conversation->Render();

    player->Render();

    if (player->IsInConversation())
    {
        conversation->RenderSentence();
    }
}
