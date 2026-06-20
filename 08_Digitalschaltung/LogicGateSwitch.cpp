#include "testlevel.h"
#include "LogicGateSwitch.h"
#include "SwitchOnOff.h"
#include "SwitchToggle.h"
#include "SwitchPulse.h"
#include "LogicExceptions.h"

LogicGateSwitch::LogicGateSwitch(const string& Label, const Point& Position, const string& ID, unsigned int Type, int Timing)
                :LogicGate(Label, Position, ID, 0, Point(176,42))
{
    if(Type == 0){                          //eigentlich:(Position.X + 70, Position.Y + 3)
        SwitchElement = new SwitchOnOff(Point(Position.X + 139, Position.Y + 6));
        TimedSwitchElement = nullptr;
    }
    if(Type == 1){
        SwitchElement = new SwitchToggle(Point(Position.X + 139, Position.Y + 6));
        TimedSwitchElement = nullptr;
    }
    if(Type == 2){
        SwitchElement = new SwitchPulse(Point(Position.X + 139, Position.Y + 6), "Push", Timing);
        TimedSwitchElement = static_cast<SwitchPulse*>(SwitchElement);
    }

    //this->Size = Point(SwitchElement->getSize().X + 73, SwitchElement->getSize().Y + 6);        //umrandendes Rechteck
                                                                                                  //Braucht man nicht mehr wegen angepasstem Konstruktor
}

LogicGateSwitch::~LogicGateSwitch(){
    delete SwitchElement;
}

void LogicGateSwitch::updateOutput(){

}

void LogicGateSwitch::onMouse(const Point& where){
    SwitchElement->onMouse(where);
    setOutput(SwitchElement->getState());
}

void LogicGateSwitch::decorate() const{
    SwitchElement->show();
}

void LogicGateSwitch::clock(){
    if(TimedSwitchElement != nullptr){
        TimedSwitchElement->onTimerTick();
        if(TimedSwitchElement->DecayTime == 0){
            setOutput(false);
        }
    }
}
