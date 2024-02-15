#include "Taller.h"

Taller::Taller()
{
	IsFree(true);
	number = ++Taller::count;
}

void Taller::Serve(Customer* customer)
{
		
}

void Taller::IsFree(bool value)
{
	isFree = value;
}

bool Taller::IsFree() const
{
	return isFree;
}
