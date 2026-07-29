#ifndef MAUER_H_INCLUDED
#define MAUER_H_INCLUDED

#include <vector>

#include "Paintable.h"
//#include "Mauerstueck.h"          //Hier muss es die Kurzdeklaration sein, ansonsten unendliche Schleife
#include "Point.h"

class Mauerstueck;

class Mauer : public Paintable{
public:
    std::vector<Mauerstueck*> Steine;

    Mauer(Point position, Point size, int Anzahl);
    void paint();


};


#endif // MAUER_H_INCLUDED
