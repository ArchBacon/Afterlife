#pragma once

#include <SDL_events.h>

#include "Window.h"

class Application
{
    static Application* instance;

    Window* window;
    bool running = false;

    Application();

public:
    static Application* Get();
    ~Application();

    void OnEvent(const SDL_Event& event);

    bool IsRunning() const { return running; };
    Window* GetWindow() const { return window; };
    SDL_Renderer* GetRenderer() const { return window->GetRenderer(); };
};
