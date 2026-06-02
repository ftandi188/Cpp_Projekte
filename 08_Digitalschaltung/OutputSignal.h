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

class OutputSignal :public ColorBox
{
    public:
        OutputSignal(const Point& Position,
                     bool InitialState);
        ~OutputSignal();
        void sendState(bool newState);
        bool getLastState() const;
        void show() const;
        void connectToConsumer(LogicGate& Consumer, unsigned Port);
        void disconnectConsumer(InputSignal& Consumer);
    protected:

    private:
        vector<InputSignal*> FanOut;
        bool LastState;
};

#endif // OUTPUTSIGNAL_H
