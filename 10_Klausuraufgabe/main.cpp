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

Spieler Spieler1(Point(350, 600), Point(20,10), 12, Point(150, 600), 7, 0, 0);



void VtlZyk(void)
{


}

void VtlMouse(int X, int Y)
{

}

void VtlKeyHit(int key)
{

}

void VtlInit(void)
{

}

void VtlPaint(int xl, int yo, int xr, int yu)
{
    Spieler1.show();
}

