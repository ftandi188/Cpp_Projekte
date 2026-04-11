#ifndef QUEUEELEMENT_H      //Include-Guard: Schutz vor Mehrfacheinbindung
#define QUEUEELEMENT_H

const unsigned LABELSIZE = 42;

class QueueElement{
public:

    char Label[LABELSIZE];
    int X,Y,Z;
    QueueElement* Previous;
    QueueElement* Next;

    QueueElement();
    QueueElement(const char* Label, int X, int Y, int Z,
                 QueueElement* Previous, QueueElement* Next);
    void print();
    QueueElement* getPrevious();
    QueueElement* getNext();
};

#endif // QUEUEELEMENT_H

