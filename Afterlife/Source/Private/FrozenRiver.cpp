#include "FrozenRiver.h"
#include "Application.h"
#include "Player.h"

FrozenRiver::FrozenRiver()
{
    // Create objects
    background = new Sprite("Assets/Memories/background.png");
    player = new Player("Assets/Memories/player_cube.png");
    player->SetLocation(Vector2(640, 550));

    box = new Actor("Assets/Keys/Key_A.png");
    box->SetLocation(Vector2(1000, 550));

    player->AddActorForOverlap(box);
}

FrozenRiver::~FrozenRiver()
{
    // Delete objects
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
