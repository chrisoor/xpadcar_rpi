#ifndef PACKETSHOWTERMINAL_HPP
#define PACKETSHOWTERMINAL_HPP

#include "PacketSenderInterface.hpp"

namespace xpadcar_rpi
{

//This class will show packets on terminal for debug purposes instead of sending them anywhere:
class PacketShowTerminal : public PacketSenderInterface
{
public:
    virtual ~PacketShowTerminal() = default;
    bool OpenCommDevice(const std::string& deviceName) override {(void)deviceName; return true;}
    void CloseCommDevice() override {}
    bool SendPacket(const std::string& packet) override;
};

} //namespace xpadcar_rpi

#endif // PACKETSHOWTERMINAL_HPP