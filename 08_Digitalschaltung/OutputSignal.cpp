#include "testlevel.h"
#include "OutputSignal.h"
#include "ColorBox.h"
#include "InputSignal.h"
#include "LogicGate.h"
#include "LogicExceptions.h"



OutputSignal::OutputSignal(const Point& Position,
                           bool InitialState)
:ColorBox(Position, Point(2,4), RGBColor(128,128,128)),
 LastState(InitialState)
{
}

OutputSignal::~OutputSignal()
{
    for (auto& in : FanOut){
        in->disconnectInput();
    }
    //FIXME! throw ExceptionFunctionNotImplemented();
}

void OutputSignal::sendState(bool NewState)
{
    if(NewState != LastState){
        for (auto& in : FanOut){
            in->setState(NewState);
        }
        LastState = NewState;
    }
}

bool OutputSignal::getLastState() const
{
    return LastState;
}

void OutputSignal::connectToConsumer(LogicGate& Consumer, unsigned Port)
{
    InputSignal& temp = Consumer.connectInput(*this, LastState, Port);
    FanOut.push_back(&temp);
}

void OutputSignal::disconnectConsumer(InputSignal& Consumer)
{
    int i=0;
    Consumer.disconnectInput();
    for (auto& in : FanOut){
        if(in == &Consumer){
            break;
        }
        i++;
    }
    FanOut.erase(FanOut.begin() + i);
}

void OutputSignal::show() const
{
    //draw all the wires
    Point My=getPosition();
    for (auto Peer : FanOut)
    {
        Point PeerPosition=Peer->getPosition();
        Point Mid((My + PeerPosition)/2);
        Line(My.X, My.Y, Mid.X, My.Y);
        Line(Mid.X, My.Y, Mid.X, PeerPosition.Y);
        Line(Mid.X, PeerPosition.Y,
             PeerPosition.X, PeerPosition.Y);
    }
    //draw connector
    ColorBox::show();
}



