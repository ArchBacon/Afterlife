#include "Sprite.h"

#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Application.h"

Sprite::Sprite(std::string path, bool text)
{
    SDL_Surface* image;

    if (text)
    {
        TTF_Font* font = TTF_OpenFont("Assets/Fonts/Roboto.ttf", 20);
        image = TTF_RenderText_Solid_Wrapped(font, path.c_str(), {0, 0, 0}, 220);
    }
    else
    {
        image = IMG_Load(path.c_str());
        if (image == nullptr)
        {
        #ifdef _DEBUG
            printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        #endif
        }
    }

    size = Vector2(image->w, image->h);
    sprite = SDL_CreateTextureFromSurface(Application::Get()->GetRenderer(), image);

    SDL_FreeSurface(image);
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(sprite);
}

void Sprite::Render(Vector2 location, SDL_Rect* clip, SDL_RendererFlip flip) const
{
    SDL_Rect renderQuad = {location.x, location.y, size.x, size.y};

    if (clip != nullptr)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    SDL_RenderCopyEx(Application::Get()->GetWindow()->GetRenderer(), sprite, clip, &renderQuad, 0.f, nullptr, flip);
}
