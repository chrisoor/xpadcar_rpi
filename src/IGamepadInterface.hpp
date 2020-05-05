#ifndef IGAMEPADINTERFACES_H
#define IGAMEPADINTERFACES_H


class IGamepadInterface
{
public:
//    IGamepadInterface();
    virtual ~IGamepadInterface() {}

    virtual bool CheckIfGamepadConnected() = 0;
};

#endif // IGAMEPADINTERFACES_H
