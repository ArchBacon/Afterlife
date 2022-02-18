#include "Levels/FriendsMemoryLevel.h"

#include "Conversation.h"
#include "Sprite.h"
#include "LevelLoaders/FrozenRiverLevelLoader.h"

FriendsMemoryLevel::FriendsMemoryLevel()
{
    size = Vector2(1280, 720);
    border = Vector2(0, 0);
    
    camera = new Camera();
    player = new Player("Assets/ghost.png");
    player->SetLocation(Vector2(1070, 490));
    player->Flip();
    
    background = new Sprite("Assets/Cafe/background.png");
    electricityPole = new Sprite("Assets/Cafe/electricity_pole.png");
    charon = new Sprite("Assets/charon.png");
    friends = new Sprite("Assets/Cafe/friends.png");
    
    levelLoader = new FrozenRiverLevelLoader(Vector2(charon->GetWidth(), charon->GetHeight()));
    levelLoader->SetLocation(Vector2(1160, 415));
    conversation = new Conversation();
    conversation->SetLocation(Vector2(220, 450));
    conversation->AddSentence("Sentence #1");
    conversation->AddSentence("Sentence #2");
    conversation->AddSentence("Sentence #3");

    player->AddInteractable(levelLoader);
    player->AddInteractable(conversation);
}

FriendsMemoryLevel::~FriendsMemoryLevel()
{
    delete camera;
    delete player;
    
    delete background;
    delete electricityPole;

    delete friends;
    delete charon;

    delete conversation;
    delete levelLoader;
}

void FriendsMemoryLevel::OnEvent(SDL_Event& event)
{
    player->OnEvent(event);
}

void FriendsMemoryLevel::Tick(float deltaTime)
{
    player->Tick(deltaTime);
    camera->Update();
}

void FriendsMemoryLevel::Render()
{
    background->Render();
    charon->Render(Vector2(1160, 415));
    levelLoader->Render();
    friends->Render(Vector2(220, 450));
    conversation->Render();
    player->Render();
    electricityPole->Render();
}
