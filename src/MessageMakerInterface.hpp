#ifndef MESSAGEMAKERINTERFACE_HPP
#define MESSAGEMAKERINTERFACE_HPP


namespace xpadcar_rpi
{

class string;
class ButtonsAxisStatus;

class MessageMakerInterface
{
public:
    virtual ~MessageMakerInterface() = default;
    virtual const string& MakeMessage(const ButtonsAxisStatus& buttonsAxis) const = 0;
};

}

#endif //MESSAGEMAKERINTERFACE_HPP