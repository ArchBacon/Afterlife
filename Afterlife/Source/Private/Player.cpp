#include "Player.h"

#include "Sprite.h"

Player::Player(const std::string& path)
    : Actor(path)
{
    interactTimer.Start();
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
    
    for (const Interactable* interactable : actors.iterator)
    {
        if (IsOverlapping(interactable) && keyStates[SDL_SCANCODE_SPACE] == 1)
        {
            if (interactTimer.GetTicks() < 400 || !canInteract)
            {
                return;
            }

            interactable->Interact();
            canInteract = false;
            interactTimer.Start();
        }
    }
}

void Player::OnEvent(SDL_Event& event)
{
    Actor::OnEvent(event);

    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_SPACE)
    {
        canInteract = true;
    }
}

void Player::Render(Camera* camera)
{
    Actor::Render(camera);
}

void Player::AddInteractable(Interactable* interactable)
{
    actors.AddUnique(interactable);
}

bool Player::IsOverlapping(const Interactable* interactable) const
{
    const SDL_Rect other = interactable->GetCollider();

    return !(other.y + other.h <= collider.y
        || other.y >= collider.y + collider.h
        || other.x + other.w <= collider.x
        || other.x >= collider.x + collider.w);
}
