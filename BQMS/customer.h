#pragma once
#include <iostream>
#include "AccountType.cpp"
class Customer
{
private:
	std::string name;
	int age;
	AccountType AccType;
	int priority;
	int ArrivaingTime;
	int WaitingTime;
	int ServiceTime;
	void setPriority();
	void setServiceTime();
public:
	Customer(std::string name, int age, AccountType acc,int HOUR, int MIN);
	void setAccType(AccountType acc);
	AccountType getAccType() const;
	void setAge(int age);
	int getAge() const;
	void increasePriority();
	int getPriority() const;
	void setName(std::string name);
	std::string getName() const;
	void setArrivingTime(int h, int m);
	int getArrivingTime() const;
	int getServiceTime() const;
	void setWaitingTime(int witingTime);
	int getWitingTime() const;
};

