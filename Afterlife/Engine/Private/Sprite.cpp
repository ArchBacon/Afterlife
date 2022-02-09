#include "Sprite.h"

#include <SDL_image.h>

#include "Application.h"
#include "Camera.h"

Sprite::Sprite(std::string path)
{
    SDL_Surface* image = IMG_Load(path.c_str());
    if (image == nullptr)
    {
        printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
    }
    
    size = Vector2(image->w, image->h);
    sprite = SDL_CreateTextureFromSurface(Application::Get()->GetRenderer(), image);

    SDL_FreeSurface(image);
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
