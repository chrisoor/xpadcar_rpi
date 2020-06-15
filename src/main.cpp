#include <iostream>
#include "SDL.h"
#include "GamepadInterfaceSDL2.hpp"
#include "ButtonsAxisStatus.hpp"
#include "TimerSDL2.hpp"
#include "PacketShowTerminal.hpp"
#include <string>

int main(int argc, char* argv[])
{
    //ignoring parameters for the development time
    (void)argc;
    (void)argv;

    if (SDL_Init(SDL_INIT_GAMECONTROLLER | SDL_INIT_TIMER) != 0)
    {
        return 1;
    }
    
    xpadcar_rpi::ButtonsAxisStatus buttonsAxis;
    xpadcar_rpi::GamepadInterfaceSDL2 gamepad;
    std::cout<<"Is gamepad opened: "<< gamepad.OpenConnection(0) <<std::endl;

    xpadcar_rpi::PacketShowTerminal packetShow;

    xpadcar_rpi::TimerSDL2 timer;
    timer.SetTimeToElapse(250);
    timer.ResetTimer();

    int i {0};
    bool result {false};
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
