#include <SDL_events.h>

#include "Application.h"
#include "Timer.h"
#include "Levels/IntroLevel.h"

/** Target framerate */
constexpr int SCREEN_FPS = 60;
constexpr int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

Application* app = Application::Get();
SDL_Event event;

Timer fpsTimer;
Timer capTimer;

int main(int argc, char** argv)
{
    app->LoadLevel(new IntroLevel());
    capTimer.Start();

    while (app->IsRunning())
    {
        capTimer.Start();

        /** Handle events if there are any */
        while (SDL_PollEvent(&event) != 0)
        {
            app->OnEvent(event);
        }

        const float deltaTime = fpsTimer.GetTicks() / 1000.f;
        fpsTimer.Start();

        app->Tick(deltaTime);
        app->Render();

        /**
         * If current framerate is higher then target framerate, delay until average frame time is met
         */
        const int frameTicks = capTimer.GetTicks();
        if (frameTicks < SCREEN_TICK_PER_FRAME)
        {
            SDL_Delay(SCREEN_TICK_PER_FRAME - frameTicks);
        }
    }

    delete app;

    return 0;
}
