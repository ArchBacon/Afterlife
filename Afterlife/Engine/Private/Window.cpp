#include "Window.h"

#include <SDL.h>
#include <SDL_image.h>

Window::Window(WindowProperties properties)
    : properties(properties)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    IMG_Init(IMG_INIT_PNG);

    window = SDL_CreateWindow(properties.title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, properties.width, properties.height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();
}

void Window::Clear() const
{
    SDL_RenderClear(renderer);
}

void Window::Update() const
{
    SDL_RenderPresent(renderer);
}
