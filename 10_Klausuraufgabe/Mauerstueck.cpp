#include "Mauerstueck.h"
#include "Mauer.h"
#include "Point.h"
#include "Paintable.h"
#include "WinAdapt.h"

Mauerstueck::Mauerstueck(Point uposition, Point usize, Mauer* uzugeh_Mauer)
            :Paintable(uposition,usize), zugeh_Mauer(uzugeh_Mauer)
{}


void Mauerstueck::paint(){
    Point linksunten(1,1);
    Point rechtsoben(1,1);

    if(zugeh_Mauer != nullptr){
        linksunten = zugeh_Mauer->position + position;
    }
    else{
        linksunten = position;
    }
    rechtsoben.X = linksunten.X + size.X;
    rechtsoben.Y = linksunten.Y - size.Y;

    LineCol(100,100,100);
    Rect(linksunten.X, linksunten.Y, rechtsoben.X, rechtsoben.Y);
}
