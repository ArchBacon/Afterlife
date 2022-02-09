#include "Application.h"

Application* app = Application::Get();

int main(int argc, char** argv)
{
    while (app->IsRunning())
    {
    }

    delete app;
    
    return 0;
}
