#include "Levels/CatLevel.h"

#include "Conversation.h"
#include "Player.h"
#include "Sprite.h"
#include "LevelLoaders/FrozenRiverLevelLoader.h"

CatLevel::CatLevel()
{
    size = Vector2(1280, 720);
    
    camera = new Camera();
    player = new Player("Assets/ghost.png");
    player->SetLocation(Vector2(1070, 490));
    player->Flip();
    
    background = new Sprite("Assets/Street/background.png");
    charon = new Sprite("Assets/charon.png");
    cat = new Sprite("Assets/Street/cat.png");

    levelLoader = new FrozenRiverLevelLoader(Vector2(charon->GetWidth(), charon->GetHeight()));
    levelLoader->SetLocation(Vector2(1160, 415));
    
    conversation = new Conversation(Vector2(144, 204));
    conversation->SetLocation(Vector2(220, 450));
    conversation->Add({"That is the stray cat you had taken care of.", Vector2(970, 300), SDL_FLIP_NONE});
    conversation->Add({"Meow~", Vector2(300, 500), SDL_FLIP_HORIZONTAL});
    conversation->Add({"Oh, what's wrong?", Vector2(200, 340), SDL_FLIP_HORIZONTAL});
    conversation->Add({"Are you lonely?", Vector2(200, 340), SDL_FLIP_HORIZONTAL});
    conversation->Add({"Meow~", Vector2(300, 500), SDL_FLIP_HORIZONTAL});
    conversation->Add({"It's living quite well, it seems.", Vector2(970, 300), SDL_FLIP_NONE});
    conversation->Add({"Good news, is it not?", Vector2(970, 300), SDL_FLIP_NONE});
 
    player->AddInteractable(levelLoader);
    player->AddInteractable(conversation);
}

CatLevel::~CatLevel()
{
    delete camera;
    delete player;
    
    delete background;
    delete cat;
    delete charon;

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
    charon->Render(Vector2(1160, 415));
    
    levelLoader->Render();
    cat->Render(Vector2(220, 450));
    conversation->Render();

    player->Render();

    if (player->IsInConversation())
    {
        conversation->RenderSentence();
    }
}
