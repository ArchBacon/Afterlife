#include "Sprite.h"

#include <SDL_image.h>

#include "Application.h"
#include "Camera.h"

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

void Sprite::Render(Vector2 location) const
{
    Camera* camera = Application::Get()->GetLevel()->GetCamera();
    SDL_Rect renderQuad = {location.x, location.y, size.x, size.y};
    SDL_Rect cameraRect = renderQuad;

    if (camera != nullptr)
    {
        renderQuad.w = camera->GetWidth();
        renderQuad.h = camera->GetHeight();

        cameraRect = camera->ToRect();
    }

    SDL_RenderCopyEx(Application::Get()->GetWindow()->GetRenderer(), sprite, &cameraRect, &renderQuad, 0.f, nullptr, SDL_FLIP_NONE);
}
