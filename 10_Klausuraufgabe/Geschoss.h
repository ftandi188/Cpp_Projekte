#ifndef GESCHOSS_H_INCLUDED
#define GESCHOSS_H_INCLUDED

#include "Paintable.h"

class Geschoss : public Paintable{
public:
    Point BackupOben;
    Point BackupUnten;
    double v0;
    int counter;

    Geschoss(Point position, Point size, double v0 = 10.0, int counter = 1);
    void paint();
};

#endif // GESCHOSS_H_INCLUDED
