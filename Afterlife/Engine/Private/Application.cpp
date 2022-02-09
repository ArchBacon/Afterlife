#include "Application.h"

Application* Application::instance = nullptr;

Application::Application()
{
    window = new Window();
    level = nullptr;
    
    running = true;
}

Application::~Application()
{
    delete instance;
    delete window;
    delete level;
}

void Application::LoadLevel(Level* inLevel)
{
    delete level;
    level = inLevel;
}

void Application::OnEvent(const SDL_Event& event)
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
    level->Render();
}

Application* Application::Get()
{
    if (instance == nullptr)
    {
        instance = new Application();
    }

    return instance;
}
