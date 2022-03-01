#include "Levels/CoworkersMemoryLevel.h"

#include "Conversation.h"
#include "Sprite.h"
#include "LevelLoaders/FrozenRiverLevelLoader.h"

CoworkersMemoryLevel::CoworkersMemoryLevel()
{
    size = Vector2(1280, 720);
    border = Vector2(0, 0);
    
    camera = new Camera();
    player = new Player("Assets/ghost.png");
    player->SetLocation(Vector2(1070, 539));
    player->Flip();
    
    background = new Sprite("Assets/Office/background.png");
    charon = new Sprite("Assets/charon.png");
    coworkers = new Sprite("Assets/Office/coworkers.png");

    levelLoader = new FrozenRiverLevelLoader(Vector2(charon->GetWidth(), charon->GetHeight()));
    levelLoader->SetLocation(Vector2(1160, 490));

    conversation = new Conversation();
    conversation->SetLocation(Vector2(200, 505));
    conversation->Add({"That is your coworker.", Vector2(970, 370)});
    conversation->Add({"He often depended on you.", Vector2(970, 370)});
    conversation->Add({"Telling you that you're the only one he could rely on, you said?", Vector2(970, 370)});
    conversation->Add({"Say, won't you take this job?", Vector2(180, 400)});
    conversation->Add({"You're the only one that can do this!", Vector2(180, 400)});
    conversation->Add({"He says that to anyone, it seems.", Vector2(970, 370)});
    
    player->AddInteractable(levelLoader);
    player->AddInteractable(conversation);
}

CoworkersMemoryLevel::~CoworkersMemoryLevel()
{
    delete camera;
    delete player;
    
    delete background;
    delete coworkers;
    delete charon;

    delete conversation;
    delete levelLoader;
}

void CoworkersMemoryLevel::OnEvent(SDL_Event& event)
{
    player->OnEvent(event);
}

void CoworkersMemoryLevel::Tick(float deltaTime)
{
    player->Tick(deltaTime);
    camera->Update();
}

void CoworkersMemoryLevel::Render()
{
    background->Render();
    charon->Render(Vector2(1160, 490));
    
    levelLoader->Render();
    coworkers->Render(Vector2(200, 505));
    conversation->Render();

    player->Render();

    if (player->IsInConversation())
    {
        conversation->RenderSentence();
    }
}
