#include "Levels/IntroLevel.h"

#include "Application.h"
#include "Player.h"
#include "Sprite.h"
#include "Levels/AfterlifeLevel.h"

IntroLevel::IntroLevel()
{
    size = Vector2(1280, 720);
    border = Vector2(0, 0);
    
    camera = new Camera();
    background = new Sprite("Assets/Intro/intro.png");
}

IntroLevel::~IntroLevel()
{
    delete camera;
    delete background;
}

void IntroLevel::OnEvent(SDL_Event& event)
{
    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_SPACE)
    {
        Application::Get()->LoadLevel(new AfterlifeLevel());
    }
}

void IntroLevel::Tick(float deltaTime)
{
    camera->Update();
}

void IntroLevel::Render()
{
    background->Render();
}
