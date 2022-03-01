#include "Player.h"

#include "Application.h"
#include "Conversation.h"
#include "Sprite.h"

Player::Player(const std::string& path)
    : Actor(path), renderLocation()
{
    interactTimer.Start();
    interactKey = new Sprite("Assets/Keys/Key_Space.png");
    renderLocation = Vector2(0, 0);
}

Player::~Player()
{
    delete interactKey;
}

void Player::Tick(float deltaTime)
{
    Actor::Tick(deltaTime);
    const Level* level = Application::Get()->GetLevel();

    // Move player when keys are pressed
    const float deltaSpeed = speed * deltaTime;
    const Uint8* keyStates = SDL_GetKeyboardState(nullptr);

    if (keyStates[SDL_SCANCODE_A] == 1 && !listening)
    {
        flip = SDL_FLIP_HORIZONTAL;

        if (location.x - deltaSpeed > 0 + level->GetBorderWidth())
        {
            location.x -= static_cast<int>(deltaSpeed);
        }
    }
    if (keyStates[SDL_SCANCODE_D] == 1 && !listening)
    {
        flip = SDL_FLIP_NONE;

        if (location.x + deltaSpeed < level->GetWidth() - level->GetBorderWidth() - sprite->GetWidth())
        {
            location.x += static_cast<int>(deltaSpeed);
        }
    }

    for (Interactable* interactable : actors.iterator)
    {
        if (IsOverlapping(interactable))
        {
            // Render interact key above interactable
            renderInteractKey = !listening;
            renderLocation = interactable->GetLocation();
            renderLocation.x += interactable->GetWidth() / 2;

            if (keyStates[SDL_SCANCODE_SPACE] == 1)
            {
                if (interactTimer.GetTicks() < 400 || !canInteract)
                {
                    return;
                }

                interactable->Interact();
                canInteract = false;
                interactTimer.Start();

                Conversation* conversation = dynamic_cast<Conversation*>(interactable);
                if (conversation != nullptr)
                {
                    if (listening)
                    {
                        if (conversation->HasNextSentence())
                        {
                            conversation->Next();
                            printf("%s\n", conversation->GetSentence().text.c_str());
                            printf("has next: %hhd\n", conversation->HasNextSentence());
                        }
                        else
                        {
                            printf("Ending conversation.\n");
                            conversation->Reset();
                            listening = false;
                        }

                        return;
                    }

                    printf("Starting conversation\n\n");
                    printf("%s\n", conversation->GetSentence().text.c_str());
                    printf("has next: %hhd\n", conversation->HasNextSentence());
                    listening = true;
                }
            }

            return;
        }

        renderInteractKey = false;
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

    if (renderInteractKey)
    {
        renderLocation = camera == nullptr ? renderLocation : renderLocation - camera->GetLocation();
        renderLocation.x -= interactKey->GetWidth() / 2;
        renderLocation.y -= interactKey->GetHeight();

        interactKey->Render(renderLocation);
    }
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
