#ifndef PAYOFF3_H
#define PAYOFF3_H

class PayOff
{
public:
    PayOff(){};

    virtual double operator() (double Spot) const=0;
    virtual ~PayOff(){}
    virtual PayOff* clone() const=0;

private:

};

class PayOffPut : public PayOff
{
public:
    PayOffPut(double Strike_);

    virtual double operator() (double Spot) const=0;
    virtual ~PayOffPut(){}
    virtual PayOff* clone() const;

private:
    double Strike;
};

#endif