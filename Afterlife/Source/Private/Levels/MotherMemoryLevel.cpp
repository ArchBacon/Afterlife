#include "Levels/MotherMemoryLevel.h"

MotherMemoryLevel::MotherMemoryLevel()
{
    camera = new Camera();
    background = new Actor("Assets/House/background.png");
    size = Vector2(2166, 720);
}

MotherMemoryLevel::~MotherMemoryLevel()
{
    delete camera;
    delete background;
}

void MotherMemoryLevel::OnEvent(SDL_Event& event)
{
}

void MotherMemoryLevel::Tick(float deltaTime)
{
    camera->Update(background);
}

void MotherMemoryLevel::Render()
{
    background->Render(camera);
}
