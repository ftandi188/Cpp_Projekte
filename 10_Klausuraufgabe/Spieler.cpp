#include "Spieler.h"
#include "Katapult.h"

Spieler::Spieler(Point upositionM, Point usizeM, int uAnzahlM, Point upositionK, int uSkalierungK, bool uSeiteK, bool uZustandK)
                :MeineMauer(new Mauer(upositionM, usizeM, uAnzahlM)),
                 MeinKatapult(new Katapult(upositionK, uSkalierungK, uSeiteK, uZustandK))
{}


void Spieler::show(){
    MeineMauer->paint();
    MeinKatapult->paint();
}
