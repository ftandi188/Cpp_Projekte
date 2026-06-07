#include "Switch.h"
#include "TextBox.h"

#ifndef SWITCHPULSE_H_INCLUDED
#define SWITCHPULSE_H_INCLUDED

class SwitchPulse : public Switch{
protected:
    TextBox* PushButton;
    int DecayTime;

public:
    SwitchPulse(const Point& pos,const std::string& Label, int DecayTime=15);
    ~SwitchPulse();

    void onTimerTick();

    void show() const;
    void onMouse(const Point& p);
    void setPosition(const Point& pos);
};

#endif // SWITCHPULSE_H_INCLUDED
