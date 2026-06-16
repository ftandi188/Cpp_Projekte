#ifndef OUTPUTSIGNAL_H
#define OUTPUTSIGNAL_H
#include "string"
using std::string;

#include "Point.h"
#include "TextBox.h"
#include "vector"
using std::vector;

class InputSignal;
class LogicGate;

class OutputSignal :public ColorBox{
private:
    vector<InputSignal*> FanOut;        //Array der InputSignal-Pointer, mit denen das Output-Objekt verbunden ist
    bool LastState;                     //Zuletzt kommunizierter Logikwert wird hier abgelegt

public:
    OutputSignal(const Point& Position, bool InitialState);
    ~OutputSignal();

    void sendState(bool newState);
    bool getLastState() const;
    void show() const;
    void connectToConsumer(LogicGate& Consumer, unsigned Port);
    void disconnectConsumer(InputSignal& Consumer);

};

#endif // OUTPUTSIGNAL_H
