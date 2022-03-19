#include "Levels/IntroLevel.h"

#include "Application.h"
#include "Player.h"
#include "Sprite.h"
#include "Levels/AfterlifeLevel.h"

IntroLevel::IntroLevel()
{
    camera = new Camera();
    background = new Sprite("Assets/Levels/Intro.png");
}

IntroLevel::~IntroLevel()
{
    delete camera;
    delete background;
}

void IntroLevel::OnEvent(SDL_Event& event)
{
    /** Load level if the [Space] key is in the [Pressed] state */
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
