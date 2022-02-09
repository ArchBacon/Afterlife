#pragma once

#include <SDL_events.h>

#include "Level.h"
#include "Window.h"

class Application
{
    static Application* instance;

    Window* window;
    Level* level;
    
    bool running = false;

    Application();

public:
    static Application* Get();
    ~Application();

    void LoadLevel(Level* level);
    Level* GetLevel() const { return level; }

    void OnEvent(SDL_Event& event);
    void Tick(float deltaTime) const;
    void Render() const;

    bool IsRunning() const { return running; };
    Window* GetWindow() const { return window; };
    SDL_Renderer* GetRenderer() const { return window->GetRenderer(); };
};
