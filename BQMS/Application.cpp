#include "Application.h"
#include <iostream>
#include <iomanip>
using namespace std;

Application::Application()
{
	bank = new Bank();
}

void Application::DisplayCustomers()
{
	priority_queue<Customer*, std::vector<Customer*>, Compare> tempQueue = bank->getCustomers();
	while (!tempQueue.empty())
	{
		cout << "Name : " << tempQueue.top()->getName() << "\t";
		cout << "ARRTIME : " << (tempQueue.top()->getArrivingTime() - (tempQueue.top()->getArrivingTime() % 60))/60 << ":" << tempQueue.top()->getArrivingTime()%60 << "\t";
		cout << "PRIORITY : " << tempQueue.top()->getPriority() << "\t";
		cout << endl;
		tempQueue.pop();
	}
	char stop;
	cin >> stop;
}

void Application::DisplayCustomers(bool flag)
{
	priority_queue<Customer*, std::vector<Customer*>, Compare> tempQueue = bank->getCustomers();
	while (!tempQueue.empty())
	{
		cout << "Name : " << tempQueue.top()->getName() << "\t";
		cout << "ARRTIME : " << (tempQueue.top()->getArrivingTime() - (tempQueue.top()->getArrivingTime() % 60)) / 60 << ":" << tempQueue.top()->getArrivingTime() % 60 << "\t";
		cout << "PRIORITY : " << tempQueue.top()->getPriority() << "\t";
		cout << "WAITITNGTIME : " << tempQueue.top()->getWitingTime() << "\t";
		cout << "SERVICETIME : " << tempQueue.top()->getServiceTime()<< endl;

		cout << endl;
		tempQueue.pop();
	}
}

void Application::AddCustomer()
{
	string name;
	cout << "Enter Name: ";
	cin >> name;
	int age;
	cout << "Enter age: ";
	cin >> age;
	AccountType accType;
	int choice;
	cout << "Enter Account Type [ 1 for Platinum , 2 for Gold , 3 for Selver  , Other for Reguler(Default)] : ";
	cin >> choice;
	choice == 1 ? accType = PLATINUM : choice == 2 ? accType = GOLD : choice == 3 ? accType = SELVER : accType = REGULER;
	int arrTimeHour;
	cout << "Enter Arrivaing Time Hour: ";
	cin >> arrTimeHour;
	int arrTimeMin;
	cout << "Enter Arrivaing Time Minute: ";
	cin >> arrTimeMin;
	bank->AddCustomer(name,age,accType,arrTimeHour,arrTimeMin);
}

void Application::DisplayReport()
{
	bank->CustomerTallerInteraction();
	DisplayCustomers(true);
	int waitingTime = bank->AverageWaitingTime();
	cout << "\n=====================================================\n";
	cout << "\tAVERAGE WAITING TIME IS " << waitingTime << endl;
	cout << "\n=====================================================\n";
	cout << "\n=====================================================\n";
	vector<int> serviceTime = bank->AverageServiceTime();
	for (int i = 0; i < serviceTime.size(); i++)
	{
		cout << "\tAVERAGE SERVICE TIME FOR TALLER NUMBER " << i+1 << " IS " << serviceTime[i] << endl;
	}
	cout << "\n=====================================================\n";
	char k;
	cin >> k;
}

void Application::Run()
{
	while (true)
	{
		std::cout << std::setw(50) << std::setfill('*') << "" << std::endl;
		std::cout << std::setw(30) << std::setfill(' ') << "BANK QUEUE SYSTEM" << std::endl;
		std::cout << std::setw(50) << std::setfill('*') << "" << std::endl;
		int key;
		cout << endl;
		cout << std::setw(35) <<  std::setfill(' ') <<  "1 - ADD CUSTOMER     \n\n";
		cout << std::setw(35) << "2 - ADD CUSTOMERS FROM FILE \n\n";
		cout << std::setw(35) << "3 - DISPLAY CUSTOMERS \n\n";
		cout << std::setw(35) << "4 - DISPLAY REPORT ABOUT THE SYSTEM\n\n";


		cin >> key;
		switch (key)
		{
		case 1:
			AddCustomer();
			break;
		case 2:
			bank->AddCustomersFromFile();
			break;
		case 3:
			DisplayCustomers();
			break;
		case 4:
			DisplayReport();
			break;
		default:
			break;
		}


	}
}
