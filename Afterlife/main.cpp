#include <SDL_events.h>

#include "Application.h"

Application* app = Application::Get();
SDL_Event event;

int main(int argc, char** argv)
{
    while (app->IsRunning())
    {
        while (SDL_PollEvent(&event) != 0)
        {
            // Handle events
            app->OnEvent(event);
        }

        // TODO: Tick

        // TODO: Render
    }

    delete app;
    
    return 0;
}
