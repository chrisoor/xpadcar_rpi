#include <iostream>
#include <string>
#include "SDL2/SDL.h"
#include "GamepadInterfaceSDL2.hpp"
#include "ButtonsAxesStatus.hpp"
#include "TimerSDL2.hpp"
#include "PacketShowTerminal.hpp"
#include "PacketSenderSerialLinux.hpp"
#include "MessageMaker.hpp"

int main(int argc, char* argv[])
{
    //ignoring parameters for the development time
    (void)argc;
    (void)argv;

    if (SDL_Init(SDL_INIT_GAMECONTROLLER | SDL_INIT_TIMER) != 0)
    {
        return 1;
    }
    
    xpadcar_rpi::ButtonsAxesStatus buttonsAxes;
    buttonsAxes.leftTrigger = 123;
    buttonsAxes.rightTrigger = 12;
    buttonsAxes.keyA = false;

    xpadcar_rpi::MessageMaker messageMaker;
    std::cout<<messageMaker.MakeMessage(buttonsAxes.testAxes, buttonsAxes.testButtons)<<std::endl;
    /*
    xpadcar_rpi::GamepadInterfaceSDL2 gamepad;
    std::cout<<"Is gamepad opened: "<< gamepad.OpenConnection(0) <<std::endl;

    xpadcar_rpi::PacketShowTerminal packetShow;
    xpadcar_rpi::PacketSenderSerialLinux packetSendSerialLinux;

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
            packetShow.SendPacket(&buttonsAxis);

            timer.ResetTimer();
            i++;
        }
        else
        {
            timer.Wait(50);
        }
    }
    */
	
    SDL_Quit();
	return 0;
}
