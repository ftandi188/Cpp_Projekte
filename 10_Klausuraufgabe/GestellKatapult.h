#ifndef GESTELLKATAPULT_H_INCLUDED
#define GESTELLKATAPULT_H_INCLUDED

#include "Paintable.h"
#include "Point.h"

class GestellKatapult : public Paintable{
public:
    int Skalierung;

    GestellKatapult(Point position, int Skalierung);
    void paint();


};


#endif // GESTELLKATAPULT_H_INCLUDED
