#ifndef PACKETSENDERSERIALLINUX_HPP
#define PACKETSENDERSERIALLINUX_HPP

#include "PacketSenderInterface.hpp"

namespace xpadcar_rpi
{

class PacketSenderSerialLinux // : public PacketSenderInterface
{
public:
    virtual ~PacketSenderSerialLinux() = default;
    // bool OpenCommDevice() override;
    // virtual void CloseCommDevice() override;
    // virtual bool SendPacket(const ButtonsAxisStatus* const buttonsAxis) override;
};

} //namespace xpadcar_rpi

#endif //PACKETSENDERSERIALLINUX_HPP