#ifndef BUTTONSAXESSTATUS_HPP
#define BUTTONSAXESSTATUS_HPP

#include <cstdint>
#include <vector>
#include <string>
#include <utility>
#include <functional>

namespace xpadcar_rpi
{

enum ButtonsAxesEnum
{
    rightTriggerEnum = 0,
    leftTriggerEnum = 1,
    keyAEnum = 10,
    keyBEnum
};

struct ButtonsAxesStatus
{
    int32_t rightTrigger = 0;
    int32_t leftTrigger = 0;

    int32_t rightStickX = 0;
    int32_t rightStickY = 0;

    int32_t leftStickX = 0;
    int32_t leftStickY = 0;

    bool keyA = false;
    bool keyB = false;
    bool keyX = false;
    bool keyY = false;

    bool rightBar = false;
    bool leftBar = false;

    

    std::vector<std::pair<std::string, std::function<int32_t()>>> testAxes {
                                                                            std::make_pair("rightTrigger", [this] {return rightTrigger;}),
                                                                            std::make_pair("leftTrigger", [this] {return leftTrigger;})
                                                                           };
    std::vector<std::pair<std::string, std::function<bool()>>> testButtons {
                                                                            std::make_pair("keyA", [this] {return keyA;})
                                                                           };

    std::vector<std::pair<ButtonsAxesEnum, std::function<int32_t()>>> testAxesEnum {
                                                                            std::make_pair(rightTriggerEnum, [this] {return rightTrigger;}),
                                                                            std::make_pair(leftTriggerEnum, [this] {return leftTrigger;})
                                                                           };
    std::vector<std::pair<ButtonsAxesEnum, std::function<bool()>>> testButtonsEnum {
                                                                            std::make_pair(keyAEnum, [this] {return keyA;})
                                                                           };

    std::vector<std::pair<std::string, int32_t ButtonsAxesStatus::*>> allowedAxes {
                                                                               std::make_pair("rightTrigger", &ButtonsAxesStatus::rightTrigger),
                                                                               std::make_pair("leftTrigger", &ButtonsAxesStatus::leftTrigger)
                                                                              };
    std::vector<std::pair<std::string, bool ButtonsAxesStatus::*>> allowedButtons {
                                                                               std::make_pair("KeyA", &ButtonsAxesStatus::keyA),
                                                                               std::make_pair("rightBar", &ButtonsAxesStatus::rightBar)
                                                                              };
};

} //namespace xpadcar_rpi

#endif //BUTTONSAXESSTATUS_HPP