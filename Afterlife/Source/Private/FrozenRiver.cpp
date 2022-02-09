#include "FrozenRiver.h"

#include "Application.h"

FrozenRiver::FrozenRiver()
{
    // Create objects
    background = new Sprite("Assets/Memories/background.png");
    boat = new Actor("Assets/Memories/boat.png");
    boat->SetLocation(Vector2(200, 200));
    
    camera = {
        0,
        0,
        (boat->GetWorldLocation().x + boat->GetSprite()->GetWidth() / 2) - Application::Get()->GetWindow()->GetWidth() / 2,
        (boat->GetWorldLocation().y + boat->GetSprite()->GetHeight() / 2) - Application::Get()->GetWindow()->GetHeight() / 2,
    };
}

FrozenRiver::~FrozenRiver()
{
    // Delete objects
    delete background;
    delete boat;
}

void FrozenRiver::Render()
{
    // Render objects
    background->Render(Vector2(0, 0));
    boat->Render();
}
