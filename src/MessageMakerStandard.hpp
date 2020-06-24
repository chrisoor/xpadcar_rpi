#ifndef MESSAGEMAKERSTANDARD_HPP
#define MESSAGEMAKERSTANDARD_HPP

#include "MessageMakerInterface.hpp"

namespace xpadcar_rpi
{

class string;
struct ButtonsAxisStatus;

class MessageMakerStandard : public MessageMakerInterface
{
public:
    virtual ~MessageMakerStandard() = default;
    const std::string& MakeMessage(const ButtonsAxisStatus& buttonsAxis) const override;
};

}

#endif // MESSAGEMAKERSTANDARD_HPP