#include "Levels/CatMemoryLevel.h"

CatMemoryLevel::CatMemoryLevel()
{
    camera = new Camera();
    background = new Actor("Assets/Memories/cat.png");
}

CatMemoryLevel::~CatMemoryLevel()
{
    delete camera;
    delete background;
}

void CatMemoryLevel::OnEvent(SDL_Event& event)
{
}

void CatMemoryLevel::Tick(float deltaTime)
{
    camera->Update(background);
}

void CatMemoryLevel::Render()
{
    background->Render(camera);
}
