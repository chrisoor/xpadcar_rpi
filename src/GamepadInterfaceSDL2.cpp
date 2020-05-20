#include "GamepadInterfaceSDL2.hpp"
#include "SDL.h"

namespace xpadcar_rpi
{

GamepadInterfaceSDL2::GamepadInterfaceSDL2()
{

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

}

}
