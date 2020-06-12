#include "GamepadInterfaceSDL2.hpp"
#include "ButtonsAxisStatus.hpp"

#include <string>
#include "SDL.h"

#include <iostream>

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

void GamepadInterfaceSDL2::CloseConnection()
{
    if (SDL_WasInit(SDL_INIT_GAMECONTROLLER) != 0) {
        if (pController != nullptr)
        {
           SDL_GameControllerClose(pController);
            pController = nullptr;
        }
    }
}

bool GamepadInterfaceSDL2::UpdateButtonsAxisStatus(ButtonsAxisStatus* pButtonsAxis)
{
    bool result {false};
    result = SDL_GameControllerGetAttached(pController);
    if (result == false)
    {
        return result;
    }

    SDL_GameControllerUpdate();
    pButtonsAxis->rightTrigger = static_cast<int32_t>(SDL_GameControllerGetAxis(pController, SDL_CONTROLLER_AXIS_TRIGGERRIGHT));

    result = SDL_GameControllerGetAttached(pController);

    return result;
}

} // namespace xpadcar_rpi
