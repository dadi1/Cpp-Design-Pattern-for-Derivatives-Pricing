#include "Random2.h"
#include "Normals.h"
#include <cstdlib>

void RandomBase::GetGaussians(MJArray& variates) 
{
    GetUniforms(variates);

    for (long i=0; i < Dimensionality; i++)
    {
        double x = variates[i];
        variates[i] = InverseCumulativeNormal(x);
    }
}

void RandomBase::ResetDimensionality(long NewDimensionality)
{
    Dimensionality = NewDimensionality;
}

RandomBase::RandomBase(long Dimensionality_) 
                    : Dimensionality(Dimensionality_)
{
}