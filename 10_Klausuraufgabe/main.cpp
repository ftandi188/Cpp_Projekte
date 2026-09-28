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
    if(key == 'a'){
        Spieler1.abschiessen(80.0, 9, &Spieler2);
        Spieler1.checkCollision(&Spieler2);
    }

    if(key == 'd'){
        Spieler2.abschiessen(20.0, 9, &Spieler1);
        Spieler2.checkCollision(&Spieler1);
    }

    if(key == 'e'){
        Spieler1.KatapultNachLinks();
    }
    if(key == 'r'){
        Spieler1.KatapultNachRechts();
    }
    if(key == 't'){
        Spieler1.KatapultNachOben();
    }
    if(key == 'z'){
        Spieler1.KatapultNachUnten();
    }
    if(key == 'u'){
        Spieler2.KatapultNachLinks();
    }
    if(key == 'i'){
        Spieler2.KatapultNachRechts();
    }
    if(key == 'o'){
        Spieler2.KatapultNachOben();
    }
    if(key == 'p'){
        Spieler2.KatapultNachUnten();
    }

    if(key == '6'){
        Spieler1.SkaliereHoch();
    }
    if(key == '7'){
        Spieler1.SkaliereRunter();
    }
    if(key == '8'){
        Spieler2.SkaliereHoch();
    }
    if(key == '9'){
        Spieler2.SkaliereRunter();
    }

    if(key == '1'){
        Spieler1.MauerNachLinks();
    }
    if(key == '2'){
        Spieler1.MauerNachRechts();
    }
    if(key == '3'){
        Spieler1.MauerNachOben();
    }
    if(key == '4'){
        Spieler1.MauerNachUnten();
    }
    if(key == 'y'){
        Spieler1.MauerBreiter();
    }
    if(key == 'x'){
        Spieler1.MauerSchmaeler();
    }
    if(key == 'c'){
        Spieler1.MauerHoeher();
    }
    if(key == 'v'){
        Spieler1.MauerNiedriger();
    }
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

