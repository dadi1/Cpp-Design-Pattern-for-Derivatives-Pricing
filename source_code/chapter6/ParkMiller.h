#ifndef PARKMILLER_H
#define PARKMILLER_H
#include "Random2.h"

class ParkMiller
{
public:
    ParkMiller(long Seed = 1);

    long GetOneRandomInteger();
    void SetSeed(long Seed);

    static long Max();
    static long Min();

private:
    long Seed;
};

class RandomParkMiller : public RandomBase
{
public:
    RandomParkMiller(long Dimensionality,
                     long Seed = 1);

    virtual RandomBase* clone() const;
    virtual void GetUniforms(MJArray& variates);
    virtual void Skip(long NumberOfPaths);
    virtual void SetSeed(long Seed);
    virtual void Reset();
    virtual void ResetDimensionality(long NewDimensionality);

private:
    ParkMiller InnerGenerator;
    long InitialSeed;
    double Reciprocal;
};

#endif