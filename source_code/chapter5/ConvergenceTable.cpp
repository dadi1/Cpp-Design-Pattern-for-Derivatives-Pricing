#include "ConvergenceTable.h"

ConvergenceTable::ConvergenceTable(const
                            Wrapper<StatisticsMC>& Inner_)
                            :  Inner(Inner_)
{
    StoppingPoint = 2;
    PathsDone = 0;
}

Statis