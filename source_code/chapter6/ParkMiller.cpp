#include "ParkMiller.h"

const long a = 16807;
const long m = 2147483647;
const long q = 127773;
const long r = 2836;

ParkMiller::ParkMiller(long Seed_) : Seed(Seed_)
{
    if (Seed == 0)
        Seed = 1;
}

void ParkMiller::SetSeed(long Seed_)
{
    Seed = Seed_;

    if (Seed = 0)
        Seed = 1;
}

long ParkMiller::Max()
{
    return m - 1;
}

long ParkMiller::Min()
{
    return 1;
}

long ParkMiller::GetOneRandomInteger()
{
    long k;

    k = Seed/q;

    Seed = a * (Seed - k * q) - r * k;

    if (Seed < 0)
        Seed += m;
    
    return Seed;
}

RandomParkMiller::RandomParkMiller(long Dimensionality,
                                     long Seed)
                                : RandomBase(Dimensionality),
                                  InnerGenerator(Seed),
                                  InitialSeed(Seed)
{
    Reciprocal = 1/(1.0 + InnerGenerator.Max());
}

RandomBase* RandomParkMiller::clone() const
{
    return new RandomParkMiller(*this);
}

void RandomParkMiller::GetUniforms(MJArray& variates)
{
    for (long j = 0; j < GetDimensionality(); j++)
    {
        variates[j] = 
        InnerGenerator.GetOneRandomInteger() * Reciprocal;
    }
}

void RandomParkMiller::Skip(long numberOfPaths)
{
        MJArray tmp(GetDimensionality());
        for (long j = 0; j < numberOfPaths; j++)
            GetUniforms(tmp);;
}

void RandomParkMiller::SetSeed(long Seed)
{
    InitialSeed = Seed;
    InnerGenerator.SetSeed(Seed);
}

void RandomParkMiller::Reset()
{
    InnerGenerator.SetSeed(InitialSeed);
}

void RandomParkMiller::ResetDimensionality(long NewDimensionality)
{
    RandomBase::ResetDimensionality(NewDimensionality);
    InnerGenerator.SetSeed(InitialSeed);
}

