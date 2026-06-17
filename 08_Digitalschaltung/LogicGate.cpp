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
    Point p(Output.getPosition());
    Point q(Output.getPosition() + Output.getSize());
    Rect(p.X, p.Y, q.X, q.Y);           //eine Möglichkeit

    for (auto& in : Input){                                             //Zweite Möglichkeit
        Rect(in.getPosition().X, in.getPosition().Y, in.getPosition().X + in.getSize().X, in.getPosition().Y + in.getSize().Y);
        TextBox::show();
        ::Text(Position.X + 10, Position.Y + Size.Y - 20, ID.c_str());
    }
    decorate();
}


void LogicGate::updateIndicator()
{
    if(Output.getLastState() == false){
        Indicator.setColor(RGBColor(255,0,0));
    }
    else{
        Indicator.setColor(RGBColor(0,255,0));
    }
}

bool LogicGate::getOutput(unsigned Index) const     //Brauchen wir nicht, da nur ein Ausgang
{
    throw ExceptionFunctionNotImplemented();
    return false;
}

void LogicGate::setOutput(bool NewState, unsigned Port)     //Zweiter Parameter wird nicht benötigt
{
    Output.sendState(NewState);
    updateIndicator();
}


InputSignal& LogicGate::connectInput(OutputSignal& From, bool CurrentState, unsigned Index)
{                                                           //Aufruf durch Output-Objekt eines fremden Gatters, das einen Eingang belegen will
    if(Index >= getNumInputs()){
        throw ExceptionIllegalInputChannel();
    }
    else{
        Input[Index].connect(From, CurrentState);
        return Input[Index];
    }
}

void LogicGate::connectOutput(LogicGate& Peer, unsigned Index)     //Ausgang mit Eingang eines anderen LogicGates (Peer) verbinden
{                                                                  //Aufruf durch Output-Objekt als Member vom LogicGate-Objekt, das
    Output.connectToConsumer(Peer, Index);                         //fremden Eingang belegen will
}

void LogicGate::decorate() const
{
    Indicator.show();
    Output.show();
}

void LogicGate::setPosition(const Point& Position)
{
    TextBox::setPosition(Position);
    positionElements();
}

void LogicGate::setSize(const Point& Size)
{
    TextBox::setSize(Size);
    positionElements();
}

void LogicGate::positionElements()
{
    Indicator.setPosition(Point(Position.X + 75, Position.Y + 45));

    int n = getNumInputs();
    for(int i=0; i<n; i++){
        Input[i].setPosition(Point(Position.X - 4, Position.Y + (i+1)*(70-2*n)/(n+1) + 2*i));
    }
    Output.setPosition(Point(Position.X + 100, Position.Y + 33));
}

#endif
