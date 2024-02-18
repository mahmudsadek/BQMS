#pragma once
#include "customer.h"
class Compare {
public:
    bool operator()(const Customer* A, const Customer* B)
    {
        if (A->getArrivingTime() > B->getArrivingTime() && A->getArrivingTime() - B->getArrivingTime() < 10)
        {
            if (A->getPriority() >= B->getPriority())
                return true;
            else
                return false;
        }
        else
        {
            if (A->getArrivingTime() - B->getArrivingTime() > 10)
                return true;
            return false;
        }
    }
};