#include "SwitchPulse.h"
#include "LogicGate.h"

SwitchPulse::SwitchPulse(const Point& pos,const std::string& Label, int uDecayTime)
            :DecayTime(uDecayTime),PushButton(new TextBox(Point(pos.X-66,pos.Y),Point(63,30),Label)),
             Switch(pos)
{}

SwitchPulse::~SwitchPulse(){
    delete PushButton;
}

void SwitchPulse::onTimerTick(){
    if(DecayTime > 0){
        DecayTime--;
    }
    if(DecayTime == 0){
        setState(false);
        //LogicGate::setOutput(false);
    }
}

void SwitchPulse::show() const{
    Switch::show();
    PushButton->show();
}

void SwitchPulse::onMouse(const Point& p){
    if((p > PushButton->getPosition())&&(p < (PushButton->getPosition() + PushButton->getSize()))){
        setState(true);
    }
}

void SwitchPulse::setPosition(const Point& pos){
    Switch::setPosition(pos);
    PushButton->setPosition(pos - Point(63,0));
}
