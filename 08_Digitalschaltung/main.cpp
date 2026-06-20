#include <iostream>
#include <iomanip>
#include "WinAdapt.h"
#include "testlevel.h"
#include "Point.h"

#if TEST_LEVEL == TEST_START
#include "SwitchOnOff.h"
#include "SwitchToggle.h"
#endif

#if TEST_LEVEL >= TEST_CIRCUIT_AVAILABLE
#include "Circuit.h"
#endif

#include "Oscillator.h"
#include "SimpleGates.h"
#include "ComplexGates.h"

#if TEST_LEVEL >= TEST_GATESWITCH
#include "LogicGateSwitch.h"
#endif

using namespace std;

/* Diese Makrodefinition beinhaltet einen kleinen Codegenerator. Das Makro wird
 * mit zwei Parametern aufgerufen, nämlich der Bedingung, welche getestet werden soll, und
 * dem Text, der zur Erläuterung ausgegeben werden soll. Daraus wird dann je nach
 * Testergebnis eine Meldung ausgegeben und ggf. das Programm abgebrochen.
 */
#define test(cond, description) {cout <<"   " << setw(50) << left << description;\
    if(cond) {cout << " OK"<<endl;} else {cout << " FAILED"<<endl;abort();}}

#define BOARDTIMER 10

#if TEST_LEVEL == TEST_START
SwitchOnOff MyOnOffSwitch(Point(10,10));
SwitchToggle MyToggleSwitch(Point(10, 110));
#endif

#if TEST_LEVEL == TEST_LOGICGATECOMM
LogicGate GateA("???", Point(10,10), "Gate A");
LogicGate GateB("???", Point(200, 100), "Gate B");
#endif // TEST_LEVEL

#if TEST_LEVEL == TEST_SIMPLEGATES
LogicGateAND GateAND(Point(10,10), "G1");
LogicGateOR GateOR(Point(10,110), "G2");
LogicGateNAND GateNAND(Point(200,10), "G3");
LogicGateXOR GateXOR(Point(230,110), "G4");
LogicGateNOT GateNOT(Point(410,110), "G5");
#endif // TEST_LEVEL

#if TEST_LEVEL == TEST_GATESWITCH
LogicGateSwitch SW1("IN1", Point(20, 10), "SW1", 0);
LogicGateSwitch SW2("IN2", Point(20, 60), "SW2", 1);
LogicGateSwitch SW3("IN3", Point(20, 110), "SW3", 0);
LogicGateSwitch SW4("IN4", Point(20, 160), "SW4", 2, 600);
LogicGateAND GateAND(Point(220, 20), "G1");
LogicGateOR GateOR(Point(220, 120), "G2");
LogicGateXOR GateXOR(Point(390, 100), "G3");
LogicGateNAND GateNAND(Point(530, 60), "G5");


#endif // TEST_LEVEL

#if TEST_LEVEL >= TEST_CIRCUIT_AVAILABLE
Circuit MyCircuit(1000/BOARDTIMER);         //Nutze ich ebenfalls für eigene Schaltung
#endif



void VtlZyk(void)
{
#if TEST_LEVEL == TEST_GATESWITCH
    SW1.clock();
    SW2.clock();
    SW3.clock();
    SW4.clock();
#endif
#if TEST_LEVEL >= TEST_CIRCUIT_AVAILABLE
    MyCircuit.clock();
#endif
}

void VtlMouse(int X, int Y)
{
#if TEST_LEVEL == TEST_START
    MyOnOffSwitch.onMouse(Point(X, Y));
    MyToggleSwitch.onMouse(Point(X, Y));
#endif
#if TEST_LEVEL == TEST_GATESWITCH
    SW1.onMouse(Point(X, Y));
    SW2.onMouse(Point(X, Y));
    SW3.onMouse(Point(X, Y));
    SW4.onMouse(Point(X, Y));
#endif
#if TEST_LEVEL >= TEST_CIRCUIT_AVAILABLE
    MyCircuit.onMouse(Point(X, Y));
#endif
}

void VtlKeyHit(int key)
{
}

