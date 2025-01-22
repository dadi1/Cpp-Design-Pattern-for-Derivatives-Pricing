#ifndef ANTITHETIC_H
#define ANTITHETIC_H

#include "Random2.h"
#include "../chapter5/Wrapper.h"

class AntiThetic : public RandomBase
{
public:
    AntiThetic(const Wrapper<RandomBase>& innerGenerator);

    virtual RandomBase* clone() const;

    virtual void GetUniforms(MJArray& variate);

    virtual void Skip(long numberOfPaths);

    virtual void SetSeed(long Seed);

    virtual void ResetDimensionality(long NewDimensionality);

    virtual void Reset();

private:
    Wrapper<RandomBase> InnerGenerator;

    bool OddEven;

    MJArray NextVariates;
};

#endif