#pragma once
#include "customer.h"
class Taller
{
	static int count;
private:
	int number;
	bool isFree;
	int currentServingTime;
	int totalServingTime;
public:
	Taller();
	bool IsFree() const;
	void IsFree(bool value);
	void Serve(Customer *customer);
	void CurrentServingTime(int time);
	int CurrentServingTime() const;
	void TotalServingTime(int time);
	int TotalServingTime() const;
	void DecreaseCurrentServingTime();

};

