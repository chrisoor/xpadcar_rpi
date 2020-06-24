#ifndef BUTTONSAXISSTATUS_HPP
#define BUTTONSAXISSTATUS_HPP

#include <cstdint>

namespace xpadcar_rpi
{

struct ButtonsAxisStatus
{
    int32_t rightTrigger = 0;
    int32_t leftTrigger = 0;

    int32_t leftStickUp = 0;
    int32_t leftStickDown = 0;
    int32_t leftStickRight = 0;
    int32_t leftStickLeft = 0;

    int32_t rightStickUp = 0;
    int32_t rightStickDown = 0;
    int32_t rightStickRight = 0;
    int32_t rightStickLeft = 0;

    bool keyA = false;
    bool keyB = false;
    bool keyX = false;
    bool keyY = false;

    bool rightBar = false;
    bool leftBar = false;
};

} //namespace xpadcar_rpi

#endif //BUTTONSAXISSTATUS_HPP