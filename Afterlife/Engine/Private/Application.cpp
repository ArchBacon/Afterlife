#include "Application.h"

Application* Application::instance = nullptr;

Application::Application()
{
    window = new Window();
    
    running = true;
}

Application::~Application()
{
    delete instance;
    delete window;
}

void Application::OnEvent(const SDL_Event& event)
{
    if (event.type == SDL_QUIT)
    {
        running = false;
    }
}

Application* Application::Get()
{
    if (instance == nullptr)
    {
        instance = new Application();
    }

    return instance;
}
