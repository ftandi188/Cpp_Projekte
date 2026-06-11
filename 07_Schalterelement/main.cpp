#include <iostream>
#include <iomanip>
#include "testlevel.h"
#include "Point.h"
#include "RGBColor.h"
#include "WinAdapt.h"
#if TEST_LEVEL >= TEST_COLORBOX
#include "ColorBox.h"
#endif
#if TEST_LEVEL >= TEST_TEXTBOX
#include "TextBox.h"
#endif
#if TEST_LEVEL >= TEST_SWITCH
#include "Switch.h"
#endif
#if TEST_LEVEL >= TEST_SWITCH_ONOFF
#include "SwitchOnOff.h"
#endif
#if TEST_LEVEL >= TEST_SWITCH_TOGGLE
#include "SwitchToggle.h"
#endif
#if TEST_LEVEL >= TEST_SWITCH_PULSE
#include "SwitchPulse.h"
#endif

using namespace std;

/* Diese Makrodefinition beinhaltet einen kleinen Codegenerator. Das Makro wird
 * mit zwei Parametern aufgerufen, nämlich der Bedingung, welche getestet werden soll, und
 * dem Text, der zur Erläuterung ausgegeben werden soll. Daraus wird dann je nach
 * Testergebnis eine Meldung ausgegeben und ggf. das Programm abgebrochen.
 */
#define test(cond, description) {cout <<"   " << setw(50) << left << description;\
    if(cond) {cout << " OK"<<endl;} else {cout << " FAILED"<<endl;abort();}}


#if TEST_LEVEL >= TEST_COLORBOX
ColorBox f(Point(100, 100), Point(300, 200), RGBColor(100, 220, 100));
#endif

#if TEST_LEVEL >= TEST_TEXTBOX
TextBox t(Point(100, 100), Point(100, 30), "Hello World!");
#endif

#if TEST_LEVEL >= TEST_SWITCH
Switch s(Point(163, 100));      //Geändert
Switch s2(Point(100, 200));
Switch s3(Point(100, 300));
#endif

#if TEST_LEVEL >= TEST_SWITCH_ONOFF
SwitchOnOff soo(Point(100, 100), "On", "Off");
#endif

#if TEST_LEVEL >= TEST_SWITCH_TOGGLE
SwitchToggle st(Point(100, 100), "On/Off");
#endif

#if TEST_LEVEL >= TEST_SWITCH_PULSE
SwitchPulse sp(Point(100, 100), "Push");
#endif

#if TEST_LEVEL == TEST_ALL
#define NUM_SWITCHES 20                                 //Initialisierung
Switch* sArray[NUM_SWITCHES]={nullptr};
SwitchPulse* spArray[NUM_SWITCHES]={nullptr};
int CntrSP=0;
#endif

void VtlZyk(void)
{
#if TEST_LEVEL >= TEST_SWITCH_PULSE
    sp.onTimerTick();
#endif
#if TEST_LEVEL == TEST_ALL
    for (int i=0; i<CntrSP; i++)
    {
        spArray[i]->onTimerTick();
    }
#endif // TEST_LEVEL
}

void VtlMouse(int X, int Y)
{
#if TEST_LEVEL >= TEST_SWITCH_ONOFF
    soo.onMouse(Point(X, Y));
#endif

#if TEST_LEVEL >= TEST_SWITCH_TOGGLE
    st.onMouse(Point(X, Y));
#endif

#if TEST_LEVEL >= TEST_SWITCH_PULSE
    sp.onMouse(Point(X, Y));
#endif

#if TEST_LEVEL == TEST_ALL
    Point m(X, Y);
    for (int i=0;i<NUM_SWITCHES;i++)
    {
        sArray[i]->onMouse(m);
    }
#endif
}

void VtlKeyHit(int key)
{
}

