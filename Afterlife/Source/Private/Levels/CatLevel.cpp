#include "Levels/CatLevel.h"

#include "Conversation.h"
#include "Player.h"
#include "Sprite.h"
#include "LevelLoaders/FrozenRiverLevelLoader.h"

CatLevel::CatLevel()
{
    camera = new Camera();
    player = new Player("Assets/Characters/Player-small.png");
    player->SetLocation(Vector2(831, 408));
    player->Flip();
    
    background = new Sprite("Assets/Levels/Cat.png");

    levelLoader = new FrozenRiverLevelLoader(Vector2(50, 208));
    levelLoader->SetLocation(Vector2(908, 337));

    constexpr Vector2 catSpeechLoc = Vector2(191, 239);
    constexpr Vector2 humanSpeechLoc = Vector2(173, 198);
    constexpr Vector2 grimSpeechLoc = Vector2(734, 212);
    
    conversation = new Conversation(Vector2(109, 134));
    conversation->SetLocation(Vector2(165, 334));
    conversation->Add({"That is the stray cat you had taken care of.", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"Meow~", catSpeechLoc});
    conversation->Add({"Oh, what's wrong?", humanSpeechLoc});
    conversation->Add({"Are you lonely?", humanSpeechLoc});
    conversation->Add({"Meow~", catSpeechLoc});
    conversation->Add({"It's living quite well, it seems.", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"Good news, is it not?", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
 
    player->AddInteractable(levelLoader);
    player->AddInteractable(conversation);
}

CatLevel::~CatLevel()
{
    delete camera;
    delete player;
    
    delete background;

    delete conversation;
    delete levelLoader;
}

void CatLevel::OnEvent(SDL_Event& event)
{
    player->OnEvent(event);
}

void CatLevel::Tick(float deltaTime)
{
    player->Tick(deltaTime);
    camera->Update();
}

void CatLevel::Render()
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
