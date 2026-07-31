#ifndef KATAPULT_H_INCLUDED
#define KATAPULT_H_INCLUDED

#include "GestellKatapult.h"
#include "Geschoss.h"


class Katapult : public GestellKatapult{
public:
    bool Seite;         //0: Katapult steht links und schieﬂt nach rechts, 1 die andere Seite
    bool Zustand;       //0: Ausgangsstellung, 1: Abschussstellung

    Geschoss* Schussobjekt;

    Katapult(Point position, int Skalierung, bool Seite, bool Zustand);
    void paint();

};

#endif // KATAPULT_H_INCLUDED
