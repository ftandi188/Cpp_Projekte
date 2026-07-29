#ifndef MAUER_H_INCLUDED
#define MAUER_H_INCLUDED

#include <vector>

#include "Paintable.h"
//#include "Mauerstueck.h"
#include "Point.h"

class Mauerstueck;

class Mauer : public Paintable{
public:
    std::vector<Mauerstueck*> Steine;

    Mauer(Point position, Point size);
    void paint();


};


#endif // MAUER_H_INCLUDED
