#ifndef PATHDEPENDENT_H
#define PATHDEPENDENT_H

#include "../chapter6/Array.h"
#include <vector>

class CashFlow
{
public:
    double Amount;
    long TimeIndex;

    CashFlow(long TimeIndex_, double Amount_ =0.0) 
            : TimeIndex(TimeIndex_), Amount(Amount_) {}
};

class PathDependent
{
public:
    PathDependent(const MJArray& LookAtTimes);

    const MJArray& GetLookAtTime() const;

    virtual long MaxNumberOfCashFlows() const=0; 
    virtual MJArray PossibleCashFlowTimes() const=0;
    virtual long CashFlows(const MJArray& SpotValue,
                           std::vector<CashFlow>& GeneratorFlows) const=0;
    virtual PathDependent* clone() const=0;
    
    virtual ~PathDependent(){}

private:
    MJArray LookAtTimes;
};

#endif