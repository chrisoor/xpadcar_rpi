#ifndef GAMEPADINTERFACESDL2_H
#define GAMEPADINTERFACESDL2_H

#include "IGamepadInterface.hpp"
#include "SDL_gamecontroller.h"

namespace xpadcar_rpi
{

class GamepadInterfaceSDL2 : public IGamepadInterface
{
public:
    GamepadInterfaceSDL2();
    virtual ~GamepadInterfaceSDL2() override;

    bool IsGamepadConnected() const override;
    bool OpenGamepadConnection(const uint8_t gamepadId) override;

private:
    SDL_GameController *pController;
};

}

#endif // GAMEPADINTERFACESDL2_H
