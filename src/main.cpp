#include <iostream>
#include <string>
#include "SDL2/SDL.h"
#include "GamepadInterfaceSDL2.hpp"
#include "ButtonsAxesStatus.hpp"
#include "TimerSDL2.hpp"
#include "PacketShowTerminal.hpp"
#include "PacketSenderSerialPosix.hpp"
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
    xpadcar_rpi::MessageMaker messageMaker;

    xpadcar_rpi::PacketSenderSerialPosix packetSender;
    if (packetSender.OpenCommDevice("/dev/ttyUSB0") == false)
    {
        return 1;
    }
    
    xpadcar_rpi::GamepadInterfaceSDL2 gamepad;
    if (gamepad.OpenConnection(0) == false)
    {
        return 1;
    }

    xpadcar_rpi::TimerSDL2 timer;
    timer.SetTimeToElapse(250);
    timer.ResetTimer();

    int i {0};
    std::string messageToSend {};
    while(i<25)
    {
        if ( timer.HasElapsedTimePassed() )
        {
            std::cout<<"Time passed! i: "<<i<<std::endl;

            if (gamepad.UpdateButtonsAxisStatus(&buttonsAxes) == false)
            {
                return 1;
            }

            if (buttonsAxes.keyY == true)
            {
                break;
            }

            messageToSend = messageMaker.MakeMessage(buttonsAxes.testAxes, buttonsAxes.testButtons);
            packetSender.SendPacket(messageToSend);
            packetSender.SendPacket("\n\r");

            timer.ResetTimer();
            i++;
        }
        else
        {
            timer.Wait(50);
        }
    }

    packetSender.CloseCommDevice();	
    SDL_Quit();

	return 0;
}
