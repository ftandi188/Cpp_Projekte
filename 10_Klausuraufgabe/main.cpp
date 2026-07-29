#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include "WinAdapt.h"

#include "Mauer.h"
#include "Mauerstueck.h"
#include "Paintable.h"

Mauerstueck Stein1(Point(200,200), Point(15,15), nullptr);


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
Stein1.paint();
}

