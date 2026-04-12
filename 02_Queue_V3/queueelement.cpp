#include "queueelement.h"
#include <iostream>
#include <string.h>

using namespace std;

QueueElement::QueueElement()
    : X(0), Y(0), Z(0),
      Previous(nullptr),
      Next(nullptr)
{
    Label[0] = '\0';    //leerer C‑String: Arrays müssen im Rumpf
}                       //initialisiert werden

QueueElement::QueueElement(const char* L, int xpos, int ypos, int zpos,
                 QueueElement* pre, QueueElement* nex)
               : X(xpos), Y(ypos), Z(zpos),
                 Previous(pre), Next(nex)
            {
                int Laenge = strlen(L);
                if (Laenge < LABELSIZE){
                    strcpy(Label, L);       //Ziel, Quelle
                }
                else{
                    strncpy(Label, L, LABELSIZE);     //Ziel, Quelle, Obergrenze
                    Label[LABELSIZE - 1] = '\0';
                }
            }



void QueueElement::print(){
    cout << "QueueElement: ";
    cout << Label;
    cout << " (" << X << ", " << Y << ", " << Z << ")" << endl;
}


QueueElement* QueueElement::getPrevious(){
    return Previous;
}


QueueElement* QueueElement::getNext(){
    return Next;
}
