#ifndef LOGICGATESWITCH_H
#define LOGICGATESWITCH_H

#include "LogicGate.h"
#include "Switch.h"
#include "SwitchPulse.h"


class LogicGateSwitch : public LogicGate{
private:
    SwitchPulse* TimedSwitchElement;
protected:
    Switch* SwitchElement;


public:
    LogicGateSwitch(const string& Label, const Point& Position, const string& ID, unsigned int Type=0, int Timing=100);
    ~LogicGateSwitch();
    void updateOutput();
    void onMouse(const Point& where);
    void decorate() const;
    void clock();


    LogicGateSwitch(const LogicGateSwitch& orig) = delete;
    LogicGateSwitch& operator=(const LogicGateSwitch& rhs) = delete;
};



#endif // LOGICGATESWITCH_H
