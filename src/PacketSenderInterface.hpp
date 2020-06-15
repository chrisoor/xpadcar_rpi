#ifndef PACKETSENDERINTERFACE_HPP
#define PACKETSENDERINTERFACE_HPP

namespace xpadcar_rpi
{

struct ButtonsAxisStatus;

class PacketSenderInterface
{
public:
    virtual ~PacketSenderInterface() = default;
    virtual bool OpenCommDevice() = 0;
    virtual void CloseCommDevice() = 0;
    virtual bool SendPacket(const ButtonsAxisStatus* const buttonsAxis) = 0;
};

} // namespace xpadcar_rpi

#endif // PACKETSENDERINTERFACE_HPP