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
    const float deltaSpeed = MovementSpeed * deltaTime;
    const Uint8* keyStates = SDL_GetKeyboardState(nullptr);

    /**
     * Move left if the [A] key is in the [Pressed] state
     * and the player is not listening to an conversation
     */
    if (keyStates[SDL_SCANCODE_A] == 1 && !listening)
    {
        flip = SDL_FLIP_HORIZONTAL;

        if (location.x - deltaSpeed > 0 + level->GetBorderWidth())
        {
            location.x -= static_cast<int>(deltaSpeed);
        }
    }
    /**
     * Move right if the [D] key is in the [Pressed] state
     * and the player is not listening to an conversation
     */
    if (keyStates[SDL_SCANCODE_D] == 1 && !listening)
    {
        flip = SDL_FLIP_NONE;

        if (location.x + deltaSpeed < level->GetWidth() - level->GetBorderWidth() - sprite->GetWidth())
        {
            location.x += static_cast<int>(deltaSpeed);
        }
    }

    /**
     * Loop over the added objects that the player can interact with
     */
    for (Interactable* interactable : actors.iterator)
    {
        if (IsOverlapping(interactable))
        {
            /** Render interact key above interactable */
            renderInteractKey = !listening;
            renderLocation = interactable->GetLocation();
            renderLocation.x += interactable->GetWidth() / 2;

            /** Check if [Space] in in the [Pressed] state */
            if (keyStates[SDL_SCANCODE_SPACE] == 1)
            {
                /**
                 * If the [Interact] key ([Space]) has been pressed again within 400 milliseconds
                 * or the player is in a state where it is not allowed to interact, negate the input
                 */
                if (interactTimer.GetTicks() < 400 || !canInteract)
                {
                    return;
                }

                interactable->Interact();
                canInteract = false;
                interactTimer.Start();

                /**
                 * If the [Interactable] is of type [Conversation], Get the next sentence
                 * or end the conversation if there are no more sentences left
                 */
                Conversation* conversation = dynamic_cast<Conversation*>(interactable);
                if (conversation != nullptr)
                {
                    /**
                     * If the player has already started listening to a conversation,
                     * get the next sentence, otherwise set the state to [Listening]
                     */
                    if (listening)
                    {
                        if (conversation->HasNextSentence())
                        {
                            conversation->Next();
                        #ifdef _DEBUG
                            printf("%s\n", conversation->GetSentence().text.c_str());
                            printf("has next: %hhd\n", conversation->HasNextSentence());
                        #endif
                        }
                        else
                        {
                        #ifdef _DEBUG
                            printf("Ending conversation.\n");
                        #endif
                            conversation->EndConversation();
                            conversation->Reset();
                            listening = false;
                        }

                        return;
                    }
                    
                #ifdef _DEBUG
                    printf("Starting conversation\n\n");
                    printf("%s\n", conversation->GetSentence().text.c_str());
                    printf("has next: %hhd\n", conversation->HasNextSentence());
                #endif
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


    /**
     * Allow the player to interact again after releasing the [Space] key.
     * This is to prevent looping through the converation by holding the [Interact] key 
     **/
    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_SPACE)
    {
        canInteract = true;
    }
}

void Player::Render(Camera* camera)
{
    Actor::Render(camera);

    /** Render the [Interact] key center top of the interactable hitbox */
    if (renderInteractKey)
    {
        renderLocation = camera == nullptr ? renderLocation : renderLocation - camera->GetLocation();
        renderLocation.x -= interactKey->GetWidth() / 2;
        renderLocation.y -= (int)(interactKey->GetHeight() * 1.5);

        interactKey->Render(renderLocation);
    }
}

void Player::AddInteractable(Interactable* interactable)
{
    actors.AddUnique(interactable);
}

/**
 * Check if the player's hitbox and the hitbox of the interactble are overlapping
 * @see https://lazyfoo.net/tutorials/SDL/27_collision_detection/index.php
 */
bool Player::IsOverlapping(const Interactable* interactable) const
{
    const SDL_Rect other = interactable->GetCollider();

    return !(other.y + other.h <= collider.y
        || other.y >= collider.y + collider.h
        || other.x + other.w <= collider.x
        || other.x >= collider.x + collider.w);
}
