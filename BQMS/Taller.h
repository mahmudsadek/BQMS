#pragma once
#include "customer.h"
class Taller
{
	static int count;
private:
	int number;
	bool isFree;
public:
	Taller();
	bool IsFree() const;
	void IsFree(bool value);
	void Serve(Customer *customer);
};

