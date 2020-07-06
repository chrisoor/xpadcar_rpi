#include "GamepadInterfaceSDL2.hpp"
#include "ButtonsAxesStatus.hpp"

#include <string>
#include "SDL2/SDL.h"

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

bool GamepadInterfaceSDL2::UpdateButtonsAxisStatus(ButtonsAxesStatus* const pButtonsAxes)
{
    bool result {false};
    result = SDL_GameControllerGetAttached(pController);
    if (result == false)
    {
        return result;
    }

    SDL_GameControllerUpdate();
    pButtonsAxes->rightTrigger = static_cast<int32_t>(SDL_GameControllerGetAxis(pController, SDL_CONTROLLER_AXIS_TRIGGERRIGHT));
    pButtonsAxes->leftTrigger = static_cast<int32_t>(SDL_GameControllerGetAxis(pController, SDL_CONTROLLER_AXIS_TRIGGERLEFT));

    result = SDL_GameControllerGetAttached(pController);

    return result;
}

} // namespace xpadcar_rpi
