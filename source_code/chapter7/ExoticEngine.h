#ifndef EXOTICENGINE_H
#define EXOTICENGINE_H

#include "../chapter5/Wrapper.h"
#include "../chapter4/Parameters.h"
#include "PathDependent.h"
#include "../chapter5/Statistics.h"
#include <vector>

class ExoticEngine
{
public:
    ExoticEngine(const Wrapper<PathDependent>&
                    TheProduct_, const Parameters& r_);
    virtual void GetOnePath(MJArray& SpotValues)=0;

    void DoSimulation(StatisticsMC& theGatherer,
                      long NumberOfPaths);

    virtual ~ExoticEngine() {}
    double DoOnePath(const MJArray& SpotValues) const;

private:
    Wrapper<PathDependent> TheProduct;
    Parameters r;
    MJArray Discounts;
    mutable std::vector<CashFlow> TheseCashFlows;
};

#endif