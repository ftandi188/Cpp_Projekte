#include "testlevel.h"
#include <vector>
using std::vector;
#include "LogicGate.h"
#include "RGBColor.h"
#include "InputSignal.h"
#include "LogicExceptions.h"
#if TEST_LEVEL > TEST_START


LogicGate::LogicGate(const string & Operation,
                     const Point& Position,
                     const string& ID,
                     unsigned NumInputs)

:TextBox(Position, Point(100,70), Operation),               //Konstruktor TextBox
 Input(NumInputs, InputSignal(*this, Point(0,0), false)),   //Konstruktor des Vektors (siehe OneNote)
 Output(Position+getSize().scaleY(.5), false),              //Konstruktor OutputSignal
 Indicator(getPosition()+getSize()-Point(15,15), Point(10,10),RGBColor(255,0,0)),   //Konstruktor ColorBox
 ID(ID)
{
    positionElements();     //Positionieren der InputSignal-Objekte im Vektor
}

LogicGate::~LogicGate()
{
}

bool LogicGate::operator==(const string& ID) const
{
      return LogicGate::ID==ID;
}

unsigned LogicGate::getNumInputs() const
{
    return Input.size();
}

unsigned LogicGate::getNumOutputs() const
{
    return 1;
}

const string& LogicGate::getID() const
{
    return ID;
}

void LogicGate::show() const
{
    throw ExceptionFunctionNotImplemented();
}

void LogicGate::updateIndicator()
{
    throw ExceptionFunctionNotImplemented();
}

bool LogicGate::getOutput(unsigned Index) const
{
    throw ExceptionFunctionNotImplemented();
    return false;
}

void LogicGate::setOutput(bool NewState, unsigned Port)
{
    throw ExceptionFunctionNotImplemented();
}


InputSignal& LogicGate::connectInput(OutputSignal& From,
                                          bool CurrentState,
                                          unsigned Index)
{
    throw ExceptionFunctionNotImplemented();
}

void LogicGate::connectOutput(LogicGate& Peer, unsigned Index)
{
    throw ExceptionFunctionNotImplemented();
}

void LogicGate::decorate() const
{
    throw ExceptionFunctionNotImplemented();
}

void LogicGate::setPosition(const Point& Position)
{
    throw ExceptionFunctionNotImplemented();
}

void LogicGate::setSize(const Point& Size)
{
    TextBox::setSize(Size);
    positionElements();
}

void LogicGate::positionElements()
{
    throw ExceptionFunctionNotImplemented();
}

#endif
