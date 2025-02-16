#include "Statistics.h"

StatisticsMean::StatisticsMean()
                    :  RunningSum(0.0), PathsDone(OUL)
{  
}

void StatisticsMean::DumpOneResult(double result)
{
    PathsDone++;
    RunningSum += result;
}

std::vector<std::vector<double> > StatisticsMean::GetResultSoFar() const
{
    std::vector<std::vector<double> > Results(1);

    Results[0].resize(1);
    Results[0][0] = RunningSum / PathsDone;

    return Results;
}

StatisticsMC* StatisticsMean::clone() const
{
    return new StatisticsMean(*this);
}
