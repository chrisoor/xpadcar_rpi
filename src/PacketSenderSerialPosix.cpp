#include "PacketSenderSerialPosix.hpp"

#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

namespace xpadcar_rpi
{

bool PacketSenderSerialPosix::OpenCommDevice(const std::string& deviceName)
{
    fdSerialPort = open(deviceName.c_str(), O_WRONLY | O_NOCTTY | O_NDELAY);

    if (fdSerialPort == -1)
    {
        return false;
    }

    return true;
}

void PacketSenderSerialPosix::CloseCommDevice()
{
    close(fdSerialPort);
}

bool PacketSenderSerialPosix::SendPacket(const std::string& packet)
{
    int n = write(fdSerialPort, packet.c_str(), packet.size());

    if (n == -1)
    {
        return false;
    }

    return true;
}

void PacketSenderSerialPosix::SetDefaultOptions()
{
    struct termios portOptions;
    tcgetattr(fdSerialPort, &portOptions);

    //set speed
    cfsetospeed(&portOptions, B9600);
    cfsetispeed(&portOptions, B9600);
    
    //set data bits
    portOptions.c_cflag &= ~CSIZE;
    portOptions.c_cflag |= CS8;

    //set one stop bit (SCTOPB is two stop bits, negation is one)
    portOptions.c_cflag &= ~CSTOPB;

    //set no parity
    portOptions.c_cflag &= ~PARENB;

    //set line local, do not change "owner" of port
    portOptions.c_cflag |= (CLOCAL);

    //set raw input
    portOptions.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    portOptions.c_oflag &= ~OPOST;

    tcsetattr(fdSerialPort, TCSANOW, &portOptions);
}

} //namespace xpadcar_rpi