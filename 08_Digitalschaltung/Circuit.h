#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <vector>
using std::vector;
#include <string>
using std::string;
#include "Point.h"

#include "LogicGate.h"
#include "LogicGateSwitch.h"

class Circuit{
private:
    double CrystalFrequency;
    vector<LogicGate*> Gates;
    vector<LogicGateSwitch*> Switches;

public:
    Circuit(double CrystalFrequency);
    ~Circuit();

    void addGate(LogicGate* NewGate);
    void addSwitch(LogicGateSwitch* NewSwitch);
    void onMouse(const Point& where);
    void clock();
    void show();

    LogicGate& operator[](unsigned Index);
    LogicGate& operator[](const string& ID);

};




#endif // CIRCUIT_H
