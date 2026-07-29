#ifndef MAUERSTUECK_H_INCLUDED
#define MAUERSTUECK_H_INCLUDED

#include "Paintable.h"
#include "Point.h"
#include "Mauer.h"

class Mauerstueck : public Paintable{
public:
    Mauer* zugeh_Mauer;

    Mauerstueck(Point position, Point size, Mauer* zugeh_Mauer);
    void paint();

};



#endif // MAUERSTUECK_H_INCLUDED
