#ifndef CONVERGENCETABLE_H
#define CONVERGENCETABLE_H

#include "Statistics.h"
#include "Wrapper.h"

class ConvergenceTable : public StatisticsMC
{
public:
    ConvergenceTable(const Wrapper<StatisticsMC>& Inner_);

    virtual StatisticsMC* clone() const;
    virtual void DumpOneResult(double Result);
    virtual std::vector<std::vector<double> > 
                            GetResultSoFar() const;

private:
    Wrapper<StatisticsMC> Inner;
    std::vector<std::vector<double> > ResultSoFar;
    long StoppingPoint;
    long PathsDone;
};

#endif