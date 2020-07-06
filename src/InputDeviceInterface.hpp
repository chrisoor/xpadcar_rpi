#ifndef INPUTDEVICEINTERFACE_HPP
#define INPUTDEVICEINTERFACE_HPP

#include <cstdint>

namespace xpadcar_rpi
{

struct ButtonsAxesStatus;

class InputDeviceInterface
{
public:
    virtual ~InputDeviceInterface() = default;

    virtual bool OpenConnection(const uint8_t deviceId) = 0;
    virtual void CloseConnection() = 0;
    virtual bool UpdateButtonsAxisStatus(ButtonsAxesStatus* const pButtonsAxes) = 0;
};

} // namespace xpadcar_rpi

#endif // IGAMEPADINTERFACES_HPP
