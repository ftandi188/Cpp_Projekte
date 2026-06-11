#include <iostream>
#include "SwitchToggle.h"
#include "TextBox.h"


SwitchToggle::SwitchToggle(const SwitchToggle& s)
            :ToggleButton(new TextBox(s.ToggleButton->getPosition(),s.ToggleButton->getSize(),s.ToggleButton->getText())),
             Switch(s)
{}

SwitchToggle::SwitchToggle(const Point& pos,const std::string& ToggleButtonLabel)
            :ToggleButton(new TextBox(Point(pos.X-66,pos.Y),Point(63,30),ToggleButtonLabel)),
             Switch(pos)
{}

SwitchToggle::~SwitchToggle(){
    delete ToggleButton;
}

void SwitchToggle::onMouse(const Point& p){
    if((p > ToggleButton->getPosition())&&(p < (ToggleButton->getPosition() + ToggleButton->getSize()))){
        if(getState() == true){
            setState(false);
        }
        else{
            setState(true);
        }
    }
}


void SwitchToggle::setPosition(const Point& p){
    Switch::setPosition(p);
    ToggleButton->setPosition(p - Point(66,0));
}

void SwitchToggle::show() const{
    Switch::show();
    ToggleButton->show();
}

SwitchToggle& SwitchToggle::operator=(const SwitchToggle& s){
    if(this != &s){
        Switch::operator=(s);

        delete ToggleButton;
        ToggleButton = new TextBox(s.ToggleButton->getPosition(),s.ToggleButton->getSize(),s.ToggleButton->getText());
    }
}
