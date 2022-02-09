#include "Player.h"

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
}

void Player::OnEvent(SDL_Event& event)
{
    Actor::OnEvent(event);
}

void Player::Render()
{
    Actor::Render();
}
