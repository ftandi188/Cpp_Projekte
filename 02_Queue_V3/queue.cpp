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


void Queue::push(QueueElement* NewIt){
    if(FirstElement == nullptr){        //Sonderfall: Liste bisher leer
        FirstElement = NewIt;           //First und LastElement sind das eine Objekt
        LastElement = NewIt;

        NewIt->Previous = nullptr;      //Im Objekt sind Previous- und Nextpointer die Nullpointer,
        NewIt->Next = nullptr;          //weil es davor und danach nichts gibt
    }
    else{                               //Normalfall: Liste hat bereits mindestens 1 Element
        FirstElement->Previous = NewIt; //bisheriges Firstelement zeigt nun auf seinen neuen Vorgänger

        NewIt->Previous = nullptr;      //Previous vom neuen Element zeigt auf nichts
        NewIt->Next = FirstElement;     //Next vom neuen Element zeigt auf bisheriges Firstelement (Nun an 2.Stelle)

        FirstElement = NewIt;           //Firstelement in Queue mit neuem Pointer überschreiben
    }
}


void Queue::pop(){
    int Flag = 0;
    QueueElement* Zwischenpointer = nullptr;

    if((FirstElement == LastElement)&&(FirstElement == nullptr)){   //Nichts in der Liste --> Nichts, was man löschen könnte
        Flag = 1;
    }

    if((FirstElement == LastElement)&&(FirstElement != nullptr)){   //Genau ein Element in der Liste
        delete FirstElement;        //Speicher freigeben

        FirstElement = nullptr;
        LastElement = nullptr;

        Flag = 1;
    }

    if(Flag == 0){
        Zwischenpointer = LastElement->Previous;    //Pointer auf vorletztes Element
        Zwischenpointer->Next = nullptr;            //Neues Ende der Liste markieren

        delete LastElement;     //Speicher freigeben (muss man machen, bevor man den Pointer überschreibt!)

        LastElement = Zwischenpointer;              //Listeneinstieg am Ende richtig setzen
    }
}


void Queue::clear(){
    unsigned Laenge = size();

    for(int i=0; i<Laenge; i++){
        pop();
    }
}


Queue::~Queue(){
    QueueElement* Zwischenspeicher;
    QueueElement* Laufpointer = FirstElement;

    while(Laufpointer != nullptr){
        Zwischenspeicher = Laufpointer->Next;
        delete Laufpointer;
        Laufpointer = Zwischenspeicher;
    }
}
