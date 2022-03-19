#include "Levels/FrozenRiver.h"

#include "Application.h"
#include "Player.h"
#include "LevelLoaders/CatLevelLoader.h"
#include "Sprite.h"
#include "LevelLoaders/ConversationLevelLoader.h"
#include "LevelLoaders/CoworkersLevelLoader.h"
#include "LevelLoaders/FriendsLevelLoader.h"
#include "LevelLoaders/MotherLevelLoader.h"

FrozenRiver::FrozenRiver()
{
    /** Configure size of the level */
    size = Vector2(3840, 720);
    /** Configure how far from the edge of the level the player is allowed to move */
    border = Vector2(640, 0);
    
    camera = new Camera();
    player = new Player("Assets/v2/Characters/Boat.png");
    player->SetLocation(Vector2(640, 550));

    levelLoaderCoworker = new CoworkersLevelLoader(Vector2(125, 125));
    levelLoaderCoworker->SetLocation(Vector2(930, 500));

    levelLoaderFriends = new FriendsLevelLoader(Vector2(125, 125));
    levelLoaderFriends->SetLocation(Vector2(1410, 500));

    levelLoaderMother = new MotherLevelLoader(Vector2(125, 125));
    levelLoaderMother->SetLocation(Vector2(1920, 500));

    levelLoaderCat = new CatLevelLoader(Vector2(125, 125));
    levelLoaderCat->SetLocation(Vector2(2410, 500));

    levelLoaderConversation = new ConversationLevelLoader(Vector2(170, 125));
    levelLoaderConversation->SetLocation(Vector2(2690 + 210, 500));

    // Create sprites
    background = new Sprite("Assets/v2/Levels/FrozenRiver.png");

    // Config
    player->AddInteractable(levelLoaderCoworker);
    player->AddInteractable(levelLoaderFriends);
    player->AddInteractable(levelLoaderMother);
    player->AddInteractable(levelLoaderCat);
    player->AddInteractable(levelLoaderConversation);
}

FrozenRiver::~FrozenRiver()
{
    // Delete objects
    delete camera;
    delete background;

    delete levelLoaderCoworker;
    delete levelLoaderFriends;
    delete levelLoaderMother;
    delete levelLoaderCat;
    delete levelLoaderConversation;
}

void FrozenRiver::Render()
{
    // Render objects
    SDL_Rect cameraRect = camera->ToRect();

    background->Render(Vector2(0, 0), &cameraRect);
    player->Render(camera);

    levelLoaderCoworker->Render(camera);
    levelLoaderFriends->Render(camera);
    levelLoaderMother->Render(camera);
    levelLoaderCat->Render(camera);
    levelLoaderConversation->Render(camera);
}

void FrozenRiver::Tick(float deltaTime)
{
    player->Tick(deltaTime);
    camera->Update(player);
}

void FrozenRiver::OnEvent(SDL_Event& event)
{
    player->OnEvent(event);
}
