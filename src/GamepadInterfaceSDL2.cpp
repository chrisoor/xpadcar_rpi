#include "GamepadInterfaceSDL2.hpp"
#include "SDL.h"

namespace xpadcar_rpi
{

GamepadInterfaceSDL2::GamepadInterfaceSDL2() : pController(nullptr)
{

}
GamepadInterfaceSDL2::~GamepadInterfaceSDL2()
{
    if (pController != nullptr)
    {
        SDL_GameControllerClose(pController);
    }
}

bool GamepadInterfaceSDL2::IsGamepadConnected() const
{
 bool result = false;

 if (SDL_NumJoysticks() > 0)
 {
     result = true;
 }

 return result;
}

bool GamepadInterfaceSDL2::OpenGamepadConnection(const uint8_t gamepadId)
{
    bool result = false;

    if (SDL_IsGameController(gamepadId) == true)
    {
        pController = SDL_GameControllerOpen(gamepadId);
        if (pController != nullptr)
        {
            result = true;
        }
    }

    return result;
}

}
