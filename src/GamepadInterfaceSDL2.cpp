#include "GamepadInterfaceSDL2.hpp"
#include "SDL.h"
#include "ButtonsAxisStatus.hpp"

namespace xpadcar_rpi
{

GamepadInterfaceSDL2::GamepadInterfaceSDL2() : pController(nullptr)
{

}
GamepadInterfaceSDL2::~GamepadInterfaceSDL2()
{
    CloseConnection();
}

bool GamepadInterfaceSDL2::IsGamepadConnected() const
{
    bool result {false};

    if (SDL_NumJoysticks() > 0)
    {
        result = true;
    }

    return result;
}

bool GamepadInterfaceSDL2::OpenConnection(const uint8_t deviceId)
{
    bool result {false};

    if (SDL_IsGameController(deviceId) == true)
    {
        pController = SDL_GameControllerOpen(deviceId);
        if (pController != nullptr)
        {
            result = true;
        }
    }

    return result;
}

bool GamepadInterfaceSDL2::CloseConnection()
{
    bool result {false};

    if (pController != nullptr)
    {
        SDL_GameControllerClose(pController);
        pController = nullptr;
        result = true;
    }

    return result;
}

bool GamepadInterfaceSDL2::UpdateButtonsAxisStatus(ButtonsAxisStatus* pButtonsAxis)
{
    pButtonsAxis->rightTrigger = static_cast<int32_t>(SDL_GameControllerGetAxis(pController, SDL_CONTROLLER_AXIS_TRIGGERRIGHT));

    bool result {true};
    return result;
}

} // namespace xpadcar_rpi
