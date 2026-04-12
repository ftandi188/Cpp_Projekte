#include "queue.h"
#include "queueelement.h"
#include <iostream>
#include <string.h>

using namespace std;


Queue::Queue()
        :FirstElement(nullptr), LastElement(nullptr)
        {}


Queue::Queue(QueueElement* InEl)
        :FirstElement(InEl), LastElement(InEl)      //Liste mit einem Element erstellt
        {}                                          //->zugleich erstes und letztes Element

QueueElement* Queue::getFirstElement(){
    return FirstElement;
}

QueueElement* Queue::getLastElement(){
    return LastElement;
}

unsigned Queue::size(){
    unsigned int Laenge = 0;

    if(FirstElement == nullptr){
        return 0;
    }
    QueueElement* Laufpointer;
    Laufpointer = FirstElement;

    while(Laufpointer != nullptr){
        Laufpointer = Laufpointer->Next;    //hierzu muss man "QueueElement.h" einbinden, ansonsten kennt
        Laenge++;                           //der Compiler hier den Inhalt eines Listenelements noch nicht!
    }
    return Laenge;
}

bool Queue::isEmpty(){
if (FirstElement == nullptr){
    return 1;
}
else{
    return 0;
}
}

void Queue::print(){
cout << "Queue" << endl << "<<>" << endl;

int Laufvar = 0;
QueueElement* Laufpointer = FirstElement;

while(Laufpointer != nullptr){
    cout << "<<" << Laufvar << ": ";
    Laufpointer->print();       //Aufruf der Methode über Pointer mit Pfeiloperator
                                //Da der Pointer vom Typ QueueElement* ist, weiß der Compiler,
                                //dass er die print-Methode dieser Klasse nehmen muss
    Laufpointer = Laufpointer->Next;
    Laufvar++;
}
}
