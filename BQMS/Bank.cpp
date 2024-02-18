#include "Bank.h"
#include <Queue>
#include <fstream>
#include <sstream>

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



