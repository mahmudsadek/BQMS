#include "Taller.h"

Taller::Taller()
{
	IsFree(true);
	CurrentServingTime(0);
	totalServingTime = 0;
	numberOfServiedCustomers = 0;
	number = ++Taller::count;
}

void Taller::Serve(Customer* customer)
{
	IsFree(false);
	if (customer->getArrivingTime() > CustomerLeveingTime())
	{
		customer->setWaitingTime(0);
	}
	else
	{
		customer->setWaitingTime(CustomerLeveingTime() - customer->getArrivingTime());
	}
	//customer->setWaitingTime( (customer->getArrivingTime() + TotalServingTime()) - customer->getArrivingTime());
	int servingTime = 10 + (rand() % 40);
	customer->setServiceTime(servingTime);
	customer->TallerNumber(number);
	CurrentServingTime(servingTime);
	TotalServingTime(servingTime);
	CustomerLeveingTime(customer->getArrivingTime() + customer->getServiceTime());
	IncrementnumberOfServiedCustomers();
	
}

void Taller::IsFree(bool value)
{
	isFree = value;
}

bool Taller::IsFree() const
{
	return isFree;
}

void Taller::TotalServingTime(int time)
{
	totalServingTime += time;
}

int Taller::TotalServingTime() const
{
	return totalServingTime;
}

int Taller::CurrentServingTime() const
{
	return currentServingTime;
}

void Taller::CurrentServingTime(int time)
{
	currentServingTime = time;
}

void Taller::DecreaseCurrentServingTime()
{
	currentServingTime--;
}

void Taller::IncrementnumberOfServiedCustomers()
{
	numberOfServiedCustomers++;
}

void Taller::CustomerLeveingTime(int time)
{
	customerLeveingTime = time;
}

int Taller::CustomerLeveingTime() const
{
	return customerLeveingTime;
}

int Taller::NumberOfServiedCustomers() const
{
	return numberOfServiedCustomers;
}