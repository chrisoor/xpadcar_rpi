#include "PacketShowTerminal.hpp"

namespace xpadcar_rpi
{

bool PacketShowTerminal::SendPacket(const ButtonsAxisStatus* const buttonsAxis)
{
    (void)buttonsAxis;

    return true;
}

} //namespace xpadcar_rpi
