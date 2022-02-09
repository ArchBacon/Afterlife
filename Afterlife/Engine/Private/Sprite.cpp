#include "Sprite.h"

#include <SDL_image.h>

#include "Application.h"

Sprite::Sprite(std::string path)
{
    SDL_Surface* surface = IMG_Load(path.c_str());
    size = Vector2(surface->w, surface->h);
    sprite = SDL_CreateTextureFromSurface(Application::Get()->GetRenderer(), surface);

    SDL_FreeSurface(surface);
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(sprite);
}

void Sprite::Render(Vector2 location)
{
    SDL_Rect renderQuad = { location.x, location.y, size.x, size.y };

    SDL_RenderCopy(Application::Get()->GetRenderer(), sprite, nullptr, nullptr);
    // SDL_RenderCopyEx(Application::Get()->GetWindow()->GetRenderer(), sprite, nullptr, &renderQuad, 0.f, nullptr, SDL_FLIP_NONE);
}
