#include "PacketShowTerminal.hpp"
#include <iostream>

namespace xpadcar_rpi
{

bool PacketShowTerminal::SendPacket(const std::string& packet)
{
    std::cout<<packet<<std::endl;

    return true;
}

} //namespace xpadcar_rpi
