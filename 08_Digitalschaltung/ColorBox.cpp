#include "ColorBox.h"
#include "WinAdapt.h"

ColorBox::ColorBox(const Point& uPosition, const Point& uSize, const RGBColor& uColor)
                :Position(uPosition), Size(uSize), Color(uColor)
                {}

Point ColorBox::getPosition() const{
    return Position;
}

Point ColorBox::getSize() const{
    return Size;
}

RGBColor ColorBox::getColor() const{
    return Color;
}

void ColorBox::setPosition(const Point& p){
    Position = p;
}

void ColorBox::setSize(const Point& s){
    Size = s;
}

void ColorBox::setColor(const RGBColor& c){
    Color = c;
}

bool ColorBox::contains(const Point& f) const{
    if((f > Position)&&(f < (Position+Size))){
        return true;
    }
    return false;
}

void ColorBox::show() const{
    int Koordinaten[8];
    Rect(Position.X, Position.Y, (Position+Size).X, (Position+Size).Y);

    Koordinaten[0] = Position.X;
    Koordinaten[1] = Position.Y;

    Koordinaten[2] = (Position+Size).X;
    Koordinaten[3] = Position.Y;

    Koordinaten[4] = (Position+Size).X;
    Koordinaten[5] = (Position+Size).Y;

    Koordinaten[6] = Position.X;
    Koordinaten[7] = (Position+Size).Y;

    FillCol(Color.R, Color.G, Color.B);
    FillPoly(Koordinaten, 4);
}
