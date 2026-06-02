#ifndef LOGICEXCEPTIONS_H
#define LOGICEXCEPTIONS_H

#include <exception>
using std::exception;

class ExceptionUnknownLogicGateID :public exception
{
    public:
        ExceptionUnknownLogicGateID(){}
        const char* what() const noexcept override
        {
            return "Gate ID unknown in this circuit!";
        }
};

class ExceptionInputConnected :public exception
{
    public:
        ExceptionInputConnected(){}
        const char* what() const noexcept override
        {
            return "Attempt to connect to an "
                   "already connected InputSignal. "
                   "Only one simultaneus connection is supported.";
        }
};

class ExceptionIllegalInputChannel :public exception
{
    public:
        ExceptionIllegalInputChannel(){}
        const char* what() const noexcept override
        {
            return "Attempt to connect to an "
                   "non existing InputSignal. ";
        }
};

class ExceptionIllegalSwitchType :public exception
{
    public:
        ExceptionIllegalSwitchType(){}
        const char* what() const noexcept override
        {
            return "Attempt to select a non defined type "
                   "of switch to be used within LogicGateSwitch object. ";
        }
};

class ExceptionFunctionNotImplemented :public exception
{
    public:
        ExceptionFunctionNotImplemented(){}
        const char* what() const noexcept override
        {
            return "This function was not yet implemented. please fix this!";
        }
};

#endif // LOGICEXCEPTIONS_H
