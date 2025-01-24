#include "BinomialTree.h" 
#include "../chapter6/Array.h"

#include <cmath>

SimpleBinomialTree::SimpleBinomialTree(double Spot_,
                                       const Parameters& r_,
                                       const Parameters& d_,
                                       double Volatility_,
                                       long Steps_,
                                       double Time_)
                                       : Spot(Spot_),
                                       r(r_),
                                       d(d_),
                                       Volatility(Volatility_),
                                       Steps(Steps_),
                                       Time(Time_),
                                       Discounts(Steps_)
{
    TreeBuilt = false;
} 

void SimpleBinomialTree::BuildTree()
{
    TreeBuilt = true;
    TheTree.resize(Steps + 1);

    double InitialLogSpot = std::log(Spot);
    for (long i = 0; i <= Steps; i++)
    {
        TheTree[i].resize(i + 1);

        double thisTime = (i * Time) / Steps;

        double movedLogSpot = 
            InitialLogSpot + r.Integral(0.0, thisTime)
                           - d.Integral(0.0, thisTime);
        
        movedLogSpot -=
            0.5 * Volatility * Volatility * thisTime;
        
        double sd = Volatility * std::sqrt(Time / Steps);

        for (long j = -static_cast<long>(i), k = 0;
                j <= static_cast<long>(i); j = j + 2, k++)
            TheTree[i][k].first = std::exp(movedLogSpot + j * sd);
        
    }

    for (long l = 0; l < Steps; l++)
        Discounts[l] = 
            std::exp(-r.Integral(l * Time/Steps, (l+1) * Time/Steps));
}

double SimpleBinomialTree::GetThePrice(const TreeProduct&
                                            TheProduct)
{
    if(!TreeBuilt)
        BuildTree();

    if (TheProduct.GetFinalTime() != Time)
        throw("mismatched product in SimpleBinomialTree");
    
    for (long j = -static_cast<long>(Steps), k = 0;
            j <= static_cast<long>(Steps); j += 2, k++)
        TheTree[Steps][k].second =
            TheProduct.FinalPayOff(TheTree[Steps][k].first);
    
     for (long i = 0; i <= Steps; i++)
     {
        long index = Steps - i;
        double ThisTime = index * Time/Steps;

        for (long j = -static_cast<long>(index), k = 0;
        j <= static_cast<long>(index); j += 2, k++)
        {
            double Spot = TheTree[index][k].first;

            double futureDiscountedValue = 0.5 * Discounts[index] *
            (TheTree[index][k].second);

            TheTree[index][k].second = 
            TheProduct.PreFinalValue(Spot, ThisTime,
                                     futureDiscountedValue);
        }
     }

     return TheTree[0][0].second;
}