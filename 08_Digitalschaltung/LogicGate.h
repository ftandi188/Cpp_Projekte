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

class LogicGate :public TextBox
{
    public:
        LogicGate(string & Operation,
                     Point& Position,
                     string& ID,
                     unsigned NumInputs=2);
        virtual ~LogicGate();
        bool operator==(string& ID);
        string& getID();
        virtual void setPosition(Point& Position);
        virtual void setSize(Point& Size);
        virtual void show();
        virtual void updateOutput(){};
        virtual bool getOutput(unsigned Port=0);
        unsigned getNumOutputs();
        unsigned getNumInputs();
        void connectOutput(LogicGate& Peer, unsigned Port=0);
        InputSignal& connectInput(OutputSignal& From, bool CurrentState, unsigned Port=0);

    protected:
        virtual void decorate();
        void setOutput(bool NewState, unsigned Port=0);
        vector<InputSignal> Input;

    private:
        OutputSignal Output;
        ColorBox Indicator;
        string ID;
        void updateIndicator();
        void positionElements();
};


#endif
