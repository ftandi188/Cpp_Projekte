#ifndef INPUTSIGNAL_H
#define INPUTSIGNAL_H

#include "Point.h"
#include "ColorBox.h"

class LogicGate;
class OutputSignal;

class InputSignal :public ColorBox
{
    public:
        InputSignal(LogicGate& LocalGate,
                    const Point& Position,
                    bool InitialState=false);
        ~InputSignal();
        void setState(bool NewState);
        void disconnectInput();
        InputSignal& connect(OutputSignal& From, bool InitialState);
        bool getState()const;
        bool isConnected()const;
        //void show() const;

    protected:

    private:
        LogicGate& LocalGate;
        OutputSignal* RemoteOutput;
        bool State;
        bool Connected;

};

#endif // INPUTSIGNAL_H
