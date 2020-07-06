#ifndef PACKETSENDERINTERFACE_HPP
#define PACKETSENDERINTERFACE_HPP

#include "ButtonsAxesStatus.hpp"

namespace xpadcar_rpi
{

class PacketSenderInterface
{
public:
    virtual ~PacketSenderInterface() = default;
    virtual bool OpenCommDevice() = 0;
    virtual void CloseCommDevice() = 0;
    virtual bool SendPacket(const ButtonsAxesStatus* const buttonsAxes) = 0;
};

} // namespace xpadcar_rpi

#endif // PACKETSENDERINTERFACE_HPP