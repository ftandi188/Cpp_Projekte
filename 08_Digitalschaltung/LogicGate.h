#ifndef LOGICGATE_H
#define LOGICGATE_H

#include <string>
using std::string;
#include <vector>
using std::vector;
#include "ColorBox.h"
#include "TextBox.h"
#include "WinAdapt.h"
#include "OutputSignal.h"
#include "InputSignal.h"
#include "testlevel.h"

class InputSignal;

class LogicGate :public TextBox{
private:
    OutputSignal Output;
    ColorBox Indicator;
    string ID;

protected:
    vector<InputSignal> Input;      //Template-Objekt: InputSignal-Objekte eines LogicGates werden
                                    //gespeichert wie in einem Array (Beachte: die Objekte selber, keine Pointer!)

private:
    void updateIndicator();
    void positionElements();

protected:
    virtual void decorate() const;
    void setOutput(bool NewState, unsigned Port=0);

public:
    LogicGate(const string& Operation, const Point& Position, const string& ID, unsigned NumInputs=2);
    //Operation und Position für Basisinitialisierer von TextBox (Größe ist im Konstruktor fest hinterlegt)
    virtual ~LogicGate();

    bool operator==(const string& ID) const;
    const string& getID() const;
    virtual void setPosition(const Point& Position);
    virtual void setSize(const Point& Size);
    virtual void show() const;
    virtual void updateOutput(){};
    virtual bool getOutput(unsigned Port=0) const;
    unsigned getNumOutputs() const;
    unsigned getNumInputs() const;
    void connectOutput(LogicGate& Peer, unsigned Port=0);
    InputSignal& connectInput(OutputSignal& From, bool CurrentState, unsigned Port=0);
};

#endif
