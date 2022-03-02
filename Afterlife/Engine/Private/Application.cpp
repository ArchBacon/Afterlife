#include "Application.h"

#include "Levels/FrozenRiver.h"

Application* Application::instance = nullptr;

Application::Application()
{
    window = new Window();
    level = nullptr;
    
    running = true;
}

Application::~Application()
{
    delete level;
    delete window;
    delete instance;
}

void Application::LoadLevel(Level* inLevel)
{
    // TODO: fix memory leak, but program crashes
    // delete level;
    level = inLevel;
}

void Application::OnEvent(SDL_Event& event)
{
    if (event.type == SDL_QUIT)
    {
        running = false;
    }

    level->OnEvent(event);
}

void Application::Tick(float deltaTime) const
{
    level->Tick(deltaTime);
}

void Application::Render() const
{
    window->Clear();
    level->Render();
    window->Update();
}

void Application::Quit()
{
    running = false;
}

Application* Application::Get()
{
    if (instance == nullptr)
    {
        instance = new Application();
    }

    return instance;
}
