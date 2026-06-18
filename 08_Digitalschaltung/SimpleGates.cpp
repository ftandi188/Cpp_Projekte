#include "testlevel.h"
#include "SimpleGates.h"

#if TEST_LEVEL >= TEST_SIMPLEGATES

// NOT
LogicGateNOT::LogicGateNOT(const Point& Position, const string& ID)
                            :LogicGate("NOT", Position, ID, 1)
{}

void LogicGateNOT::updateOutput()
{
    setOutput(!Input[0].getState());
}

void LogicGateNOT::decorate() const         //Zeichnen vom Invertierungspunkt beim NOT
{
    LogicGate::decorate();
    FillCol(0,0,0);
    Point LO(getPosition()+getSize().scaleXY(1.0,.5)+Point(0,-4));  //scaleXY(...), um gleich bei halber Höhe rauszukommen
    Point RU(getPosition()+getSize().scaleXY(1.0,.5)+Point(8,4));
    Elli(LO.X, LO.Y, RU.X, RU.Y);
}


// AND

LogicGateAND::LogicGateAND(const Point& Position, const string& ID, int Ports)
                            :LogicGate("AND", Position, ID, Ports)
{}

void LogicGateAND::updateOutput(){
    bool outp = 1;

    for(auto& in : Input){
        if(in.getState() == false){
            outp = 0;
        }
    }
    LogicGate::setOutput(outp,0);
}


//OR

LogicGateOR::LogicGateOR(const Point& Position, const string& ID, int Ports)
                            :LogicGate("OR", Position, ID, Ports)
{}

void LogicGateOR::updateOutput(){
    bool outp = 0;

    for(auto& in : Input){
        if(in.getState() == true){
            outp = 1;
        }
    }
    LogicGate::setOutput(outp,0);
}


//NAND

LogicGateNAND::LogicGateNAND(const Point& Position, const string& ID, int Ports)
                            :LogicGate("NAND", Position, ID, Ports)
{}

void LogicGateNAND::updateOutput(){
    bool outp = 0;

    for(auto& in : Input){
        if(in.getState() == false){
            outp = 1;
        }
    }
    LogicGate::setOutput(outp,0);
}

void LogicGateNAND::decorate() const{
    LogicGate::decorate();
    FillCol(0,0,0);
    Point LO(getPosition()+getSize().scaleXY(1.0,.5)+Point(0,-4));
    Point RU(getPosition()+getSize().scaleXY(1.0,.5)+Point(8,4));
    Elli(LO.X, LO.Y, RU.X, RU.Y);
}

//XOR

LogicGateXOR::LogicGateXOR(const Point& Position, const string& ID, int Ports)
                            :LogicGate("XOR", Position, ID, Ports)
{}

void LogicGateXOR::updateOutput(){
    int counter = 0;

    for(auto& in : Input){
        if(in.getState() == true){
            counter++;
        }
    }
    if(counter%2 == 0){                     //Bei gerader Anzahl an Einsen: Ausgang Low
        LogicGate::setOutput(false,0);
    }
    else{                                   //Bei ungerader Anzahl: Ausgang High
        LogicGate::setOutput(true,0);
    }
}

void LogicGateXOR::decorate() const{

    FillCol(0,0,0);
    LineCol(0,0,0);

    //Ich male lauter parallele Linien; mit der FillPoly-Funktion geht es nicht
    for (int i = Position.X + Size.X - 7; i <= Position.X + Size.X; i++){
        Line(i, Position.Y, i, Position.Y + Size.Y);
    }

    LogicGate::decorate();
}
#endif
