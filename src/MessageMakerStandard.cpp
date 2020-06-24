#include "MessageMakerStandard.hpp"
#include "ButtonsAxisStatus.hpp"
#include <string>

namespace xpadcar_rpi
{

const std::string& MessageMakerStandard::MakeMessage(const ButtonsAxisStatus& buttonsAxis) const
{
    std::string message {"{"};

    message += "[rightTrigger:" + std::to_string(buttonsAxis.rightTrigger) + "]";

    message += "}";
    return message;
}

} //namespace xpadcar_rpi