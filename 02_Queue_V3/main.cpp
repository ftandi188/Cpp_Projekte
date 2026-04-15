/*
 * Test application for queue implementation
 * Michael Niemetz (C) 2021
 */
#include <iostream>
#include <sstream>
#include <string>
#include "testlevel.h"
#include "queueelement.h"
#include "queue.h"


/* This macro (based on M. Farmbauer) simplifies the coding of tests.
 * The two parameters are first a condition to test (true indicating success) and
 * second a message, which is printed in case of a test failure. Such afailure will
 * abort the program. For examples, see below.
 */
#define test(cond, failure_message) {std::cout << "Test: (" << #cond << ") ... ";\
    if(cond) {std::cout << "OK" << std::endl;} \
    else {std::cout << failure_message << std::endl;; abort();}}

int main()
{
    QueueElement*  __attribute__((unused)) TestQueueElem ;
    std::cout << std::endl << "Test level 0 completed!" << std::endl << std::endl ;

// Basic tests for QueueElement
#if test_level >=1
    TestQueueElem = new QueueElement();
    TestQueueElem->print();
    test (TestQueueElem->getPrevious()==nullptr, "Konstruktor initialisiert Prev nicht korrekt.");
    test (TestQueueElem->getNext()==nullptr, "Konstruktor initialisiert Next nicht korrekt.");
    test (std::string(TestQueueElem->Label)=="", "Konstruktor initialisiert Label nicht korrekt.");
    test (TestQueueElem->X==0, "Konstruktor initialisiert X nicht korrekt.");
    test (TestQueueElem->Y==0, "Konstruktor initialisiert Y nicht korrekt.");
    test (TestQueueElem->Z==0, "Konstruktor initialisiert Z nicht korrekt.");
    delete TestQueueElem;
#endif

// Standard tests for QueueElement
#if test_level >=2
    std::cout << std::endl;
    TestQueueElem = new QueueElement((char*)"Point 1", 1, 2, 3, nullptr, nullptr);
    TestQueueElem->print();
    std::cout << " Prev: " << TestQueueElem->getPrevious()
              << ", Next: " << TestQueueElem->getNext()
              << std::endl;
    test (TestQueueElem->getPrevious()==nullptr, "Konstruktor initialisiert Prev nicht korrekt.");
    test (TestQueueElem->getNext()==nullptr, "Konstruktor initialisiert Next nicht korrekt.");
    test (std::string(TestQueueElem->Label)=="Point 1", "Konstruktor initialisiert Label nicht korrekt.");
    test (TestQueueElem->X==1, "Konstruktor initialisiert X nicht korrekt.");
    test (TestQueueElem->Y==2, "Konstruktor initialisiert Y nicht korrekt.");
    test (TestQueueElem->Z==3, "Konstruktor initialisiert Z nicht korrekt.");
    delete TestQueueElem;

    std::cout << std::endl;
    TestQueueElem = new QueueElement();
    TestQueueElem->print();
    std::cout << " Prev: " << TestQueueElem->getPrevious()
              << ", Next: " << TestQueueElem->getNext()
              << std::endl;
    test (TestQueueElem->getPrevious()==nullptr, "Konstruktor initialisiert Prev nicht korrekt.");
    test (TestQueueElem->getNext()==nullptr, "Konstruktor initialisiert Next nicht korrekt.");
    test (std::string(TestQueueElem->Label)=="", "Konstruktor initialisiert Label nicht korrekt.");
    delete TestQueueElem;

    std::cout << std::endl;
    TestQueueElem = new QueueElement((char*)"This label is exceeding the allowed label length and therefore should be truncated!",
                                     111, 222, 333, (QueueElement*)0xbaadf00d, (QueueElement*)0xcafecafe);
    TestQueueElem->print();
    std::cout << " Prev: " << TestQueueElem->getPrevious()
              << ", Next: " << TestQueueElem->getNext()
              << std::endl;
    test (TestQueueElem->getPrevious()==(QueueElement*)0xbaadf00d, "Konstruktor initialisiert Prev nicht korrekt / getPrevious liefert falschen Wert.");
    test (TestQueueElem->getNext()==(QueueElement*)0xcafecafe, "Konstruktor initialisiert Next nicht korrekt/ getNext liefert falschen Wert.");
    test (std::string(TestQueueElem->Label).size()==LABELSIZE-1, "Konstruktor kürzt Label nicht korrekt.");
    test (std::string(TestQueueElem->Label)=="This label is exceeding the allowed label", "Konstruktor initialisiert Label nicht korrekt.");
    test (TestQueueElem->X==111, "Konstruktor initialisiert X nicht korrekt.");
    test (TestQueueElem->Y==222, "Konstruktor initialisiert Y nicht korrekt.");
    test (TestQueueElem->Z==333, "Konstruktor initialisiert Z nicht korrekt.");
    std::cout << std::endl << "Test level 2 completed!" << std::endl << std::endl;
    delete TestQueueElem;
#endif

// Basic tests for Queue (empty)

#if test_level >=3
    Queue* TestQueue=nullptr;

    TestQueue = new Queue();
    test (TestQueue->FirstElement==nullptr, "Queue Konstruktor initialisiert FirstElement nicht korrekt.");
    test (TestQueue->LastElement==nullptr, "Queue Konstruktor initialisiert LastElement nicht korrekt.");
    test (TestQueue->getFirstElement()==TestQueue->FirstElement, "Queue::getFirstElement() liefert falschen Wert");
    test (TestQueue->getLastElement()==TestQueue->LastElement, "Queue::getLastElement() liefert falschen Wert");

    TestQueue->print();
    test (TestQueue->isEmpty()==true, "Queue::isEmpty() liefert falschen Wert!");
    test (TestQueue->size()==0, "Queue::size() liefert falschen Wert!");

    std::cout << std::endl;
    std::cout << std::endl << "Test level 3 completed!" << std::endl << std::endl;
#endif

// Standard tests for Queue (filled)

#if test_level >=4
    const unsigned MaxItemCnt=10;
    QueueElement* InitialElement=nullptr;
    for (unsigned i=0; i<MaxItemCnt; i++)
    {
        std::cout << std::endl << "Pushing element " << i << "..." << std::endl;
        std::stringstream Labeltext;
        Labeltext << "Item Number #" << i;
        TestQueueElem = new QueueElement(Labeltext.str().c_str(), i*2, i*i, 10000/(i+1), nullptr, nullptr);
        if (!InitialElement)
        {
            InitialElement=TestQueueElem;
        }
        TestQueue->push(TestQueueElem);
        TestQueue->print();
        test (!TestQueue->isEmpty(), "Queue::isEmpty() liefert falschen Wert!");
        test (TestQueue->size()==i+1, "Queue::size() liefert falschen Wert!");
        test (TestQueue->FirstElement==TestQueueElem, "FirstElement durch Queue::push() falsch gesetzt!");
        if (TestQueue->FirstElement->Next)
        {
            test (TestQueue->FirstElement->Next->Previous==TestQueue->FirstElement, "FirstElement durch Queue::push() falsch gesetzt!");
        }
        test (TestQueue->LastElement==InitialElement, "LastElement durch Queue::push() falsch gesetzt!");
    }

    unsigned j=MaxItemCnt;
    QueueElement* FinalElement=TestQueue->FirstElement;
    while (TestQueue->size())
    {
        std::cout << std::endl << "Removing element... " << std::endl;
        TestQueue->pop();
        j--;
        TestQueue->print();
        test (TestQueue->isEmpty() == !j, "Queue::isEmpty() liefert falschen Wert!");
        test (TestQueue->size()==j, "Queue::size() liefert falschen Wert!");
        test (TestQueue->FirstElement==FinalElement ||
              TestQueue->FirstElement==nullptr, "First:Element durch Queue::push() falsch gesetzt!");
    }

    std::cout << std::endl;
    std::cout << std::endl << "Test level 4 completed!" << std::endl << std::endl;
#endif

// Cleanup tests for Queue

#if test_level >=5
    std::cout << std::endl;
    for (unsigned i=0; i<MaxItemCnt; i++)
    {
        std::cout << "Pushing element " << i << "..." << std::endl;
        std::stringstream Labeltext;
        Labeltext << "Item Number #" << i;
        TestQueueElem = new QueueElement(Labeltext.str().c_str(), i*2, i*i, 10000/(i+1), nullptr, nullptr);
        TestQueue->push(TestQueueElem);
    }

    test (TestQueue->size()==MaxItemCnt, "Queue::size() liefert falschen Wert!");
    TestQueue->clear();
    test (TestQueue->size()==0, "Queue::size() liefert falschen Wert!");

    for (unsigned i=0; i<MaxItemCnt; i++)
    {
        std::cout << "Pushing element " << i << "..." << std::endl;
        std::stringstream Labeltext;
        Labeltext << "Item Number #" << i;
        TestQueueElem = new QueueElement(Labeltext.str().c_str(), i*2, i*i, 10000/(i+1), nullptr, nullptr);
        TestQueue->push(TestQueueElem);
    }

    delete TestQueue;
    TestQueue=nullptr;
    TestQueueElem=nullptr;

    std::cout << std::endl;
    std::cout << std::endl << "Test level 5 completed!" << std::endl << std::endl;
#endif

#if test_level >=6
    Queue* Liste = new Queue;          //leere Liste angelegt
    QueueElement* Elemente[10];

    for (int i=0; i<10; i++){
        Elemente[i] = new QueueElement();
    }

    std::cout << "Test a): Einfuegen eines Elements in leere Liste" << std::endl;
    Liste->insert(Elemente[0], 44);     //ein Element in leere Liste einfügen
    if((Liste->FirstElement == Elemente[0])&&(Liste->LastElement == Elemente[0])){
        std::cout << "Listenverwaltung passt" << std::endl;
    }
    if((Elemente[0]->Previous == nullptr)&&(Elemente[0]->Next == nullptr)){
        std::cout << "Pointer auf die Nachbarn stimmen" <<std::endl <<std::endl;
    }

    std::cout << "Test b): Einfuegen eines Elements am Anfang in Liste mit einem Element" << std::endl;
    Liste->insert(Elemente[1], 0);      //in Liste ist nun erst Elemente[1], dann Elemente[0]
    if((Liste->FirstElement == Elemente[1])&&(Liste->LastElement == Elemente[0])){
        std::cout << "Listenverwaltung passt" << std::endl;
    }
    if((Elemente[1]->Previous == nullptr)&&(Elemente[1]->Next == Elemente[0])){
        if((Elemente[0]->Previous == Elemente[1])&&(Elemente[0]->Next == nullptr)){
            std::cout << "Pointer auf die Nachbarn stimmen" <<std::endl <<std::endl;
        }
    }

    std::cout << "Test c): Einfuegen eines Elements am Ende in Liste mit einem Element" << std::endl;
    Liste->pop();       //Nun nur noch Elemente[1] in der Liste
    Liste->insert(Elemente[2], 1);      //in Liste ist nun erst Elemente[1], dann Elemente[2]
    if((Liste->FirstElement == Elemente[1])&&(Liste->LastElement == Elemente[2])){
        std::cout << "Listenverwaltung passt" << std::endl;
    }
    if((Elemente[1]->Previous == nullptr)&&(Elemente[1]->Next == Elemente[2])){
        if((Elemente[2]->Previous == Elemente[1])&&(Elemente[2]->Next == nullptr)){
            std::cout << "Pointer auf die Nachbarn stimmen" <<std::endl <<std::endl;
        }
    }

    Liste->clear();     //Liste zunächst geleert
    for (int i=6; i>=3; i--){
        Liste->push(Elemente[i]);   //Liste befüllen mit 4 Elementen (Elemente[3] bis Elemente[6])
    }
    std::cout << "Test d): Einfuegen eines Elements am Anfang in Liste mit vielen Elementen" << std::endl;
    Liste->insert(Elemente[7], 0);      //Abfolge 7,3,4,5,6
    if((Liste->FirstElement == Elemente[7])&&(Liste->LastElement == Elemente[6])){
        std::cout << "Listenverwaltung passt" << std::endl;
    }
    if((Elemente[7]->Previous == nullptr)&&(Elemente[7]->Next == Elemente[3])){
        if((Elemente[3]->Previous == Elemente[7])&&(Elemente[3]->Next == Elemente[4])){
            std::cout << "Pointer auf die Nachbarn stimmen" <<std::endl <<std::endl;
        }
    }

    std::cout << "Test e): Einfuegen eines Elements am Ende in Liste mit vielen Elementen" << std::endl;
    Liste->insert(Elemente[8], 23981);      //Abfolge 7,3,4,5,6,8
    if((Liste->FirstElement == Elemente[7])&&(Liste->LastElement == Elemente[8])){
        std::cout << "Listenverwaltung passt" << std::endl;
    }
    if((Elemente[8]->Previous == Elemente[6])&&(Elemente[8]->Next == nullptr)){
        std::cout << "Pointer auf die Nachbarn stimmen" <<std::endl <<std::endl;
    }

    std::cout << "Test f): Einfuegen eines Elements irgendwo in die Mitte" << std::endl;
    Liste->insert(Elemente[9], 4);      //Abfolge 7,3,4,5,9,6,8
    if((Elemente[9]->Previous == Elemente[5])&&(Elemente[9]->Next == Elemente[6])){
        if((Elemente[6]->Previous == Elemente[9])&&(Elemente[5]->Next == Elemente[9])){
            std::cout << "Pointer auf die Nachbarn stimmen" <<std::endl <<std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << std::endl << "Test level 6 completed!"
              << std::endl << std::endl;

#endif
    return 0;
}
