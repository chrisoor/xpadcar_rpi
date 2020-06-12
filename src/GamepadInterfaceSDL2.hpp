#ifndef GAMEPADINTERFACESDL2_HPP
#define GAMEPADINTERFACESDL2_HPP

#include "InputDeviceInterface.hpp"
#include "SDL_gamecontroller.h"

namespace xpadcar_rpi
{

class GamepadInterfaceSDL2 : public InputDeviceInterface
{
public:
    GamepadInterfaceSDL2();
    virtual ~GamepadInterfaceSDL2() override;

    bool IsGamepadConnected() const;
    bool OpenConnection(const uint8_t deviceId) override;
    void CloseConnection() override;
    bool UpdateButtonsAxisStatus(ButtonsAxisStatus* const pButtonsAxis) override;

private:
    SDL_GameController *pController;
};

} // namespace xpadcar_rpi

#endif // GAMEPADINTERFACESDL2_HPP
