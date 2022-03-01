#include "Levels/FriendsMemoryLevel.h"

#include "Conversation.h"
#include "Sprite.h"
#include "LevelLoaders/FrozenRiverLevelLoader.h"

FriendsMemoryLevel::FriendsMemoryLevel()
{
    size = Vector2(1280, 720);
    border = Vector2(0, 0);
    font = TTF_OpenFont("Assets/Fonts/Roboto.ttf", 24);
    
    camera = new Camera();
    player = new Player("Assets/ghost.png");
    player->SetLocation(Vector2(1070, 490));
    player->Flip();
    
    background = new Sprite("Assets/Cafe/background.png");
    electricityPole = new Sprite("Assets/Cafe/electricity_pole.png");
    charon = new Sprite("Assets/charon.png");
    friends = new Sprite("Assets/Cafe/friends.png");
    speechBubble = new Sprite("Assets/speech_bubble.png");
    
    levelLoader = new FrozenRiverLevelLoader(Vector2(charon->GetWidth(), charon->GetHeight()));
    levelLoader->SetLocation(Vector2(1160, 415));
    
    conversation = new Conversation();
    conversation->SetLocation(Vector2(220, 450));
    conversation->Add({"Those are your friends.", Vector2(970, 300), SDL_FLIP_NONE});
    conversation->Add({"They often played with you, you said?", Vector2(970, 300), SDL_FLIP_NONE});
    conversation->Add({"Hey, have you heard?", Vector2(200, 340), SDL_FLIP_HORIZONTAL});
    conversation->Add({"They say he died.", Vector2(200, 340), SDL_FLIP_HORIZONTAL});
    conversation->Add({"For real!?", Vector2(270, 360), SDL_FLIP_HORIZONTAL});
    conversation->Add({"Messing around with him was fun, though.", Vector2(270, 360), SDL_FLIP_HORIZONTAL});
    conversation->Add({"Dang it, there goes one toy.", Vector2(190, 340), SDL_FLIP_NONE});
    conversation->Add({"They played \"with\" you, it seems.", Vector2(970, 300), SDL_FLIP_NONE});
 
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
    delete speechBubble;

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

    if (player->IsInConversation())
    {
        const Vector2 location = conversation->GetSentence().location;
        
        speechBubble->Render(location, nullptr, conversation->GetSentence().flip);
        
        const Sprite* text = new Sprite(conversation->GetSentence().text, true);
        text->Render(location + Vector2(20, 10));
        delete text;
    }
}
