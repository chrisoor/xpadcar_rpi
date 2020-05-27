#include <iostream>
#include "SDL.h"
#include "GamepadInterfaceSDL2.hpp"

uint32_t tester(uint32_t interval, void *param)
{
    std::cout<<"Z wnetrza tester"<<std::endl;
    return interval;
}

int main(int argc, char* argv[])
{
	std::cout<<"Hello, world!"<<std::endl;

    if (SDL_Init(SDL_INIT_GAMECONTROLLER | SDL_INIT_TIMER) != 0)
    {
        return 1;
    }

    xpadcar_rpi::GamepadInterfaceSDL2 gamepad;
    std::cout<<"Is any gamepad connected: "<< gamepad.IsGamepadConnected() <<std::endl;

    std::cout<<"Is gamepad opened: "<< gamepad.OpenGamepadConnection(0) <<std::endl;

    SDL_TimerID my_timer_id = SDL_AddTimer(10, tester, nullptr);

	
    SDL_Quit();
	return 0;
}
