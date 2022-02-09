#include <SDL_events.h>

#include "Application.h"
#include "FrozenRiver.h"

Application* app = Application::Get();
SDL_Event event;

int main(int argc, char** argv)
{
    app->LoadLevel(new FrozenRiver());
    
    while (app->IsRunning())
    {
        while (SDL_PollEvent(&event) != 0)
        {
            app->OnEvent(event);
        }

        app->Tick(0.01f);
        app->Render();
    }

    delete app;
    
    return 0;
}
