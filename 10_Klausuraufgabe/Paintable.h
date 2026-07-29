#ifndef PAINTABLE_H_INCLUDED
#define PAINTABLE_H_INCLUDED

#include "Point.h"

class Paintable{
public:
    Point position;
    Point size;

    Paintable(Point position, Point size);
    virtual void paint() = 0;
};



#endif // PAINTABLE_H_INCLUDED
