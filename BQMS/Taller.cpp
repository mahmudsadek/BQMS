#include "Taller.h"

Taller::Taller()
{
	IsFree(true);
	CurrentServingTime(0);
	TotalServingTime(0);
	numberOfServiedCustomers = 0;
	number = ++Taller::count;
}

void Taller::Serve(Customer* customer)
{
	IsFree(false);
	int servingTime = 10 + (rand() % 40);
	customer->setServiceTime(servingTime);
	CurrentServingTime(servingTime);
	TotalServingTime(servingTime);
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

int Taller::NumberOfServiedCustomers() const
{
	return numberOfServiedCustomers;
}