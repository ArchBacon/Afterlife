#include "Levels/EndingLevel.h"

#include "Conversation.h"
#include "Sprite.h"
#include "LevelLoaders/FrozenRiverLevelLoader.h"

EndingLevel::EndingLevel()
{
    size = Vector2(1280, 720);
    border = Vector2(0, 0);
    
    camera = new Camera();
    
    background = new Sprite("Assets/ending/end.png");
}

EndingLevel::~EndingLevel()
{
    delete camera;
    delete background;
}

void EndingLevel::OnEvent(SDL_Event& event)
{
}

void EndingLevel::Tick(float deltaTime)
{
    camera->Update();
}

void EndingLevel::Render()
{
    background->Render();
}
