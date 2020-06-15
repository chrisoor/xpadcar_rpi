#include "PacketShowTerminal.hpp"
#include "ButtonsAxisStatus.hpp"
#include <iostream>
#include <string>

namespace xpadcar_rpi
{

bool PacketShowTerminal::SendPacket(const ButtonsAxisStatus* const buttonsAxis)
{
    // (void)buttonsAxis;
    // std::cout<<"rightTrigger: "<<buttonsAxis->rightTrigger<<std::endl;
    for ( auto it = buttonsAxis->analogMap.begin(); it != buttonsAxis->analogMap.end(); it++)
    {
        std::cout<< it->first <<" :"<< *(it->second) <<std::endl;
    }

    return true;
}

} //namespace xpadcar_rpi
