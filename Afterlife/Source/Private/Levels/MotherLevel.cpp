#include "Levels/MotherLevel.h"

#include "Conversation.h"
#include "Player.h"
#include "Sprite.h"
#include "LevelLoaders/FrozenRiverLevelLoader.h"

MotherLevel::MotherLevel()
{
    camera = new Camera();
    player = new Player("Assets/v2/Characters/Player.png");
    player->SetLocation(Vector2(730, 201));
    player->Flip();
    
    background = new Sprite("Assets/v2/Levels/Mother.png");
    furniture = new Sprite("Assets/v2/Levels/Mother-overlay.png");

    levelLoader = new FrozenRiverLevelLoader(Vector2(140, 415));
    levelLoader->SetLocation(Vector2(843, 74));

    constexpr Vector2 motherSpeechLoc = Vector2(141, 77);
    constexpr Vector2 grimSpeechLoc = Vector2(659, 15);
    
    conversation = new Conversation(Vector2(120, 220));
    conversation->SetLocation(Vector2(92, 202));
    conversation->Add({"That is your mother.", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"She's a good-for-nothing, you said?", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"Huh?", motherSpeechLoc, SDL_FLIP_NONE});
    conversation->Add({"What?", motherSpeechLoc, SDL_FLIP_NONE});
    conversation->Add({"He's dead?", motherSpeechLoc, SDL_FLIP_NONE});
    conversation->Add({"...", motherSpeechLoc, SDL_FLIP_NONE});
    conversation->Add({"Like i'd know!", motherSpeechLoc, SDL_FLIP_NONE});
    conversation->Add({"I didn't have him because i wanted to!", motherSpeechLoc, SDL_FLIP_NONE});
    conversation->Add({"She truly is a good-for-nothing, it seems.", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
 
    player->AddInteractable(levelLoader);
    player->AddInteractable(conversation);
}

MotherLevel::~MotherLevel()
{
    delete camera;
    delete player;
    
    delete background;
    delete furniture;

    delete conversation;
    delete levelLoader;
}

void MotherLevel::OnEvent(SDL_Event& event)
{
    player->OnEvent(event);
}

void MotherLevel::Tick(float deltaTime)
{
    player->Tick(deltaTime);
    camera->Update();
}

void MotherLevel::Render()
{
    background->Render();
    levelLoader->Render();
    conversation->Render();

    player->Render();

    furniture->Render();

    if (player->IsInConversation())
    {
        conversation->RenderSentence();
    }
}
