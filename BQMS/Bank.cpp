#include "Bank.h"
#include <Queue>
#include <fstream>
#include <sstream>

void Bank::AddCustomer(std::string name, int age, AccountType accType, int arrTimeHour, int arrTimeMin)
{
	Customers.push(new Customer(name,age,accType,arrTimeHour,arrTimeMin));
}

void Bank::DecreaseServiceTimeForTellers()
{
    bool flag = true;
    while (flag)
    {
        int i = 0;
        while(flag && i < 4)
        {
            if (tallers[i]->CurrentServingTime() > 0)
                tallers[i]->DecreaseCurrentServingTime();

            if (tallers[i]->CurrentServingTime() == 0)
            {
                tallers[i]->IsFree(true);
                flag = false;
            }
            i++;
        }
    }
}

void Bank::FindingFreeTaller(std::priority_queue<Customer*, std::vector<Customer*>, Compare> &temp)
{
    while (!temp.empty())
    {
        Customer* customer = temp.top();
        int i = 0;
        while(!temp.empty() && i < 4)
        {
            if (tallers[i]->IsFree())
            {
                temp.pop();
                tallers[i]->Serve(customer);
                totalWaitingTimeForCustomers += customer->getWitingTime();
            }
            else
            {
                DecreaseServiceTimeForTellers();
                FindingFreeTaller(temp);
            }
            i++;
        }
    }
}

Bank::Bank()
{
    for (int i = 0; i < 4; i++)
    {
        tallers.push_back(new Taller());
    }
    totalWaitingTimeForCustomers = 0;
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

void Bank::AddCustomersFromFile()
{
	std::ifstream CustomersData("data.txt");
    while (CustomersData)
    {
        std::string s;
        if (!getline(CustomersData, s)) break;

        std::istringstream ss(s);
        std::vector <std::string> record;

        while (ss)
        {
            std::string s;
            if (!getline(ss, s, ',')) break;
            record.push_back(s);
        }

        int age = stoi(record[1]);
        int choice = stoi(record[2]);
        AccountType accType;
        choice == 1 ? accType = PLATINUM : choice == 2 ? accType = GOLD : choice == 3 ? accType = SELVER : accType = REGULER;
        int hour = stoi(record[3]);
        int minute = stoi(record[4]);

        AddCustomer(record[0],age,accType,hour,minute);
    }
    if (!CustomersData.eof())
    {
        std::cerr << "Fooey!\n";
    }
}

void Bank::CustomerTallerInteraction()
{
    std::priority_queue<Customer*, std::vector<Customer*>, Compare> temp = Customers;
    FindingFreeTaller(temp);
}

std::vector<int> Bank::AverageServiceTime()
{
    std::vector<int> avgServiceTime;
    for (int i = 0; i < tallers.size(); i++)
    {
        int AVG  = tallers[i]->TotalServingTime() / tallers[i]->NumberOfServiedCustomers();
        avgServiceTime.push_back(AVG);
    }
    return avgServiceTime;
}

int Bank::AverageWaitingTime()
{
    return totalWaitingTimeForCustomers / (int)Customers.size();
}



