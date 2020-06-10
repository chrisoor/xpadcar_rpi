#ifndef BUTTONSAXISSTATUS_H
#define BUTTONSAXISSTATUS_H

namespace xpadcar_rpi
{

struct ButtonsAxisStatus
{
    int32_t rightTrigger;
    int32_t leftTrigger;

    int32_t leftStickUp;
    int32_t leftStickDown;
    int32_t leftStickRight;
    int32_t leftStickLeft;

    int32_t rightStickUp;
    int32_t rightStickDown;
    int32_t rightStickRight;
    int32_t rightStickLeft;

    bool keyA;
    bool keyB;
    bool keyX;
    bool keyY;

    bool rightBar;
    bool leftBar;

    ButtonsAxisStatus() : rightTrigger(0),
                          leftTrigger(0),
                          leftStickUp(0),
                          leftStickDown(0),
                          leftStickRight(0),
                          leftStickLeft(0),
                          rightStickUp(0),
                          rightStickDown(0),
                          rightStickRight(0),
                          rightStickLeft(0),
                          keyA(false),
                          keyB(false),
                          keyX(false),
                          keyY(false),
                          rightBar(false),
                          leftBar(false)
    {
        
    }
};

} //namespace xpadcar_rpi

#endif //BUTTONSAXISSTATUS_H