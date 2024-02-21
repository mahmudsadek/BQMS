#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include "Taller.h"
#include "customer.h"
#include "comparer.h"
class Bank
{
private:
	std::vector<Taller*> tallers;
	std::priority_queue<Customer*, std::vector<Customer*>, Compare> Customers;
	int totalWaitingTimeForCustomers;
	void DecreaseServiceTimeForTellers();
	void FindingFreeTaller(std::priority_queue<Customer*, std::vector<Customer*>, Compare> &Customers);
public:
	Bank();
	void AddCustomer(std::string name, int age, AccountType accType, int arrTimeHour, int arrTimeMin);
	void AddTaller();
	std::priority_queue<Customer*, std::vector<Customer*>, Compare> getCustomers();
	void AddCustomersFromFile();
	void CustomerTallerInteraction();
	int AverageWaitingTime();
	std::vector<int> AverageServiceTime();
	std::vector<int> ServiceTimeForEachTaller();
	int TotalWaitingTimeForCustomers() const;
	int TotalServiceTime()const;
	int avgServiceTimeForAll()const;
	std::vector<int> NumberOfServiedCustomerForEachTaller();

};

