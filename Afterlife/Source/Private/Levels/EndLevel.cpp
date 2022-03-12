#include "Levels/EndLevel.h"

#include <SDL.h>

#include "Conversation.h"
#include "Sprite.h"
#include "LevelLoaders/FrozenRiverLevelLoader.h"

EndLevel::EndLevel()
{
    size = Vector2(1280, 720);
    border = Vector2(0, 0);
    
    camera = new Camera();
    
    background = new Sprite("Assets/v2/Levels/End.png");
}

EndLevel::~EndLevel()
{
    delete camera;
    delete background;
}

void EndLevel::OnEvent(SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
    {
        Application::Get()->Quit();
    }
}

void EndLevel::Tick(float deltaTime)
{
    camera->Update();
}

void EndLevel::Render()
{
    background->Render();
}