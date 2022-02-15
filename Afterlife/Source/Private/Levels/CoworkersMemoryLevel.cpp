#include "Levels/CoworkersMemoryLevel.h"

CoworkersMemoryLevel::CoworkersMemoryLevel()
{
    camera = new Camera();
    background = new Actor("Assets/Memories/coworkers.png");
}

CoworkersMemoryLevel::~CoworkersMemoryLevel()
{
    delete camera;
    delete background;
}

void CoworkersMemoryLevel::OnEvent(SDL_Event& event)
{
}

void CoworkersMemoryLevel::Tick(float deltaTime)
{
    camera->Update(background);
}

void CoworkersMemoryLevel::Render()
{
    background->Render(camera);
}
