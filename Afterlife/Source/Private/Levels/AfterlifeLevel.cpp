#include "Levels/AfterlifeLevel.h"

#include "Conversation.h"
#include "Sprite.h"
#include "LevelLoaders/FrozenRiverLevelLoader.h"

AfterlifeLevel::AfterlifeLevel()
{
    size = Vector2(1280, 720);
    border = Vector2(0, 0);
    
    camera = new Camera();
    player = new Player("Assets/ghost_150.png");
    player->SetLocation(Vector2(256, 329));
    
    background = new Sprite("Assets/Intro/background.png");
    
    levelLoader = new FrozenRiverLevelLoader(Vector2(125, 340));
    levelLoader->SetLocation(Vector2(1120, 250));
    
    conversation = new Conversation(Vector2(180, 380), player);
    conversation->SetLocation(Vector2(415, 200));
    conversation->Add({"Congratulations!", Vector2(420, 90), SDL_FLIP_HORIZONTAL});
    conversation->Add({"You are the millionth person to have died within this area!", Vector2(420, 90), SDL_FLIP_HORIZONTAL});
    conversation->Add({"For that, I shall grant you a single wish!", Vector2(420, 90), SDL_FLIP_HORIZONTAL});
    conversation->Add({"What shall it be?", Vector2(420, 90), SDL_FLIP_HORIZONTAL});
    conversation->Add({"Resurrection?", Vector2(420, 90), SDL_FLIP_HORIZONTAL});
    conversation->Add({"A chance to redo your life?", Vector2(420, 90), SDL_FLIP_HORIZONTAL});
    conversation->Add({"Now!!", Vector2(420, 90), SDL_FLIP_HORIZONTAL});
    conversation->Add({"What is your wish!?", Vector2(420, 90), SDL_FLIP_HORIZONTAL});
    conversation->Add({"Um...", Vector2(player->GetLocation().x - 100, 230), SDL_FLIP_NONE, true});
    conversation->Add({"Ah...", Vector2(player->GetLocation().x - 100, 230), SDL_FLIP_NONE, true});
    conversation->Add({"Then-", Vector2(player->GetLocation().x - 100, 230), SDL_FLIP_NONE, true});
    conversation->Add({"I want to see how everyone's been doing.", Vector2(player->GetLocation().x - 100, 230), SDL_FLIP_NONE, true});
    conversation->Add({"What?", Vector2(420, 90), SDL_FLIP_HORIZONTAL});
 
    player->AddInteractable(levelLoader);
    player->AddInteractable(conversation);
}

AfterlifeLevel::~AfterlifeLevel()
{
    delete camera;
    delete player;
    
    delete background;

    delete conversation;
    delete levelLoader;
}

void AfterlifeLevel::OnEvent(SDL_Event& event)
{
    player->OnEvent(event);
}

void AfterlifeLevel::Tick(float deltaTime)
{
    player->Tick(deltaTime);
    camera->Update();

    printf("Plocx: %d\n", player->GetLocation().x);
}

void AfterlifeLevel::Render()
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
