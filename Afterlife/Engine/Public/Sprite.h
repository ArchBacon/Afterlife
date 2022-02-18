#pragma once

#include <SDL_render.h>
#include <string>

#include "Utils.h"

class Sprite final
{
    SDL_Texture* sprite;
    Vector2 size;
    
public:
    Sprite(std::string path, bool text = false);
    ~Sprite();

    void Render(Vector2 location = Vector2(0, 0), SDL_Rect* clip = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE) const;
    
    int GetWidth() const { return size.x; }
    int GetHeight() const { return size.y; }
};
