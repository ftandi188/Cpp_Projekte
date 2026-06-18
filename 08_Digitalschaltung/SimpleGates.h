#ifndef SIMPLEGATES_H
#define SIMPLEGATES_H
#include "LogicGate.h"
#include "testlevel.h"
#if TEST_LEVEL > TEST_START

class LogicGateNOT : public LogicGate{
    public:
        LogicGateNOT(const Point& Position, const string& ID);

        virtual void updateOutput() override;
        void decorate() const override;
};



class LogicGateAND : public LogicGate{
public:
    LogicGateAND(const Point& Position, const string& ID, int Ports = 2);

    virtual void updateOutput() override;
};



class LogicGateOR : public LogicGate{
public:
    LogicGateOR(const Point& Position, const string& ID, int Ports = 2);

    virtual void updateOutput() override;
};



class LogicGateNAND : public LogicGate{
public:
    LogicGateNAND(const Point& Position, const string& ID, int Ports = 2);

    virtual void updateOutput() override;
    void decorate() const override;
};



class LogicGateXOR : public LogicGate{
public:
    LogicGateXOR(const Point& Position, const string& ID, int Ports = 2);

    virtual void updateOutput() override;
    void decorate() const override;
};

#endif
#endif // SIMPLEGATES_H
