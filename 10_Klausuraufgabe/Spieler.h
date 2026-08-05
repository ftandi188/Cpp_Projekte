#ifndef SPIELER_H_INCLUDED
#define SPIELER_H_INCLUDED

#include "Mauer.h"
#include "Katapult.h"

class Spieler{
public:
    Mauer* MeineMauer;
    Katapult* MeinKatapult;

    Spieler(Point positionM, Point sizeM, int AnzahlM, Point positionK, int SkalierungK, bool SeiteK, bool ZustandK);
    void show();
    void abschiessen(double v0);

};

#endif // SPIELER_H_INCLUDED
