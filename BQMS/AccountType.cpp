#include <iostream>

enum AccountType
{
	PLATINUM,
	GOLD,
	SELVER,
	REGULER,
};

static std::string ToString(AccountType a)
{
	if (a == PLATINUM)
		return "Platinum";
	else if (a == GOLD)
		return "Gold";
	else if (a == SELVER)
		return "Selver";
	else
		return "Reguler";
}