#include "Levels/AfterlifeLevel.h"

#include "Conversation.h"
#include "Sprite.h"
#include "LevelLoaders/FrozenRiverLevelLoader.h"

AfterlifeLevel::AfterlifeLevel()
{
    camera = new Camera();
    player = new Player("Assets/Characters/Player.png");
    player->SetLocation(Vector2(286, 427));

    background = new Sprite("Assets/Levels/Afterlife.png");
    portal = new Sprite("Assets/Levels/Afterlife-overlay.png");

    levelLoader = new FrozenRiverLevelLoader("Afterlife", Vector2(186, 302));
    levelLoader->SetLocation(Vector2(803, 377));

    constexpr Vector2 grimSpeechLoc = Vector2(368, 172);
    constexpr Vector2 playerSpeechLoc = Vector2(0, 282);
    
    conversation = new Conversation(Vector2(199, 415), player);
    conversation->SetLocation(Vector2(535, 259));
    conversation->Add({"Congratulations!", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"You are the millionth person to have died within this area!", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"For that, I shall grant you a single wish!", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"What shall it be?", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"Resurrection?", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"A chance to redo your life?", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"Now!!", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"What is your wish!?", grimSpeechLoc, SDL_FLIP_HORIZONTAL});
    conversation->Add({"Um...", playerSpeechLoc, SDL_FLIP_NONE, true});
    conversation->Add({"Ah...", playerSpeechLoc, SDL_FLIP_NONE, true});
    conversation->Add({"Then-", playerSpeechLoc, SDL_FLIP_NONE, true});
    conversation->Add({"I want to see how everyone's been doing.", playerSpeechLoc, SDL_FLIP_NONE, true});
    conversation->Add({"What?", grimSpeechLoc, SDL_FLIP_HORIZONTAL});

    player->AddInteractable(levelLoader);
    player->AddInteractable(conversation);
}

AfterlifeLevel::~AfterlifeLevel()
{
    delete camera;
    delete player;

    delete background;
    delete portal;

    delete conversation;
    delete levelLoader;
}

void AfterlifeLevel::OnEvent(SDL_Event& event)
{
    player->OnEvent(event);
}

void AfterlifeLevel::Tick(float deltaTime)
{
    player->Tick(deltaTime);
    camera->Update();
}

void AfterlifeLevel::Render()
{
    background->Render();

    if (conversation->HasEnded())
    {
        portal->Render();
        levelLoader->Render();
    }

    conversation->Render();

    player->Render();

    if (player->IsInConversation())
    {
        conversation->RenderSentence();
    }
}
