#ifndef TIMERINTERFACE_HPP
#define TIMERINTERFACE_HPP

#include <cstdint>
namespace xpadcar_rpi
{

class TimerInterface
{
public:
    virtual ~TimerInterface() = default;
    virtual void SetTimeToElapse(uint32_t miliSeconds) = 0;
    virtual bool HasElapsedTimePassed() = 0;
    virtual void ResetTimer() = 0;
    virtual void Wait(uint32_t milisecondsToWait) = 0;
};

}
#endif // TIMERINTERFACE_HPP