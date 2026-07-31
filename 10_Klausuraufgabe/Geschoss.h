#ifndef GESCHOSS_H_INCLUDED
#define GESCHOSS_H_INCLUDED

#include "Paintable.h"

class Geschoss : public Paintable{
public:
    Geschoss(Point position, Point size);
    void paint();
};

#endif // GESCHOSS_H_INCLUDED
