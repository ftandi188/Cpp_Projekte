#include "testlevel.h"
#include "InputSignal.h"
#include "LogicGate.h"
#include "LogicExceptions.h"
#if TEST_LEVEL > TEST_START


InputSignal::InputSignal(LogicGate& LocalGate,
                         const Point& Position,
                         bool InitialState)
:ColorBox(Position, Point(4,2), RGBColor(128,128,128)),
 LocalGate(LocalGate),
 RemoteOutput(nullptr),
 State(InitialState),
 Connected(false)
{
}

InputSignal::~InputSignal()
{
    throw ExceptionFunctionNotImplemented();
}

void InputSignal::setState(bool NewState)
{
    throw ExceptionFunctionNotImplemented();

}

bool InputSignal::getState() const
{
    return State;
}


bool InputSignal::isConnected() const
{
    return Connected;
}

void InputSignal::disconnectInput()
{
    throw ExceptionFunctionNotImplemented();
}

InputSignal& InputSignal::connect(OutputSignal& From,
                                  bool InitialState)
{
    throw ExceptionFunctionNotImplemented();
}

#endif
