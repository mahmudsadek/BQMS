#pragma once
#include <iostream>
#include <list>
#include <queue>
#include "Taller.h"
#include "customer.h"
#include "comparer.h"
class Bank
{
private:
	std::list<Taller*> tallers;
	std::priority_queue<Customer*, std::vector<Customer*>, Compare> Customers;
public:
	
};

