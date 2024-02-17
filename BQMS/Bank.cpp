#include "Bank.h"
#include <Queue>

void Bank::AddCustomer(std::string name, int age, AccountType accType, int arrTimeHour, int arrTimeMin)
{
	Customers.push(new Customer(name,age,accType,arrTimeHour,arrTimeMin));
}

Bank::Bank()
{
}

void Bank::AddTaller()
{
	tallers.push_back(new Taller());
}

std::priority_queue<Customer*, std::vector<Customer*>, Compare> Bank::getCustomers()
{
	std::priority_queue < Customer*, std::vector<Customer*>, Compare> tempQueue = Customers;
	return tempQueue;
}



