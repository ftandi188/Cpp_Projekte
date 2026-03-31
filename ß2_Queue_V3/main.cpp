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
    TestQueueElem = new QueueElement((char*)"Point 1", 1, 2, 3);
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
        TestQueueElem = new QueueElement(Labeltext.str().c_str(), i*2, i*i, 10000/(i+1));
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
        TestQueueElem = new QueueElement(Labeltext.str().c_str(), i*2, i*i, 10000/(i+1));
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
        TestQueueElem = new QueueElement(Labeltext.str().c_str(), i*2, i*i, 10000/(i+1));
        TestQueue->push(TestQueueElem);
    }

    delete TestQueue;
    TestQueue=nullptr;
    TestQueueElem=nullptr;

    std::cout << std::endl;
    std::cout << std::endl << "Test level 5 completed!" << std::endl << std::endl;
#endif

#if test_level >=6
    // insert tests for insert method here:

    std::cout << std::endl;
    std::cout << std::endl << "Test level 6 completed!"
              << std::endl << std::endl;

#endif
    return 0;
}
