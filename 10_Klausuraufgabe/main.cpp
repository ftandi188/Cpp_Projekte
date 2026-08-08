#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include "WinAdapt.h"

#include "Mauer.h"
#include "Mauerstueck.h"
#include "Paintable.h"
#include "GestellKatapult.h"
#include "Katapult.h"
#include "Spieler.h"

Spieler Spieler1(Point(350, 400), Point(20,10), 10, Point(150, 400), 7, 0, 0);      //positionM, sizeM, AnzahlM, positionK, SkalierungK, SeiteK, ZustandK
Spieler Spieler2(Point(650, 400), Point(20,10), 8, Point(700, 400), 9, 1, 0);


void VtlZyk(void)
{


}

void VtlMouse(int X, int Y)
{

}

void VtlKeyHit(int key)
{
    if(key == 115){     //Taste s
        Spieler1.abschiessen(80.0, 9);
        Spieler2.abschiessen(130.0, 9);
        Spieler1.checkCollision(&Spieler2);
        Spieler2.checkCollision(&Spieler1);
    }

    if(key == 114){     //Taste r
        Spieler2.MeineMauer->Steine.erase(Spieler2.MeineMauer->Steine.begin() + 3);
    }   //Gegner->MeineMauer->Steine.erase(Gegner->MeineMauer->Steine.begin() + m);

}

void VtlInit(void)
{

}

void VtlPaint(int xl, int yo, int xr, int yu)
{
    Spieler1.show();
    Spieler2.show();
}

