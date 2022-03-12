#include "Levels/FriendsLevel.h"

#include "Conversation.h"
#include "Sprite.h"
#include "LevelLoaders/FrozenRiverLevelLoader.h"

FriendsLevel::FriendsLevel()
{
    size = Vector2(989, 720);
    border = Vector2(0, 0);
    
    camera = new Camera();
    player = new Player("Assets/v2/Characters/Player-small.png");
    player->SetLocation(Vector2(152, 396));
    player->Flip();
    
    background = new Sprite("Assets/v2/Levels/Friends.png");
    electricityPole = new Sprite("Assets/v2/Levels/Friends-overlay.png");
    
    levelLoader = new FrozenRiverLevelLoader(Vector2(100, 208));
    levelLoader->SetLocation(Vector2(33, 354));

    constexpr Vector2 friend1 = Vector2(97, 195);
    constexpr Vector2 friend2 = Vector2(161, 189);
    constexpr Vector2 friend3 = Vector2(450, 194);
    constexpr Vector2 grim = Vector2(55, 222);
    
    conversation = new Conversation(Vector2(237, 146));
    conversation->SetLocation(Vector2(269, 332));
    conversation->Add({"Those are your friends.", grim, SDL_FLIP_NONE});
    conversation->Add({"They often played with you, you said?", grim, SDL_FLIP_NONE});
    conversation->Add({"Hey, have you heard?", friend1, SDL_FLIP_HORIZONTAL});
    conversation->Add({"They say he died.", friend1, SDL_FLIP_HORIZONTAL});
    conversation->Add({"For real!?", friend2, SDL_FLIP_HORIZONTAL});
    conversation->Add({"Messing around with him was fun, though.", friend2, SDL_FLIP_HORIZONTAL});
    conversation->Add({"Dang it, there goes one toy.", friend3, SDL_FLIP_NONE});
    conversation->Add({"They played \"with\" you, it seems.", grim, SDL_FLIP_NONE});
 
    player->AddInteractable(levelLoader);
    player->AddInteractable(conversation);
}

FriendsLevel::~FriendsLevel()
{
    delete camera;
    delete player;
    
    delete background;
    delete electricityPole;

    delete conversation;
    delete levelLoader;
}

void FriendsLevel::OnEvent(SDL_Event& event)
{
    player->OnEvent(event);
}

void FriendsLevel::Tick(float deltaTime)
{
    player->Tick(deltaTime);
    camera->Update();
}

void FriendsLevel::Render()
{
    background->Render();
    levelLoader->Render();
    conversation->Render();

    player->Render();
    electricityPole->Render();

    if (player->IsInConversation())
    {
        conversation->RenderSentence();
    }
}
