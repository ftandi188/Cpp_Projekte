#include "queueelement.h"
#include <iostream>

using namespace std;

QueueElement::QueueElement()
    : X(0), Y(0), Z(0),
      Previous(nullptr),
      Next(nullptr)
{
    Label[0] = '\0';    //leerer C‑String: Arrays müssen im Rumpf
}                       //initialisiert werden


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
