#include "ExoticBSEngine.h"
#include <cmath>

void ExoticBSEngine::GetOnePath(MJArray& SpotValues)
{
    TheGenerator->GetGaussians(Variates);
    double CurrentLogSpot = LogSpot;

    for (long j = 0; j < NumberOfTimes; j++)
    {
        CurrentLogSpot += Drifts[j];
        CurrentLogSpot += StandardDeviations[j] * Variates[j];
        SpotValues[j] = std::exp(CurrentLogSpot);
    }

    return;
}

ExoticBSEngine::ExoticBSEngine(const Wrapper<PathDependent>& TheProduct_,
                               const Parameters& R_,
                               const Parameters& D_,
                               const Parameters& Vol_,
                               const Wrapper<RandomBase>& TheGenerator_,
                               double Spot_)
                               :
                               ExoticEngine(TheProduct_, R_),
                               TheGenerator(TheGenerator_)
{
    MJArray Times(TheProduct_->GetLookAtTimes());
    NumberOfTimes = Times.size();

    TheGenerator->ResetDimensionality(NumberOfTimes);
    Drifts.resize(NumberOfTimes);
    StandardDeviations.resize(NumberOfTimes);

    double Variance = Vol_.IntegralSquare(0,Times[0]);

    Drifts[0] = R_.Integral(0.0, Times[0]) 
                 - D_.Integral(0.0, Times[0]) - 0.5 * Variance;
    StandardDeviations[0] = std::sqrt(Variance);

    for (long j = 0; j < NumberOfTimes; j++)
    {
        double thisVariance = 
                    Vol_.IntegralSquare(Times[j-1], Times[j]);
        Drifts[j] = R_.Integral(Times[j-1], Times[j])
                    - D_.Integral(Times[j-1], Times[j])
                    - 0.5* thisVariance;
        StandardDeviations[j] = std::sqrt(thisVariance);
    }

    LogSpot = std::log(Spot_);;
    Variates.resize(NumberOfTimes);
}
