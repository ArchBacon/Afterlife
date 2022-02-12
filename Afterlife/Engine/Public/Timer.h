#pragma once

#include <SDL_timer.h>

class Timer
{
    Uint32 startTicks = 0;
    Uint32 pausedTicks = 0;

    bool started = false;
    bool paused = false;
    
public:
    void Start();
    void Stop();
    void Pause();
    void Unpause();

    Uint32 GetTicks() const;

    bool IsStarted() const { return started; }
    bool IsPaused() const { return started && paused; }
};
