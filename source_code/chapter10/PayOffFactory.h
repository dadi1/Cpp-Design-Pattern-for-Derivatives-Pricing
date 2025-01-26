#ifndef PAY_OFF_FACTORY_H
#define PAY_OFF_FACTORY_H

#include "../chapter4/PayOff3.h"

#include <string>
#include <map>

class PayOffFactory
{
public:
    typedef PayOff* (*CreatePayOffFunction)(double);

    static PayOffFactory& Instance();
    void RegisterPayOff(std::string, CreatePayOffFunction);
    PayOff* CreatePayOff(std::string PayOffId, double Strike);
    ~PayOffFactory(){};

private:
    std::map<std::string, CreatePayOffFunction>
                TheCreateFunction;
    PayOffFactory(){}
    PayOffFactory(const PayOffFactory&){}
    PayOffFactory& operator=
                (const PayOffFactory&){ return *this; }
};

#endif
