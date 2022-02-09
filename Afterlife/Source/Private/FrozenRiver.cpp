#include "FrozenRiver.h"

FrozenRiver::FrozenRiver()
{
    // Create objects
    background = new Sprite("Assets/background.png");
}

FrozenRiver::~FrozenRiver()
{
    // Delete objects
    delete background;
}

void FrozenRiver::Render()
{
    // Render objects
    background->Render(Vector2(0, 0));
}
