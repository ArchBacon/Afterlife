#include <SDL_events.h>

#include "Application.h"
#include "FrozenRiver.h"

constexpr int SCREEN_FPS = 60;
constexpr int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

Application* app = Application::Get();
SDL_Event event;

LTimer fpsTimer;
LTimer capTimer;

int main(int argc, char** argv)
{
    capTimer.start();

    app->LoadLevel(new FrozenRiver());

    while (app->IsRunning())
    {
        capTimer.start();

        while (SDL_PollEvent(&event) != 0)
        {
            app->OnEvent(event);
        }

        const float deltaTime = fpsTimer.getTicks() / 1000.f;
        fpsTimer.start();

        app->Tick(deltaTime);
        app->Render();

        int frameTicks = capTimer.getTicks();
        if (frameTicks < SCREEN_TICK_PER_FRAME)
        {
            SDL_Delay(SCREEN_TICK_PER_FRAME - frameTicks);
        }
    }

    delete app;

    return 0;
}
