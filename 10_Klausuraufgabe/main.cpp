#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include "WinAdapt.h"



char szStartString[128] = "Gestartet am ";   // für init
char szLaufzeit[128]; // für Zyk
int xMaus=-1, yMaus=-1;  // für Maus
char nKey[] = "X"; // für KeyHit

int aPoints[] = { 40,50, 30,70, 30,60, 10,90, 10,80, 0,80, 30,60, 20,60, 40,50 };
int nPoints = sizeof(aPoints)/sizeof(int)/2;
int i;


void VtlZyk(void)
{
    time_t tLaufzeit;
    struct tm tmStruktur;
    tLaufzeit = time(0);
    tmStruktur = *localtime(&tLaufzeit);
    sprintf(szLaufzeit, "Laufzeit: %d:%d:%d",
            tmStruktur.tm_hour, tmStruktur.tm_min, tmStruktur.tm_sec);
}

void VtlMouse(int X, int Y)
{
    xMaus=X;
    yMaus=Y;
}

void VtlKeyHit(int key)
{
    nKey[0] = key;
}

void VtlInit(void)
{
    time_t tStart;
    tStart = time(0);
    strcat(szStartString, ctime(&tStart));
    setWindowTitle("Mein WinAdapt-Test");
    setUpdateInterval(200);
}

void VtlPaint(int xl, int yo, int xr, int yu)
{
    Text(50, 5, szLaufzeit);      /* Zeichnet Text      */
    Text(50, 25, szStartString);   /* Zeichnet Text      */
    Line(xl, yo, xr, yu);          /* Zeichnet Linie     */
    LineCol(255, 10, 50);          /* Setzt Linienfarbe  */
    Elli(50, 50, xr-50, yu-50);    /* Zeichnet Ellipse   */
    LineCol(0, 0, 255);            /* Setzt Linienfarbe  */
    FillCol(200, 200, 255);        /* Setzt Flächenfarbe */
    Rect(100, 100, xr-100, yu-100);/* Zeichnet Rechteck  */
    FillCol(-1,-1,-1); /* Setzt Flächenfarbe transparent */
    Elli(50, 150, xr-50, yu-150);  /* Zeichnet Ellipse   */

    Text((xr-xl)/2, (yu-yo)/2, nKey);

    /* Zusatzfunktionen */
    FillCol(0, 255, 255);
    FillPoly(aPoints, nPoints);   /* Fuellt ein Polygon */
    for(i=0; i<100; i++) /* Färbt einzelne Pixel ein */
        PutPixel(i,   45+40*sin(3.14*i/50), RGB(255-2*i, 2*i,0));

    if(xMaus!=-1 && yMaus!=-1)
    {
        FillCol(100,50,50);
        Elli(xMaus, yMaus, xMaus+7, yMaus+7);
    }
}

