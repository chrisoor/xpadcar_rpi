#ifndef IGAMEPADINTERFACES_H
#define IGAMEPADINTERFACES_H

#include <cstdint>
namespace xpadcar_rpi
{

struct ButtonsAxisStatus
{
    uint8_t rightTrigger;
    uint8_t leftTrigger;

    uint8_t leftStickUp;
    uint8_t leftStickDown;
    uint8_t leftStickRight;
    uint8_t leftStickLeft;

    uint8_t rightStickUp;
    uint8_t rightStickDown;
    uint8_t rightStickRight;
    uint8_t rightStickLeft;

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

class IGamepadInterface
{
public:
//    IGamepadInterface();
    virtual ~IGamepadInterface() = default;

    virtual bool IsGamepadConnected() const = 0;
    virtual bool OpenGamepadConnection(uint8_t gamepadId) = 0;
//    virtual
};

}

#endif // IGAMEPADINTERFACES_H
