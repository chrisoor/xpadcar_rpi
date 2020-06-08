#ifndef ITIMER_H
#define ITIMER_H

#include <cstdint>
#include "SDL_gamecontroller.h"
namespace xpadcar_rpi
{

class ITimer
{
public:
    virtual void SetTimeToElapse(uint32_t miliSeconds) = 0;
    virtual bool HasElapsedTimePassed() = 0;
    virtual void ResetTimer() = 0;
    virtual void Wait(uint32_t milisecondsToWait) = 0;
};

}
#endif // ITIMER_H