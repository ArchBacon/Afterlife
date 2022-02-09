#include "FrozenRiver.h"

FrozenRiver::FrozenRiver()
{
    // Create objects;
}

FrozenRiver::~FrozenRiver()
{
    // Delete objects
}

void FrozenRiver::Render()
{
    // Render objects
}

void FrozenRiver::OnEvent(const SDL_Event& event)
{
    Level::OnEvent(event);
}

void FrozenRiver::Tick(float deltaTime)
{
    Level::Tick(deltaTime);
}
