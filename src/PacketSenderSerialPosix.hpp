#ifndef PACKETSENDERSERIALPOSIX_HPP
#define PACKETSENDERSERIALPOSIX_HPP

#include "PacketSenderInterface.hpp"

namespace xpadcar_rpi
{

class PacketSenderSerialPosix : public PacketSenderInterface
{
public:
    virtual ~PacketSenderSerialPosix() = default;
    bool OpenCommDevice(const std::string& deviceName) override;
    void CloseCommDevice() override;
    bool SendPacket(const std::string& packet) override;

private:
    void SetDefaultOptions();
    int fdSerialPort = 0;
};

} //namespace xpadcar_rpi

#endif //PACKETSENDERSERIALPOSIX_HPP