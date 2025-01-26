#include "PayOffFactory.h"
#include <iostream>

void PayOffFactory::RegisterPayOff(std::string PayOffId,
              CreatePayOffFunction CreatorFunction)
{
    TheCreateFunction.insert(std::pair<std::string,CreatePayOffFunction>
                                (PayOffId, CreateFunction));
}

PayOff* PayOffFactory::CreatePayOff(std::string PayOffId,
                                        double Strike)
{
    std::map<std::string, CreatePayOffFunction>::const_iterator
                    i = TheCreatorFunction.find(PayOff);

    if (i == TheCreatorFunction.end())
    {
        std::cout << PayOffId
        << "is an unknow payoff" << std::endl;
        return NULL;
    }

    return (i->second)(Strike);
}

PayOffFactory& PayOffFactory::Instance()
{
    static PayOffFactory theFactory;
    return theFactory;
}