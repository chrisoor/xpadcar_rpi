#include <iostream>
#include "SDL.h"
#include "GamepadInterfaceSDL2.hpp"
#include "ButtonsAxisStatus.hpp"
#include "TimerSDL2.hpp"
#include <string>
#include "chrono"
#include "ctime"

int main(int argc, char* argv[])
{
    //ignoring parameters for the development time
    (void)argc;
    (void)argv;

	std::cout<<"Hello, world!"<<std::endl;

    if (SDL_Init(SDL_INIT_GAMECONTROLLER | SDL_INIT_TIMER) != 0)
    {
        return 1;
    }
    
    xpadcar_rpi::GamepadInterfaceSDL2 gamepad;
    std::cout<<"Is any gamepad connected: "<< gamepad.IsGamepadConnected() <<std::endl;

    std::cout<<"Is gamepad opened: "<< gamepad.OpenConnection(0) <<std::endl;

    //SDL_TimerID my_timer_id = SDL_AddTimer(10, tester, nullptr);

    xpadcar_rpi::TimerSDL2 timer;
    timer.SetTimeToElapse(250);
    timer.ResetTimer();

    int i {0};
    bool result {false};
    xpadcar_rpi::ButtonsAxisStatus buttonsAxis;
    while(i<15)
    {
        if ( timer.HasElapsedTimePassed() )
        {
            std::cout<<"Time passed! i: "<<i<<std::endl;
            result = gamepad.UpdateButtonsAxisStatus(&buttonsAxis);
            std::cout<<"result: "<<result<<std::endl;
            std::cout<<"rightTrigger: "<<buttonsAxis.rightTrigger<<std::endl;
            timer.ResetTimer();
            i++;
        }
        else
        {
            timer.Wait(50);
        }
    }
	
    SDL_Quit();
	return 0;
}
