#ifndef INPUTSIGNAL_H
#define INPUTSIGNAL_H

#include "Point.h"
#include "ColorBox.h"

class LogicGate;
class OutputSignal;

class InputSignal :public ColorBox{
private:
    LogicGate& LocalGate;           //Referenz auf Gatter, zu dem es gehört
    OutputSignal* RemoteOutput;
    bool State;                     //Speichert den vom verbundenen Ausgang zuletzt übermittelten Logikwert
    bool Connected;                 //Zeigt Verbindungsstatus an

public:
    InputSignal(LogicGate& LocalGate, const Point& Position, bool InitialState=false);
    ~InputSignal();

    void setState(bool NewState);
    void disconnectInput();
    InputSignal& connect(OutputSignal& From, bool InitialState);
    bool getState()const;
    bool isConnected()const;
    //void show() const;

};

#endif // INPUTSIGNAL_H