void VtlInit(void)
{
    setWindowTitle("Switch");
    cout << "test_level: " << TEST_LEVEL << endl;


#if TEST_LEVEL == TEST_COLORBOX
    {
	cout << "** Teste Klasse ColorBox **" << endl;

	Point Pos(100, 100), Size(300, 200);
	RGBColor C(50, 100, 200);
	ColorBox f(Pos, Size, C); // test Konstruktor
	ColorBox ff(f); // test Kopie
	test( (f.getPosition()==Pos), "ColorBox::getPos()");
	test( (f.getSize()==Size), "ColorBox::getSize()");
	test( (f.getColor()==C), "ColorBox::getFarbe()");
	Point newPos(150, 150), newSize(350, 250);
	RGBColor newC(3, 22, 111);
	f.setPosition(newPos);
	test( (f.getPosition()==newPos), "ColorBox::setPos()");
	f.setSize(newSize);
	test( (f.getSize()==newSize), "ColorBox::setSize()");
	f.setColor(newC);
	test( (f.getColor()==newC), "FarbRect::setFarbe()");
    }
#endif

#if TEST_LEVEL == TEST_TEXTBOX
    {
	cout << "** Teste Klasse TextBox **" << endl;

	Point Pos(120, 120), Size(200, 100);
	RGBColor C(100, 50, 200);
	TextBox t(Pos, Size, "testing TextBox"); // test Konstruktor
	ColorBox tt(t); // test Kopie
	test( (t.getText()=="testing TextBox"), "TextBox::getText()");
	test( (t.setText("testing textBox: new text"), t.getText()=="testing textBox: new text"), "TextBox::setText()");
    }
#endif

#if TEST_LEVEL == TEST_SWITCH
    {
        cout << "** Teste Klasse Switch **" << endl;
        Switch NewSwitch(s); // test Copy Constructor
        Switch* TempSwitch(new Switch(s));
        NewSwitch.setPosition(Point(100,300));
        NewSwitch.setState(true);
        TempSwitch->setPosition(Point(30,50));
        TempSwitch->setState(false);
        delete TempSwitch;
        NewSwitch.setPosition(Point(200,200));
        s2.setState(true);
        s3.setState(false);
    }
#endif

#if TEST_LEVEL == TEST_SWITCH_ONOFF
    {
        cout << "** Teste Klasse Switch **" << endl;
        SwitchOnOff NewSwitch(soo); // test Copy Constructor
        SwitchOnOff* TempSwitch(new SwitchOnOff(soo));
        NewSwitch.setPosition(Point(100,300));
        NewSwitch.setState(true);
        TempSwitch->setPosition(Point(30,50));
        TempSwitch->setState(false);
        delete TempSwitch;
        NewSwitch.setPosition(Point(200,200));
    }
#endif

#if TEST_LEVEL == TEST_SWITCH_TOGGLE
    {
        cout << "** Teste Klasse Switch **" << endl;
        SwitchToggle NewSwitch(st); // test Copy Constructor
        SwitchToggle* TempSwitch(new SwitchToggle(st));
        NewSwitch.setPosition(Point(100,300));
        NewSwitch.setState(true);
        TempSwitch->setPosition(Point(30,50));
        TempSwitch->setState(false);
        delete TempSwitch;
        NewSwitch.setPosition(Point(200,200));
    }
#endif

#if TEST_LEVEL == TEST_ALL
    Point p(s.getPosition());               //Referenzpunkt

    for (int i=0;i<NUM_SWITCHES;i++)
    {
        Point d(10+130*(i/5), 50*(i%5)+10*(i/5));       //x-Koord.: int-Division, Faktor ist: 0,0,0,0,0,1,1,1,1,1,2,...
                                                        //y-Koord.: modulo, damit es immer wieder zurückspringt, hintere
                                                        //Komponente bewirkt Offset zwischen den Spalten


        switch (i%4)        //Versatz, da hier 4er Prinzip, beim Ausgaberaster aber 5er Prinzip
        {
            case 0:
            sArray[i]=new Switch(Point(1,1));
            break;
            case 1:
            sArray[i]=new SwitchOnOff(Point(1,1));
            break;
            case 2:
            sArray[i]=new SwitchToggle(Point(1,1));
            break;
            case 3:
            spArray[CntrSP++]=new SwitchPulse(Point(1,1), "Press", 3);
            sArray[i]=spArray[CntrSP-1];
            break;
        }
        sArray[i]->setPosition(Point(p + d));
    }
#endif

#if TEST_LEVEL == TEST_DESTRUCTOR
    {
        cout << "** Teste Destruktor **" << endl;
        Switch* TempSwitch(new SwitchToggle(Point(100,100)));
        TempSwitch->setPosition(Point(30,50));
        TempSwitch->setState(false);
        delete TempSwitch;
    }
#endif
}

void VtlPaint(int xl, int yo, int xr, int yu)
{
#if TEST_LEVEL == TEST_COLORBOX
    f.show();
#endif

#if TEST_LEVEL == TEST_TEXTBOX
    t.show();
#endif

#if TEST_LEVEL == TEST_SWITCH
    s.show();
    s2.show();
    s3.show();
#endif

#if TEST_LEVEL == TEST_SWITCH_ONOFF
    soo.show();
#endif

#if TEST_LEVEL == TEST_SWITCH_TOGGLE
    st.show();
#endif
#if TEST_LEVEL == TEST_SWITCH_PULSE
    sp.show();
#endif

#if TEST_LEVEL == TEST_ALL
    for (int i=0;i<NUM_SWITCHES;i++) {
	sArray[i]->show();                  //Ausgabe aller Switches
    }
#endif
}

