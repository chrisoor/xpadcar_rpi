#ifndef MESSAGEMAKERBASE_HPP
#define MESSAGEMAKERBASE_HPP

#include <string>
#include <vector>
#include <utility>
#include <functional>

#include "ButtonsAxesStatus.hpp"

namespace xpadcar_rpi
{

class MessageMaker
{
public:
    virtual ~MessageMaker() = default;

    template<typename T>
    std::string MakeMessage(const std::vector<std::pair<T, std::function<int32_t()>>>& axes,
                            const std::vector<std::pair<T, std::function<bool()>>>& buttons) const
    {
        std::string message {"{"};

        message += MakeMessageCellsT(axes);
        message += MakeMessageCellsT(buttons);
        message += "}";

        return message;
    }

private:

    template<typename T1, typename T2>
    std::string MakeMessageCellsT(const std::vector<std::pair<T1, std::function<T2>>>& vectorWithPairs) const
    {
       std::string returnString {};

        for (auto pair : vectorWithPairs)
        {
            returnString += "[" + returnStringFromFirst(pair.first) + ":" + std::to_string(pair.second()) + "]";
        }

        return returnString;
    }

    std::string returnStringFromFirst(ButtonsAxesEnum buttonsAxes) const
    {
        return std::to_string(buttonsAxes);
    }

    std::string returnStringFromFirst(std::string buttonsAxes) const
    {
        return buttonsAxes;
    }
    
};

}

#endif //MESSAGEMAKERBASE_HPP