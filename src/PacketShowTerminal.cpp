#include "PacketShowTerminal.hpp"
#include <iostream>

namespace xpadcar_rpi
{

bool PacketShowTerminal::SendPacket(const ButtonsAxisStatus* const buttonsAxis)
{
    // (void)buttonsAxis;
    std::cout<<"rightTrigger: "<<buttonsAxis->rightTrigger<<std::endl;

    return true;
}

} //namespace xpadcar_rpi
