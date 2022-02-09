#pragma once

#include <SDL_render.h>
#include <string>

#include "Utils.h"

class Sprite final
{
    SDL_Texture* sprite;
    Vector2 size;
    
public:
    Sprite(std::string path);
    ~Sprite();

    void Render(Vector2 location) const;
    
    int GetWidth() const { return size.x; }
    int GetHeight() const { return size.y; }
};