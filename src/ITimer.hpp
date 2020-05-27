#ifndef ITIMER_H
#define ITIMER_H

#include <cstdint>
#include "SDL_gamecontroller.h"
namespace xpadcar_rpi
{

class ITimer
{
public:
    virtual void SetElapsedTime(uint32_t miliSeconds) = 0;
    virtual bool HasElapsedTimePassed() = 0;
    virtual bool ResetTimer() = 0;
};

}
#endif // ITIMER_H