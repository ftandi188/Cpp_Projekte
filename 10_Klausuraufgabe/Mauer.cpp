#include "Mauer.h"
#include "Mauerstueck.h"
#include "Point.h"

Mauer::Mauer(Point uposition, Point usize, int uAnzahl)
            :Paintable(uposition, uposition)    //size der Mauer ist egal, einfach mit selben Wert belegen
{
    for(int i=0; i<uAnzahl; i++){
        Steine.push_back(new Mauerstueck(Point(0, i*(usize.Y)), usize, this));
    }
}


void Mauer::paint(){
    for(auto s : Steine){
        s->paint();
    }
}
