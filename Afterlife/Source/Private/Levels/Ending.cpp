#include "Levels/Ending.h"

#include "Conversation.h"
#include "Sprite.h"
#include "LevelLoaders/FrozenRiverLevelLoader.h"

Ending::Ending()
{
    size = Vector2(1280, 720);
    border = Vector2(0, 0);
    
    camera = new Camera();
    
    background = new Sprite("Assets/ending/end.png");
}

Ending::~Ending()
{
    delete camera;
    delete background;
}

void Ending::OnEvent(SDL_Event& event)
{
    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_SPACE)
    {
        Application::Get()->Quit();
    }
}

void Ending::Tick(float deltaTime)
{
    camera->Update();
}

void Ending::Render()
{
    background->Render();
}
