#ifndef SPIELER_H_INCLUDED
#define SPIELER_H_INCLUDED

#include "Mauer.h"
#include "Katapult.h"

class Spieler{
public:
    Mauer* MeineMauer;
    Katapult* MeinKatapult;

    Spieler();
    Spieler(Point positionM, Point sizeM, int AnzahlM, Point positionK, int SkalierungK, bool SeiteK, bool ZustandK);
    Spieler& operator=(Spieler& other);

    void show();
    void abschiessen(double v0, int Schrittweite, Spieler* Gegner);
    void checkCollision(Spieler* Gegenspieler);

    void KatapultNachOben();
    void KatapultNachUnten();
    void KatapultNachLinks();
    void KatapultNachRechts();

    void SkaliereHoch();
    void SkaliereRunter();

};

#endif // SPIELER_H_INCLUDED
