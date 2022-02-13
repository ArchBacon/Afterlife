#include "Levels/FrozenRiver.h"

#include "Application.h"
#include "Player.h"
#include "LevelLoaders/CatMemoryLevelLoader.h"

FrozenRiver::FrozenRiver()
{
    // Create objects
   camera = new Camera();
    background = new Sprite("Assets/Memories/background.png");
    player = new Player("Assets/Memories/player_cube.png");
    player->SetLocation(Vector2(640, 550));

    box = new CatMemoryLevelLoader(Vector2(125, 125));
    box->SetLocation(Vector2(1000, Application::Get()->GetWindow()->GetHeight() - 180));

    player->AddInteractable(box);
}

FrozenRiver::~FrozenRiver()
{
    // Delete objects
    delete camera;
    delete background;
}

void FrozenRiver::Render()
{
    // Render objects
    SDL_Rect cameraRect = camera->ToRect();
    
    background->Render(Vector2(0, 0), &cameraRect);
    player->Render(camera);
    box->Render(camera);
}

void FrozenRiver::Tick(float deltaTime)
{
    player->Tick(deltaTime);
    camera->Update(player);
}

void FrozenRiver::OnEvent(SDL_Event& event)
{
    player->OnEvent(event);
}
