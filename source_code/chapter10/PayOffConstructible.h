#ifndef PAY_OFF_CONSTRUCTIBLE_H
#define PAY_OFF_CONSTRUCTIBLE_H

#include <iostream>
#include "../chapter4/PayOff3.h"
#include "PayOffFactory.h"
#include <string>

template <class T>
class PayOffHelper
{
public:
    PayOffHelper(std::string);
    static PayOff* Create(doble Strike);
};

template <class T>
PayOff*  PayOffHelper<T>::Create(double Strike)
{
    return new T(Strike);
}

template <class T>
PayOffHelper<T>::PayOffHelper(std::string id)
{
    PayOffFactory& thePayOffFactory = PayOffFactory::Instance();
    thePayOffFactory.RegisterPayOff(id, PayOffHelper<T>::Create);
}

#endif
