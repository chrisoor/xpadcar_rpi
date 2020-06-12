#ifndef TIMERSDL2_H
#define TIMERSDL2_H

#include "TimerInterface.hpp"
#include "SDL_timer.h"

namespace xpadcar_rpi
{

class TimerSDL2 : public TimerInterface
{
public:
    TimerSDL2();
    void SetTimeToElapse(uint32_t miliSeconds) override;
    bool HasElapsedTimePassed() override;
    void ResetTimer() override;
    void Wait(uint32_t milisecondsToWait) override;

private:
    uint32_t timeStamp;
    uint32_t miliSecondsToElapse;
};

}
#endif // TIMERSDL2_H