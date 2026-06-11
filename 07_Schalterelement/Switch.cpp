#include "Point.h"
#include "ColorBox.h"
#include "Switch.h"
#include "WinAdapt.h"

Switch::Switch()
        :State(0), Indicator(new ColorBox(Point(169,103),Point(30,30),RGBColor(255, 0, 0))),
         ColorBox(Point(100,100),Point(102,36),RGBColor(100,100,100))
        {}


Switch::Switch(const Switch& Source)
        :State(Source.State), Indicator(new ColorBox(Source.Indicator->getPosition(),
                                        Source.Indicator->getSize(),Source.Indicator->getColor())),
         ColorBox(Source.Position, Source.Size, Source.Color)
        {}

Switch::Switch(const Point& uPosition)
        :State(0), Indicator(new ColorBox(uPosition,Point(30,30),RGBColor(255, 0, 0))),
         ColorBox(Point(uPosition.X-69, uPosition.Y-3),Point(102,36),RGBColor(100,100,100))
        {}


Switch::~Switch(){
    delete Indicator;
}

void Switch::onMouse(const Point& Position){

}

void Switch::setPosition(const Point& uPosition){
    Indicator->ColorBox::setPosition(uPosition);
    Position = Point(uPosition.X-69, uPosition.Y-3);
}

bool Switch::getState() const{
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

void Switch::show() const{

    int Koordinaten[8];
    Rect(Position.X, Position.Y, Position.X + Size.X, Position.Y + Size.Y);

    Koordinaten[0] = Position.X;
    Koordinaten[1] = Position.Y;

    Koordinaten[2] = Position.X + Size.X;
    Koordinaten[3] = Position.Y;

    Koordinaten[4] = Position.X + Size.X;
    Koordinaten[5] = Position.Y + Size.Y;

    Koordinaten[6] = Position.X;
    Koordinaten[7] = Position.Y + Size.Y;

    FillCol(100, 100, 100);
    FillPoly(Koordinaten, 4);

    Indicator->show();
}

Switch& Switch::operator=(const Switch& rhs){
    if(this != &rhs){       //Verhindere Selbstzuweisung
        State = rhs.State;
        Position = rhs.Position;
        Size = rhs.Size;
        Color = rhs.Color;
        delete Indicator;

        Indicator = new ColorBox(rhs.Indicator->getPosition(), rhs.Indicator->getSize(), rhs.Indicator->getColor());
    }
    return *this;
}

