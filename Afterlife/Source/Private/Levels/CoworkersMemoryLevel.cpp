#include "Levels/CoworkersMemoryLevel.h"

#include "Sprite.h"

CoworkersMemoryLevel::CoworkersMemoryLevel()
{
    camera = new Camera();
    
    player = new Player("Assets/ghost.png");
    player->SetLocation(Vector2(640, 550));
    
    background = new Sprite("Assets/Office/background.png");
    size = Vector2(3338, 720);
}

CoworkersMemoryLevel::~CoworkersMemoryLevel()
{
    delete camera;
    delete background;
    delete player;
}

void CoworkersMemoryLevel::OnEvent(SDL_Event& event)
{
    player->OnEvent(event);
}

void CoworkersMemoryLevel::Tick(float deltaTime)
{
    player->Tick(deltaTime);
    camera->Update(player);
}

void CoworkersMemoryLevel::Render()
{
    SDL_Rect cameraRect = camera->ToRect();
    
    background->Render(Vector2(0, 0), &cameraRect);
    player->Render(camera);
}
