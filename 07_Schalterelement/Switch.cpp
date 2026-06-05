#include "Point.h"
#include "ColorBox.h"
#include "Switch.h"
#include "WinAdapt.h"

Switch::Switch()
        :State(0), Indicator(new ColorBox(Point(100,100),Point(30,30),RGBColor(255, 0, 0)))
        {}


Switch::Switch(const Switch& Source)
        :State(Source.State), Indicator(new ColorBox(Source.Indicator->getPosition(),
                                        Source.Indicator->getSize(),Source.Indicator->getColor()))
        {}

Switch::Switch(const Point& uPosition)
        :State(0), Indicator(new ColorBox(uPosition,Point(30,30),RGBColor(255, 0, 0)))
        {}


Switch::~Switch(){
    delete Indicator;
}

void Switch::onMouse(Point& Position){

}

void Switch::setPosition(const Point& uPosition){
    Indicator->ColorBox::setPosition(uPosition);
}

bool Switch::getState(){
    return State;
}

void Switch::setState(bool uState){
    State = uState;
    RGBColor Gruen(0,255,0);
    RGBColor Rot(255,0,0);
    if(State==true){
        Indicator->setColor(Gruen);
    }
    else{
       Indicator->setColor(Rot);
    }
}

void Switch::show(){
    Point Referenz = Indicator->getPosition();

    int Koordinaten[8];
    Rect(Referenz.X - 70, Referenz.Y - 2, Referenz.X + 32, Referenz.Y + 32);

    Koordinaten[0] = Referenz.X - 70;
    Koordinaten[1] = Referenz.Y - 2;

    Koordinaten[2] = Referenz.X + 32;
    Koordinaten[3] = Referenz.Y - 2;

    Koordinaten[4] = Referenz.X + 32;
    Koordinaten[5] = Referenz.Y + 32;

    Koordinaten[6] = Referenz.X - 70;
    Koordinaten[7] = Referenz.Y + 32;

    FillCol(100, 100, 100);
    FillPoly(Koordinaten, 4);

    Indicator->show();
}

Switch& Switch::operator=(Switch& rhs){
    if(this == &rhs){       //Verhindere Selbstzuweisung
        State = rhs.State;
        delete Indicator;

        Indicator = new ColorBox(rhs.Indicator->getPosition(), rhs.Indicator->getSize(), rhs.Indicator->getColor());
    }
}
