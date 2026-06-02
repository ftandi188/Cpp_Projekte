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
    //FIXME! throw ExceptionFunctionNotImplemented();
}

void OutputSignal::sendState(bool NewState)
{
    throw ExceptionFunctionNotImplemented();
}

bool OutputSignal::getLastState() const
{
    return LastState;
}

void OutputSignal::connectToConsumer(LogicGate& Consumer, unsigned Port)
{
    throw ExceptionFunctionNotImplemented();
}

void OutputSignal::disconnectConsumer(InputSignal& Consumer)
{
    throw ExceptionFunctionNotImplemented();
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



