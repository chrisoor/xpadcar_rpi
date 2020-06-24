#ifndef BUTTONSAXISSTATUS_HPP
#define BUTTONSAXISSTATUS_HPP

#include <cstdint>
#include <vector>
#include <string>
#include <utility>

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

    std::vector<std::pair<std::string, int32_t ButtonsAxisStatus::*>> allowedAxes {
                                                                               std::make_pair("rightTrigger", &ButtonsAxisStatus::rightTrigger),
                                                                               std::make_pair("leftTrigger", &ButtonsAxisStatus::leftTrigger)
                                                                              };

    std::vector<std::pair<std::string, bool ButtonsAxisStatus::*>> allowedButtons {
                                                                               std::make_pair("KeyA", &ButtonsAxisStatus::keyA),
                                                                               std::make_pair("rightBar", &ButtonsAxisStatus::rightBar)
                                                                              };
};



} //namespace xpadcar_rpi

#endif //BUTTONSAXISSTATUS_HPP