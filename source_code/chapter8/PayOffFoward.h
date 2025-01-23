#ifndef PAY_OFF_FOWARD_H
#define PAY_OFF_FOWARD_H

#include "../chapter4/PayOff3.h"

class PayOffFoward : public PayOff
{
public:
    PayOffFoward(double Strike_);

    virtual double operator()(double Spot) const;
    virtual ~PayOffFoward(){}
    virtual PayOff* clone() const;

private:
    double Strike;
};

#endif