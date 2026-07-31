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

Mauer M1(Point(200,200), Point(25,15), 7);
Mauer M2(Point(500,140), Point(10,40), 6);

GestellKatapult GK1(Point(200,600), 10);

Katapult K1(Point(200,600), 10, 0, 0);
Katapult K2(Point(200,300), 12, 0, 1);
Katapult K3(Point(600,600), 10, 1, 0);
Katapult K4(Point(600,300), 6, 1, 1);

void VtlZyk(void)
{
//K3.Zustand = 1;
//K3.Zustand = 0;

}

void VtlMouse(int X, int Y)
{

}

void VtlKeyHit(int key)
{
    if(key == 52){
        K3.Zustand = 1;
    }
    if(key == 53){
        K3.Zustand = 0;
    }
    if(key == 54){
        K3.Seite = 1;
    }
    if(key == 55){
        K3.Seite = 0;
    }
}

void VtlInit(void)
{

}

void VtlPaint(int xl, int yo, int xr, int yu)
{
//M1.paint();
//M2.paint();

//GK1.paint();

K1.paint();
K2.paint();
K3.paint();
K4.paint();
}

