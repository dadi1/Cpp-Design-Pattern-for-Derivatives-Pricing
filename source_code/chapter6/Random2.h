#ifndef RANDOM2_H
#define RANDOM2_H

#include "Array.h"

class RandomBase
{
public:
    RandomBase(long Dimensionality);

    inline long GetDimensionality() const;

    virtual RandomBase* clone() const=0;
    virtual void GetUniforms(MJArray& variates)=0;
    virtual void Skip(long NumberOfPaths)=0;
    virtual void SetSeed(long Seed)=0;
    virtual void Reset()=0;

    virtual void GetGaussians(MJArray& variates);
    virtual void ResetDimensionality(long NewDimensionality);

private:
    long Dimensionality;
};

long RandomBase::GetDimensionality() const
{
    return Dimensionality;
}

#endif