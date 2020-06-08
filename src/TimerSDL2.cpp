#include "TimerSDL2.hpp"

namespace xpadcar_rpi
{

TimerSDL2::TimerSDL2()
{
    ResetTimer();
}

void TimerSDL2::SetTimeToElapse(uint32_t miliSeconds) 
{
    miliSecondsToElapse = miliSeconds;
}

bool TimerSDL2::HasElapsedTimePassed() 
{
    bool result {false};

    if ( SDL_TICKS_PASSED(SDL_GetTicks(), timeStamp + miliSecondsToElapse))
    {
        result = true;
    }

    return result;
}

void TimerSDL2::ResetTimer()
{
    timeStamp = SDL_GetTicks();
}

void TimerSDL2::Wait(uint32_t milisecondsToWait)
{
    SDL_Delay(milisecondsToWait);
}

}
