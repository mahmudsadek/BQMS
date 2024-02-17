#include "customer.h"
class Compare {
public:
    bool operator()(const Customer* A, const Customer* B)
    {
        return A->getPriority() > B->getPriority();
    }
};