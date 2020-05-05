#ifndef GAMEPADINTERFACESDL2_H
#define GAMEPADINTERFACESDL2_H

#include "IGamepadInterface.hpp"

class GamepadInterfaceSDL2 : public IGamepadInterface
{
public:
    GamepadInterfaceSDL2();
    virtual ~GamepadInterfaceSDL2() {}

    bool CheckIfGamepadConnected();
};

#endif // GAMEPADINTERFACESDL2_H
