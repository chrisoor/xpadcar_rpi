#ifndef PACKETSENDERINTERFACE_HPP
#define PACKETSENDERINTERFACE_HPP

#include <string>

namespace xpadcar_rpi
{

class PacketSenderInterface
{
public:
    virtual ~PacketSenderInterface() = default;
    virtual bool OpenCommDevice(const std::string& deviceName) = 0;
    virtual void CloseCommDevice() = 0;
    virtual bool SendPacket(const std::string& packet) = 0;
};

} // namespace xpadcar_rpi

#endif // PACKETSENDERINTERFACE_HPP