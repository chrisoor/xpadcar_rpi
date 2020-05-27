#ifndef TIMERSDL2_H
#define TIMERSDL2_H

#include "ITimer.hpp"

namespace xpadcar_rpi
{

class TimerSDL2 : public ITimer
{
public:
    void SetElapsedTime(uint32_t miliSeconds) override;
    bool HasElapsedTimePassed() override;
    bool ResetTimer() override;

private:
    void UpdateTicks();

    uint32_t elapsedTime;
};

}
#endif // TIMERSDL2_H