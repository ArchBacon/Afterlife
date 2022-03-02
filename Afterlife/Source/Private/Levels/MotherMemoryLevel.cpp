#include "Levels/MotherMemoryLevel.h"

#include "Conversation.h"
#include "Player.h"
#include "Sprite.h"
#include "LevelLoaders/FrozenRiverLevelLoader.h"

MotherMemoryLevel::MotherMemoryLevel()
{
    size = Vector2(1280, 720);
    border = Vector2(0, 0);

    camera = new Camera();
    player = new Player("Assets/ghost.png");
    player->SetLocation(Vector2(1070, 250));
    player->Flip();
    
    background = new Sprite("Assets/House/background.png");
    furniture = new Sprite("Assets/House/furniture.png");
    charon = new Sprite("Assets/charon.png");
    mother = new Sprite("Assets/House/grandma.png");

    levelLoader = new FrozenRiverLevelLoader(Vector2(charon->GetWidth(), charon->GetHeight()));
    levelLoader->SetLocation(Vector2(1160, 200));
    
    conversation = new Conversation(Vector2(99, 200));
    conversation->SetLocation(Vector2(220, 200));
    conversation->Add({"That is your mother.", Vector2(970, 80), SDL_FLIP_NONE});
    conversation->Add({"She's a good-for-nothing, you said?", Vector2(970, 80), SDL_FLIP_NONE});
    conversation->Add({"Huh?", Vector2(220, 80), SDL_FLIP_HORIZONTAL});
    conversation->Add({"What?", Vector2(220, 80), SDL_FLIP_HORIZONTAL});
    conversation->Add({"He's dead?", Vector2(220, 80), SDL_FLIP_HORIZONTAL});
    conversation->Add({"...", Vector2(220, 80), SDL_FLIP_HORIZONTAL});
    conversation->Add({"Like i'd know!", Vector2(220, 80), SDL_FLIP_HORIZONTAL});
    conversation->Add({"I didn't have him because i wanted to!", Vector2(220, 80), SDL_FLIP_HORIZONTAL});
    conversation->Add({"She truly is a good-for-nothing, it seems.", Vector2(970, 80), SDL_FLIP_NONE});
 
    player->AddInteractable(levelLoader);
    player->AddInteractable(conversation);
}

MotherMemoryLevel::~MotherMemoryLevel()
{
    delete camera;
    delete player;
    
    delete background;
    delete furniture;
    delete mother;
    delete charon;

    delete conversation;
    delete levelLoader;
}

void MotherMemoryLevel::OnEvent(SDL_Event& event)
{
    player->OnEvent(event);
}

void MotherMemoryLevel::Tick(float deltaTime)
{
    player->Tick(deltaTime);
    camera->Update();
}

void MotherMemoryLevel::Render()
{
    background->Render();
    charon->Render(Vector2(1160, 200));
    
    levelLoader->Render();
    mother->Render(Vector2(220, 200));
    conversation->Render();

    player->Render();

    furniture->Render();

    if (player->IsInConversation())
    {
        conversation->RenderSentence();
    }
}
