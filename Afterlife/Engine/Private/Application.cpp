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
}

Application* Application::Get()
{
    if (instance == nullptr)
    {
        instance = new Application();
    }

    return instance;
}
