#include "testlevel.h"
#include "SimpleGates.h"

#if TEST_LEVEL >= TEST_SIMPLEGATES

// NOT
LogicGateNOT::LogicGateNOT(const Point& Position,
             const string& ID
             )
:LogicGate("NOT", Position, ID, 1)
{}

void LogicGateNOT::updateOutput()
{
    setOutput(!Input[0].getState());
}

void LogicGateNOT::decorate() const
{
    LogicGate::decorate();
    FillCol(0,0,0);
    Point LO(getPosition()+getSize().scaleXY(1.0,.5)+Point(0,-4));
    Point RU(getPosition()+getSize().scaleXY(1.0,.5)+Point(8,4));
    Elli(LO.X, LO.Y, RU.X, RU.Y);
}

#endif
