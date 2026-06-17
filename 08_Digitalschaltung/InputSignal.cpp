#include "testlevel.h"
#include "InputSignal.h"
#include "LogicGate.h"
#include "LogicExceptions.h"
#if TEST_LEVEL > TEST_START


InputSignal::InputSignal(LogicGate& LocalGate,              //Konstruktor
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
    disconnectInput();
}

void InputSignal::setState(bool NewState)
{
    State = NewState;
    LocalGate.updateOutput();
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
    if(Connected == true){
        RemoteOutput->disconnectConsumer(*this);
        Connected = false;
        RemoteOutput = nullptr;
    }
}

InputSignal& InputSignal::connect(OutputSignal& From, bool InitialState)
{
    if(Connected == true){
        throw ExceptionInputConnected();
    }
    else{
        RemoteOutput = &From;
        Connected = true;
        State = InitialState;
        LocalGate.updateOutput();
        return *this;
    }
}

#endif
