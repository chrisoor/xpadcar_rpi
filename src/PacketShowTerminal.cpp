#include "PacketShowTerminal.hpp"
#include <iostream>

namespace xpadcar_rpi
{

bool PacketShowTerminal::SendPacket(const ButtonsAxesStatus* const buttonsAxes)
{
    // (void)buttonsAxis;
    std::cout<<"rightTrigger: "<<buttonsAxes->rightTrigger<<std::endl;

    return true;
}

} //namespace xpadcar_rpi
