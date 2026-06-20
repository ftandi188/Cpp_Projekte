#include "testlevel.h"
#include "Circuit.h"
#include "Oscillator.h"
#include "LogicGateSwitch.h"
#include "LogicExceptions.h"

Circuit::Circuit(double uCrystalFrequency)
        :CrystalFrequency(uCrystalFrequency)
{}

Circuit::~Circuit(){
    for (auto& elements : Gates){
        delete elements;
    }
}

void Circuit::addGate(LogicGate* NewGate){
    int Index = Gates.size();
    Gates.push_back(NewGate);
}

void Circuit::addSwitch(LogicGateSwitch* NewSwitch){
    int IndexS = Switches.size();
    int IndexG = Gates.size();

    Switches.push_back(NewSwitch);
    Gates.push_back(NewSwitch);
}

void Circuit::onMouse(const Point& where){
    for (auto& elements : Switches){
        elements->onMouse(where);
    }
}

void Circuit::clock(){
    for (auto& elements : Switches){
        elements->clock();
    }
}

void Circuit::show(){
    for (auto& elements : Gates){
        elements->show();
    }
}

LogicGate& Circuit::operator[](unsigned Index){
    return *(Gates[Index]);
}

LogicGate& Circuit::operator[](const string& uID){
    for (auto& elements : Gates){
        if(*elements == uID){
            return *elements;
        }
    }

    throw ExceptionUnknownLogicGateID();
}


