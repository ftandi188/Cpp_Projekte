#ifndef SIMPLEGATES_H
#define SIMPLEGATES_H
#include "LogicGate.h"
#include "testlevel.h"
#if TEST_LEVEL > TEST_START

class LogicGateNOT : public LogicGate
{
    public:
        LogicGateNOT(const Point& Position,
                     const string& ID
                     );
        virtual void updateOutput() override;
        void decorate() const override;
};


#endif
#endif // SIMPLEGATES_H
