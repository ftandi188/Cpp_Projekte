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

Mauer M1(Point(200,200), Point(25,15), 7);
Mauer M2(Point(500,140), Point(10,40), 6);

GestellKatapult K1(Point(200,600), 10);

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
//M1.paint();
//M2.paint();

K1.paint();
}

