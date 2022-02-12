#include "Player.h"

#include "Sprite.h"

Player::Player(const std::string& path)
    : Actor(path)
{
}

Player::~Player()
{
}

void Player::Tick(float deltaTime)
{
    Actor::Tick(deltaTime);

    // Move player when keys are pressed
    const float deltaSpeed = speed * deltaTime;
    const Uint8* keyStates = SDL_GetKeyboardState(nullptr);

    if (keyStates[SDL_SCANCODE_A] == 1)
    {
        if (location.x - deltaSpeed > 0 + 640)
        {
            location.x -= static_cast<int>(deltaSpeed);
        }
    }
    if (keyStates[SDL_SCANCODE_D] == 1)
    {
        if (location.x + deltaSpeed < 3200 - 640 - sprite->GetWidth())
        {
            location.x += static_cast<int>(deltaSpeed);
        }
    }
}

void Player::OnEvent(SDL_Event& event)
{
    Actor::OnEvent(event);
}

void Player::Render(Camera* camera)
{
    Actor::Render(camera);
}