void VtlInit(void)
{
    setWindowTitle("Digitalschaltung Sommer 2023");
    setUpdateInterval(BOARDTIMER);
    cout << "TEST_LEVEL: " << TEST_LEVEL << endl;

#if TEST_LEVEL == TEST_LOGICGATECOMM
    GateA.connectOutput(GateB, 1);
#endif
#if TEST_LEVEL == TEST_SIMPLEGATES
    GateAND.connectOutput(GateNAND, 0);
    GateAND.connectOutput(GateXOR, 0);
    GateOR.connectOutput(GateNAND, 1);
    GateXOR.connectOutput(GateNOT, 0);
    GateOR.connectOutput(GateXOR, 1);
#endif
#if TEST_LEVEL == TEST_GATESWITCH
    SW1.connectOutput(GateAND, 0);
    SW2.connectOutput(GateAND, 1);
    SW3.connectOutput(GateOR, 0);
    SW4.connectOutput(GateOR, 1);
    GateAND.connectOutput(GateNAND, 0);
    GateAND.connectOutput(GateXOR, 0);
    GateOR.connectOutput(GateXOR, 1);
    GateXOR.connectOutput(GateNAND, 1);
#endif
#if TEST_LEVEL == TEST_CIRCUIT_AVAILABLE
    MyCircuit.addSwitch(new LogicGateSwitch("BoostSw", Point(20,150), "SW1", 1));
    MyCircuit.addSwitch(new LogicGateSwitch("LightSw", Point(20,220), "SW2", 0));
    MyCircuit.addGate(new LogicGateNAND(Point(250,200), "G1"));
    MyCircuit["SW1"].connectOutput(MyCircuit["G1"], 0);
    MyCircuit["SW2"].connectOutput(MyCircuit["G1"], 1);
#endif

#if TEST_LEVEL == TEST_CIRCUIT_COMPLETE
    MyCircuit.addSwitch(new LogicGateSwitch("A", Point(20,20), "SW1", 0));
    MyCircuit.addSwitch(new LogicGateSwitch("B", Point(20,100), "SW2", 1));
    MyCircuit.addSwitch(new LogicGateSwitch("C", Point(20,180), "SW3", 1));
    MyCircuit.addSwitch(new LogicGateSwitch("D", Point(20,260), "SW4", 0));
    MyCircuit.addSwitch(new LogicGateSwitch("E", Point(450,345), "SW5", 2));
    MyCircuit.addSwitch(new LogicGateSwitch("F", Point(450,387), "SW6", 0));

    MyCircuit.addGate(new LogicGateAND(Point(390,30), "G1",4));
    MyCircuit.addGate(new LogicGateAND(Point(390,110), "G2",4));
    MyCircuit.addGate(new LogicGateAND(Point(390,190), "G3",4));
    MyCircuit.addGate(new LogicGateAND(Point(390,270), "G4",4));

    MyCircuit.addGate(new LogicGateNOT(Point(260,7), "G5"));
    MyCircuit.addGate(new LogicGateNOT(Point(260,102), "G6"));
    MyCircuit.addGate(new LogicGateNOT(Point(260,197), "G7"));
    MyCircuit.addGate(new LogicGateNOT(Point(260,292), "G8"));

    MyCircuit["SW1"].connectOutput(MyCircuit["G5"],0);
    MyCircuit["G5"].connectOutput(MyCircuit["G1"],0);
    MyCircuit["SW2"].connectOutput(MyCircuit["G1"],1);
    MyCircuit["SW3"].connectOutput(MyCircuit["G1"],2);
    MyCircuit["SW4"].connectOutput(MyCircuit["G1"],3);

    MyCircuit["SW2"].connectOutput(MyCircuit["G6"],0);
    MyCircuit["G6"].connectOutput(MyCircuit["G2"],1);
    MyCircuit["SW1"].connectOutput(MyCircuit["G2"],0);
    MyCircuit["SW3"].connectOutput(MyCircuit["G2"],2);
    MyCircuit["SW4"].connectOutput(MyCircuit["G2"],3);

    MyCircuit["SW3"].connectOutput(MyCircuit["G7"],0);
    MyCircuit["G7"].connectOutput(MyCircuit["G3"],2);
    MyCircuit["SW1"].connectOutput(MyCircuit["G3"],0);
    MyCircuit["SW2"].connectOutput(MyCircuit["G3"],1);
    MyCircuit["SW4"].connectOutput(MyCircuit["G3"],3);

    MyCircuit["SW4"].connectOutput(MyCircuit["G8"],0);
    MyCircuit["G8"].connectOutput(MyCircuit["G4"],3);
    MyCircuit["SW1"].connectOutput(MyCircuit["G4"],0);
    MyCircuit["SW2"].connectOutput(MyCircuit["G4"],1);
    MyCircuit["SW3"].connectOutput(MyCircuit["G4"],2);

    MyCircuit.addGate(new LogicGateOR(Point(580,150), "G9",4));
    MyCircuit["G1"].connectOutput(MyCircuit["G9"],0);
    MyCircuit["G2"].connectOutput(MyCircuit["G9"],1);
    MyCircuit["G3"].connectOutput(MyCircuit["G9"],2);
    MyCircuit["G4"].connectOutput(MyCircuit["G9"],3);

    MyCircuit.addGate(new LogicGateXOR(Point(675,347), "G10"));
    MyCircuit["SW5"].connectOutput(MyCircuit["G10"],0);
    MyCircuit["SW6"].connectOutput(MyCircuit["G10"],1);

    MyCircuit.addGate(new LogicGateAND(Point(800,200), "G11"));
    MyCircuit["G9"].connectOutput(MyCircuit["G11"],0);
    MyCircuit["G10"].connectOutput(MyCircuit["G11"],1);


#endif // TEST_LEVEL
}

void VtlPaint(int xl, int yo, int xr, int yu)
{
#if TEST_LEVEL == TEST_START
    MyOnOffSwitch.show();
    MyToggleSwitch.show();
#endif
#if TEST_LEVEL == TEST_LOGICGATECOMM
    GateA.show();
    GateB.show();
#endif
#if TEST_LEVEL == TEST_SIMPLEGATES
    GateAND.show();
    GateOR.show();
    GateNAND.show();
    GateXOR.show();
    GateNOT.show();
#endif
#if TEST_LEVEL == TEST_GATESWITCH
    SW1.show();
    SW2.show();
    SW3.show();
    SW4.show();
    GateAND.show();
    GateOR.show();
    GateNAND.show();
    GateXOR.show();

#endif
#if TEST_LEVEL >= TEST_CIRCUIT_AVAILABLE
    MyCircuit.show();
#endif
}

