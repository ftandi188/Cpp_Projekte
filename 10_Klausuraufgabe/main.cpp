#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include "WinAdapt.h"

#include "Mauer.h"
#include "Mauerstueck.h"
#include "Paintable.h"
#include "GestellKatapult.h"
#include "Katapult.h"
#include "Spieler.h"

Spieler Spieler1;
Spieler Spieler2;


void VtlZyk(void)
{


}

void VtlMouse(int X, int Y)
{

}

void VtlKeyHit(int key)
{
    if(key == 97){     //Taste a
        Spieler1.abschiessen(80.0, 9, &Spieler2);
        Spieler1.checkCollision(&Spieler2);
    }

    if(key == 100){     //Taste d
        Spieler2.abschiessen(20.0, 9, &Spieler1);
        Spieler2.checkCollision(&Spieler1);
    }

    /*
    if(key == 114){     //Taste r
        Spieler2.MeineMauer->Steine.erase(Spieler2.MeineMauer->Steine.begin() + 3);
    }
    */
}


void VtlInit(void)
{
    Point positionM1(1,1);
    Point positionM2(1,1);
    Point sizeM1(1,1);
    Point sizeM2(1,1);
    int AnzahlM1;
    int AnzahlM2;
    Point positionK1(1,1);
    Point positionK2(1,1);
    int SkalierungK1;
    int SkalierungK2;
    bool SeiteK1;
    bool SeiteK2;
    bool ZustandK1;
    bool ZustandK2;

    std::cout << "Gib xPosition von Mauer1 an\n";
    std::cin >> positionM1.X;
    std::cout << "Gib xPosition von Mauer2 an\n";
    std::cin >> positionM2.X;

    std::cout << "Gib Breite der Steine von Mauer1 an\n";
    std::cin >> sizeM1.X;
    std::cout << "Gib Höhe der Steine von Mauer1 an\n";
    std::cin >> sizeM1.Y;

    std::cout << "Gib Breite der Steine von Mauer2 an\n";
    std::cin >> sizeM2.X;
    std::cout << "Gib Höhe der Steine von Mauer2 an\n";
    std::cin >> sizeM2.Y;

    std::cout << "Gib Anzahl der Steine von Mauer1 an\n";
    std::cin >> AnzahlM1;
    std::cout << "Gib Anzahl der Steine von Mauer2 an\n";
    std::cin >> AnzahlM2;

    std::cout << "Gib xPosition von Katapult1 an\n";
    std::cin >> positionK1.X;
    std::cout << "Gib xPosition von Katapult2 an\n";
    std::cin >> positionK2.X;

    std::cout << "Gib Skalierung von Katapult1 an\n";
    std::cin >> SkalierungK1;
    std::cout << "Gib Skalierung von Katapult2 an\n";
    std::cin >> SkalierungK2;

Spieler TempSpieler1(Point(positionM1.X, 400), sizeM1, AnzahlM1, Point(positionK1.X, 400), SkalierungK1, 0, 0);      //positionM, sizeM, AnzahlM, positionK, SkalierungK, SeiteK, ZustandK
Spieler TempSpieler2(Point(positionM2.X, 400), sizeM2, AnzahlM2, Point(positionK2.X, 400), SkalierungK2, 1, 0);

Spieler1 = TempSpieler1;
Spieler2 = TempSpieler2;
}


void VtlPaint(int xl, int yo, int xr, int yu)
{
    Spieler1.show();
    Spieler2.show();
}

