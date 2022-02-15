#include "Levels/FrozenRiver.h"

#include "Application.h"
#include "Player.h"
#include "LevelLoaders/CatMemoryLevelLoader.h"
#include "Sprite.h"
#include "LevelLoaders/CoworkersMemoryLevelLoader.h"
#include "LevelLoaders/FriendsMemoryLevelLoader.h"
#include "LevelLoaders/MotherMemoryLevelLoader.h"

FrozenRiver::FrozenRiver()
{
    // Create objects
    camera = new Camera();

    player = new Player("Assets/Memories/boat.png");
    player->SetLocation(Vector2(640, 550));

    levelLoaderCoworker = new CoworkersMemoryLevelLoader(Vector2(125, 125));
    levelLoaderCoworker->SetLocation(Vector2(720 + (125/2), 540));

    levelLoaderFriends = new FriendsMemoryLevelLoader(Vector2(125, 125));
    levelLoaderFriends->SetLocation(Vector2(1250 + (125/2), 540));

    levelLoaderMother = new MotherMemoryLevelLoader(Vector2(125, 125));
    levelLoaderMother->SetLocation(Vector2(1730 + (125/2), 540));

    levelLoaderCat = new CatMemoryLevelLoader(Vector2(125, 125));
    levelLoaderCat->SetLocation(Vector2(2210 + (125/2), 540));

    // Create sprites
    background = new Sprite("Assets/Memories/background.png");
    coworkers = new Sprite("Assets/Memories/coworkers.png");
    friends = new Sprite("Assets/Memories/friends.png");
    mother = new Sprite("Assets/Memories/mother.png");
    cat = new Sprite("Assets/Memories/cat.png");
    portal = new Sprite("Assets/Memories/portal.png");
    
    player->AddInteractable(levelLoaderCoworker);
    player->AddInteractable(levelLoaderFriends);
    player->AddInteractable(levelLoaderMother);
    player->AddInteractable(levelLoaderCat);
}

FrozenRiver::~FrozenRiver()
{
    // Delete objects
    delete camera;
    delete background;
    delete coworkers;
    delete friends;
    delete mother;
    delete cat;
    delete portal;
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

    coworkers->Render(Vector2(720, 250) - camera->GetLocation());
    portal->Render(Vector2(720, 250) - camera->GetLocation());

    friends->Render(Vector2(1250, 250) - camera->GetLocation());
    portal->Render(Vector2(1250, 250) - camera->GetLocation());

    mother->Render(Vector2(1730, 250) - camera->GetLocation());
    portal->Render(Vector2(1730, 250) - camera->GetLocation());

    cat->Render(Vector2(2210, 250) - camera->GetLocation());
    portal->Render(Vector2(2210, 250) - camera->GetLocation());
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