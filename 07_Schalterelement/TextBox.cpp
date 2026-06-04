#include "TextBox.h"
#include "ColorBox.h"
#include "WinAdapt.h"

TextBox::TextBox(const Point& uPosition, const Point& uSize, const std::string& uText)
                :ColorBox(uPosition,uSize, RGBColor(100,100,100)), Text(uText)  //Im Konstruktoraufruf der Basisklasse
                {}                                                              //ist wiederum der Konstruktoraufruf
                                                                                //von RGBColor verschachtelt
std::string TextBox::getText() const{
    return Text;
}

void TextBox::setText(const std::string& uText){
    Text = uText;
}

void TextBox::show() const{
    ColorBox::show();
    ::Text(Position.X + 10, Position.Y + 0.5*Size.Y, Text.c_str());     //:: hier zwingend, da ansonsten
}                                                                       //die gemeinte Methode Text vom
                                                                        //Attribut Text überschattet wird
