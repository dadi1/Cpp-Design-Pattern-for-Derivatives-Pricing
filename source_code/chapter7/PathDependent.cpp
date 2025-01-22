#include "PathDependent.h"

PathDependent::PathDependent(const MJArray& LookAtTimes_,)
        : LookAtTimes(LookAtTimes_)
{}

const MJArray& PathDependent::GetLookAtTime() const 
{
    return LookAtTimes;
}