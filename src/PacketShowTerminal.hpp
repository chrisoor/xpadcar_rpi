#ifndef PACKETSHOWTERMINAL_HPP
#define PACKETSHOWTERMINAL_HPP

#include "PacketSenderInterface.hpp"

namespace xpadcar_rpi
{

class PacketShowTerminal : public PacketSenderInterface
{
public:
    virtual ~PacketShowTerminal() = default;
    bool OpenCommDevice() {return true;}
    void CloseCommDevice() {}
    bool SendPacket(const ButtonsAxisStatus* const buttonsAxis);
};

} //namespace xpadcar_rpi

#endif // PACKETSHOWTERMINAL_HPP