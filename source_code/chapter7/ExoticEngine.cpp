#include "ExoticEngine.h"

#include <cmath>

ExoticEngine::ExoticEngine(const Wrapper<PathDependent>& TheProduct_,
                           const Parameters& r_)
        : TheProduct(TheProduct_),
          r(r_),
          Discounts(TheProduct_->PossibleCashFlowTimes())
{
    for (long i = 0; i < Discounts.size(); i++) 
        Discounts[i] = std::exp(-r.Integral(0.0, Discounts[i]));
    
    TheseCashFlows.resize(TheProduct->MaxNumberOfCashFlows());
}

void ExoticEngine::DoSimulation(StatisticsMC& TheGatherer,
                                long NumberOfPaths)
{
    MJArray SpotValues(TheProduct->GetLookAtTimes().size());

    TheseCashFlows.resize(TheProduct->MaxNumberOfCashFlows());
    double thisValue;

    for (long i = 0; i < NumberOfPaths; i++)
    {
        GetOnePath(SpotValues);
        thisValue = DoOnePath(SpotValues); 
        TheGatherer.DumpOneResult(thisValue);
    }

    return;
}

double ExoticEngine::DoOnePath(const MJArray& SpotValues) const
{
    long NumberFlows = TheProduct->CashFlows(SpotValues, TheseCashFlows);

    double Value = 0.0;

    for (long i =0; i < NumberFlows; i++)
    {
        Value += TheseCashFlows[i].Amount *
                Discounts[TheseCashFlows[i].TimeIndex];
    }

    return Value;
}

