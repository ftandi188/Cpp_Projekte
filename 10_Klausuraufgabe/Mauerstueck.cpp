#include "Mauerstueck.h"
#include "Mauer.h"
#include "Point.h"
#include "Paintable.h"
#include "WinAdapt.h"

Mauerstueck::Mauerstueck(Point uposition, Point usize, Mauer* uzugeh_Mauer)
            :Paintable(uposition,usize), zugeh_Mauer(uzugeh_Mauer)
{}


void Mauerstueck::paint(){
    Point linksoben(1,1);
    Point rechtsunten(1,1);

    if(zugeh_Mauer != nullptr){
        linksoben = zugeh_Mauer->position + position;
    }
    else{
        linksoben = position;
    }
    rechtsunten = linksoben + size;

    LineCol(100,100,100);
    Rect(linksoben.X, linksoben.Y, rechtsunten.X, rechtsunten.Y);
}
