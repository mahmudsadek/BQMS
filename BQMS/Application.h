#pragma once
#include <iostream>
#include "Bank.h"
using namespace std;

class Application
{
private:
	Bank *bank = nullptr;
public:
	Application();
	void DisplayCustomers();
	void AddCustomer();
	void Run();
};

