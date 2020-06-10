#ifndef INPUTDEVICEINTERFACE_H
#define INPUTDEVICEINTERFACE_H

#include <cstdint>

namespace xpadcar_rpi
{

struct ButtonsAxisStatus;

class InputDeviceInterface
{
public:
    virtual ~InputDeviceInterface() = default;

    virtual bool OpenConnection(const uint8_t deviceId) = 0;
    virtual bool CloseConnection() = 0;
    virtual bool UpdateButtonsAxisStatus(ButtonsAxisStatus* pButtonsAxis) = 0;
};

} // namespace xpadcar_rpi

#endif // IGAMEPADINTERFACES_H
