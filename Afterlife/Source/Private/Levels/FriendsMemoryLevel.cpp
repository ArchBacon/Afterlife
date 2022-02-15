#include "Levels/FriendsMemoryLevel.h"

FriendsMemoryLevel::FriendsMemoryLevel()
{
    camera = new Camera();
    background = new Actor("Assets/Memories/friends.png");
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
