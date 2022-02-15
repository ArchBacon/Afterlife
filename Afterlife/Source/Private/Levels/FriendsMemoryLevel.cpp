#include "Levels/FriendsMemoryLevel.h"

FriendsMemoryLevel::FriendsMemoryLevel()
{
    camera = new Camera();
    background = new Actor("Assets/Cafe/background.png");

    size = Vector2(1280, 720);
}

FriendsMemoryLevel::~FriendsMemoryLevel()
{
    delete camera;
    delete background;
}

void FriendsMemoryLevel::OnEvent(SDL_Event& event)
{
}

void FriendsMemoryLevel::Tick(float deltaTime)
{
    camera->Update(background);
}

void FriendsMemoryLevel::Render()
{
    background->Render(camera);
}
