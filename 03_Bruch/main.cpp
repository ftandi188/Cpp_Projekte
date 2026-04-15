/*
 * Tests fuer die Klasse Bruch
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include "testlevel.h"
#include "bruch.h"

#define STABILITYTEST(testexpression) {\
    cout << "Stabilität: " \
         << ((testexpression) ? "OK" : "##Fehler: Operator darf Parameter nicht ändern!") \
         << endl << endl;}

#define REFERENCETEST(operator) {\
    cout << "Test auf Referenzen: " \
         << ( &tmp == &(tmp operator c) ? "OK" : "## Fehler! Referenzparamater bzw. Rückgabewerte fehlerhaft verwendet!") \
         << endl << endl;}

#define REFERENCETESTUNARY(testexpression) {\
    cout << "Test auf Referenzen: " \
         << ( (testexpression) ? "OK" : "## Fehler! Referenzparamater bzw. Rückgabewerte fehlerhaft verwendet!") \
         << endl << endl;}


using namespace std;

int main()
{
    srand(time(nullptr));
    {
	cout<<"---->Test: Verwendung von Konstruktor und print\n";
    int arg1=rand()%100;
	Bruch a;
	a.print(cout);
	cout << ", ";
	Bruch b(-1,arg1);
	b.print(cout);
	cout<<"\n(0/1), (-1/"<<arg1<<") = Zeile darueber\n\n";
    }


#if test_level >0
    {
	cout<<"---->Test: Get Methoden " << endl;
	Bruch a(1, 2);
	a.print(cout);
	cout << setprecision(6);
	cout << ": " << a.getZaehler() << " | " << a.getNenner() << " | "
	    << a.getValue()
	     << endl;
	cout<<"(1/2): 1 | 2 | 0.5 = Zeile darueber" << endl << endl;
	Bruch b(-1.0,-2.0);
	b.print(cout);
	cout << ": " << b.getZaehler() << " | " << b.getNenner() << " | "
	    << b.getValue()
	    << endl;
	cout<<"(-1/-2): -1 | -2 | 0.5 = Zeile darueber" << endl << endl;
	Bruch c(1.25,2.25);
	c.print(cout);
	cout << ": " << c.getZaehler() << " | " << c.getNenner() << " | "
	    << c.getValue()
	    << endl;
	cout<<"(1/2): 1 | 2 | 0.5 = Zeile darueber" << endl << endl;
    }
#endif

#if test_level >1
    {
	cout<<"---->Test: Ueberladene print-Methode " << endl;
	Bruch a(1.0,3.0);
	a.print(cout);
	cout << ": "; a.print(cout, 33);
	cout << " | "; a.print(cout, 3);
	cout << " | "; a.print(cout, 0);
	cout << endl;
	cout<<"(1/3): 0.333333333333333333333333333333333 | 0.333 | 0 = Zeile darueber" << endl << endl;
    }
#endif

#if test_level >2
    {
	Bruch b1(3, 4);
	Bruch b2(2, 6);
	Bruch b3(b1);
	cout << "---->Test fuer ueberladenen Ausgabeoperator " << endl << endl;
	cout << b1 << " --- ";
	cout << b2 << " --- ";
	cout << Bruch(0, 1) << endl;
	cout << "(3/4) --- (2/6) --- (0/1) = Zeile darueber" << endl << endl;
    }
#endif // test_level

#if test_level >3
    {
    const Bruch b1(3,4);
    //Bruch tmp=b1;
    cout << "---->Test fuer ueberladene Operatoren - und ~" << endl << endl;
    cout << "Vorzeichen (-)" << endl;
    cout << -b1 << endl;
    cout << "(-3/4) = Zeile darueber" << endl;
    //STABILITYTEST(tmp==b1);
    cout << "Kehrbruch (~)" << endl;
    cout << ~b1 << endl;
    cout << "(4/3) = Zeile darueber" << endl;
    //STABILITYTEST(tmp==b1);
    }
#endif

#if test_level >4
    {
	const Bruch b1(3,4);
	const Bruch b2(-2,3);
	//Bruch tmp=b1;
	//Bruch tmp2=b2;
	cout << "Multiplikation" << endl;
	cout << b1 << " * " << b2 << " = " << b1 * b2 << endl;
	cout << b1 << " * " << b2 << " = "
	    << "(-6/12) = Zeile darueber"  << endl << endl;
	cout << b1 << " * 2 = " << b1 * 2 << endl;
	cout << b1 << " * 2 = "
	    << "(6/4) = Zeile darueber" << endl << endl;
	cout << "2 * " << b2 << " = " << 2 * b2 << endl;
	cout << "2 * " << b2 << " = "
	    << "(-4/3) = Zeile darueber" << endl << endl;
	//STABILITYTEST(tmp==b1 && tmp2==b2);
    }
#endif

#if test_level >5
    {
	Bruch c(3,4);
	Bruch tmp=c;
    cout << "---->Test fuer ueberladene Zuweisungsoperatoren" << endl << endl;

    cout << "Zuweisung" << endl;
    cout << "*=" << endl;
    c *= Bruch(1,2);
    cout << c << endl;
    cout << "(3/8) = Zeile darueber" << endl;
    REFERENCETEST(*=)
    }
#endif

#if test_level >6
    {
    const Bruch c(1, 2), d(2, 3), e(2, 3), f(4,6);
    cout << "---->Test fuer ueberladene Vergleichsoperatoren" << endl << endl;

    cout << "==" << endl;
    cout << (c==d) << " --- " << (d==e) << " --- " << (e==f)<< endl;
    cout << "0 --- 1 --- 1 = Zeile darueber" << endl << endl;
}
#endif


#if test_level >7
    {
	Bruch c(3, 4);
	Bruch tmp=c;
	cout << "---->Test: Inkrement" << endl;
	cout << c++; cout << " --- " << c << endl;
	cout << "(3/4) --- (7/4) = Zeile darueber" << endl << endl;
	cout << ++c;
	cout << " --- " << c << endl;
	cout << "(11/4) --- (11/4) = Zeile darueber" << endl;
	REFERENCETESTUNARY(&tmp==&(++tmp));
    }
#endif

#if test_level >8
{
    const Bruch c(6, 8) ;
    Bruch d=c;
    cout << "---->Test: Kürzen" << endl;
    d.normalize();
    cout << "Original: " << c << " gekürzt: " << d << endl;
    cout << "Original: (6/8) gekürzt: (3/4) = Zeile darueber" << endl << endl;
}
#endif

    cout << "ENDE: Testlevel " << test_level << endl;

    return 0;
}


