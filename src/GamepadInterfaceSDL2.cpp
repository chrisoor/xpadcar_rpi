#include "GamepadInterfaceSDL2.hpp"
#include "SDL.h"

GamepadInterfaceSDL2::GamepadInterfaceSDL2()
{

}

bool GamepadInterfaceSDL2::CheckIfGamepadConnected()
{
 bool result = false;

 if (SDL_NumJoysticks() > 0)
 {
     result = true;
 }

 return result;
}
