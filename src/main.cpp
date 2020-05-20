#include <iostream>
#include "SDL.h"
#include "GamepadInterfaceSDL2.hpp"

int main(int argc, char* argv[])
{
	std::cout<<"Hello, world!"<<std::endl;

    if (SDL_Init(SDL_INIT_GAMECONTROLLER) != 0)
    {
        return 1;
    }

    xpadcar_rpi::GamepadInterfaceSDL2 gamepad;
    std::cout<<"Is any gamepad connected: "<< gamepad.IsGamepadConnected() <<std::endl;
	
    SDL_Quit();
	return 0;
}
