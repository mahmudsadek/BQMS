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
	void DisplayCustomers(bool flag);
	void AddCustomer();
	void DisplayReport();
	void MainMenu();
	void TallersReport();
	void Run();
	void WriteToFile();
};

