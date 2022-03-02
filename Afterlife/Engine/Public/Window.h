#pragma once

#include <SDL_render.h>
#include <SDL_video.h>
#include <string>

struct WindowProperties
{
    std::string title = "Of a life without regret.";
    int width = 1280;
    int height = 720;
};

class Window
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    WindowProperties properties;

public:
    Window(WindowProperties properties = WindowProperties());
    ~Window();

    void Clear() const;
    void Update() const;

    SDL_Window* GetWindow() const { return window; }
    SDL_Renderer* GetRenderer() const { return renderer; }
    int GetWidth() const { return properties.width; }
    int GetHeight() const { return properties.height; }
};