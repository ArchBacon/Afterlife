#include "Timer.h"

void Timer::Start()
{
    started = true;
    paused = false;

    startTicks = SDL_GetTicks();
    pausedTicks = 0;
}

void Timer::Stop()
{
    started = false;
    paused = false;

    startTicks = 0;
    pausedTicks = 0;
}

void Timer::Pause()
{
    if (started && !paused)
    {
        paused = false;

        startTicks = 0;
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void Timer::Unpause()
{
    if (started && paused)
    {
        paused = false;
        startTicks = SDL_GetTicks() - pausedTicks;
        pausedTicks = 0;
    }
}

Uint32 Timer::GetTicks() const
{
    Uint32 time = 0;

    if (started)
    {
        time = paused
        ? pausedTicks
        : SDL_GetTicks() - startTicks;
    }

    return time;
}
