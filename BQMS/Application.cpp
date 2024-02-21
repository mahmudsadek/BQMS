#include "Application.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Utility.h"



using namespace std;

Application::Application()
{
	bank = new Bank();
}

void Application::DisplayCustomers()
{
	system("cls");
	priority_queue<Customer*, std::vector<Customer*>, Compare> tempQueue = bank->getCustomers();
	system("cls");
	cout << "\t --------------------------------|Customers Queue|-----------------------------------------\n";
	cout << "\t| No.\tName\t\tAge\tPriority\tArrive Time \t\t\t\t   |\n";
	cout << "\t ------------------------------------------------------------------------------------------\n";
	int i = 1;
	while (!tempQueue.empty())
	{
		cout << "\t| " << i++ << "\t" << tempQueue.top()->getName() << "\t\t" << tempQueue.top()->getAge() << "\t   " << tempQueue.top()->getPriority() << "\t\t   ";
		cout <<Utility::GetInHourFormat(tempQueue.top()->getArrivingTime()) << setw(36) << "|" << endl;

		cout << "\t ------------------------------------------------------------------------------------------\n";
		tempQueue.pop();
	}
	char stop;
	cin >> stop;
}

void Application::DisplayCustomers(bool flag)
{
	priority_queue<Customer*, std::vector<Customer*>, Compare> tempQueue = bank->getCustomers();
	system("cls");
	cout << "\t -----------------------------------------------| Customer Report |--------------------------------------------------------\n";
	cout << "\t| No.\tName\t\tAge\tPriority\tArrive Time\tWait Time\tService Time\tLeave Time\tTaller No. |\n";
	cout << "\t --------------------------------------------------------------------------------------------------------------------------\n";
	int i = 1;
	while (!tempQueue.empty())
	{
		cout << "\t| "  << i++ << "\t" <<tempQueue.top()->toString() << endl;
		cout << "\t --------------------------------------------------------------------------------------------------------------------------\n";
		tempQueue.pop();
	}
	cout << "\t| Total Customers : " << i-1 << "\t\t Total Wait Time : " << bank->TotalWaitingTimeForCustomers() <<"\t\t Total Service Time : " << bank->TotalServiceTime() << endl;
	cout << "\t --------------------------------------------------------------------------------------------------------------------------\n";
	cout << "\t\t\t " << "\t\t Averge Wait Time : " << bank->AverageWaitingTime() << "\t\t Average Service Time : " << bank->avgServiceTimeForAll() << endl;
	cout << "\t --------------------------------------------------------------------------------------------------------------------------\n";
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

void Application::TallersReport()
{
	cout << "\n\n===========================================================================================================================================\n\n\n";
	cout << "\t -------------------------------------------| Tallers Report |--------------------------------------------------------------\n";
	cout << "\t| No. \t\t Service Time \t\t No. of Customers \t\t Avg. Service Time\t\t Utilization Rates  |\n";
	cout << "\t ----------------------------------------------------------------------------------------------------------------------------\n";
	vector<int> AvgServiceTime = bank->AverageServiceTime();
	vector<int> ServiceTime = bank->ServiceTimeForEachTaller();
	vector<int> numOfCustomers = bank->NumberOfServiedCustomerForEachTaller();

	for (int i = 0; i < AvgServiceTime.size(); i++)
	{
		cout << "\t   " << i + 1 << " \t\t  " << ServiceTime[i] << " \t\t\t     " << numOfCustomers[i] << "\t\t\t\t     " << AvgServiceTime[i];
		cout << "\t\t\t\t     " << setprecision(3) << ((float)ServiceTime[i] / 420) * 100 << " %" << "\n";
		cout << "\t ----------------------------------------------------------------------------------------------------------------------------\n";
	}
	cout << "\n=============================================================================================================================================\n";
}
void Application::DisplayReport()
{
	bank->CustomerTallerInteraction();
	DisplayCustomers(true);
	TallersReport();
	WriteToFile();
	char k;
	cin >> k;
}

void Application::MainMenu()
{
	while (true)
	{
		system("cls");
		cout << "\t\t\t=====================================================================\n";
		cout <<"\t\t\t|\t\t\tBANK QUEUE SYSTEM\t\t\t    |\n";
		cout << "\t\t\t=====================================================================\n\n\n";

		cout << "\t\t\t|\t\tADD CUSTOMER MANUALLY    [Enter 1]\t\t    |" << endl;
		cout << "\t\t\t|\t\tREAD CUSTOMERS FROM FILE [Enter 2]\t\t    |" << endl;
		cout << "\t\t\t|\t\tDISPLAY CUSTOMERS        [Enter 3]\t\t    |" << endl;
		cout << "\t\t\t|\t\tDISPLAY THE REPORT       [Enter 4]\t\t    |" << endl;
		
		int key;
		cout << endl << "\t\t\t---------------------------------------------------------------------\n";
		cout << "\t\t\t\t\t\tENTER YOUR CHIOCE: " ;
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
			std::cout << "\t\t\t\t\t Invalid choice. Please try again." << std::endl;
			break;
		}
	}
}

void Application::Run()
{
	MainMenu();
}

void Application::WriteToFile()
{
	std::ofstream reportFile;
	reportFile.open("report.txt");
	if (!reportFile)
	{ 
		cerr << "Error: file could not be opened" << endl;
		exit(1);
	}
	priority_queue<Customer*, std::vector<Customer*>, Compare> tempQueue = bank->getCustomers();
	reportFile << "\t -----------------------------------------------| Customer Report |--------------------------------------------------------\n";
	reportFile << "\t| No.\tName\t\tAge\tPriority\tArrive Time\tWait Time\tService Time\tLeave Time\tTaller No. |\n";
	reportFile << "\t --------------------------------------------------------------------------------------------------------------------------\n";
	int i = 1;
	while (!tempQueue.empty())
	{
		reportFile << "\t| " << i++ << "\t" << tempQueue.top()->toString() << endl;
		reportFile << "\t --------------------------------------------------------------------------------------------------------------------------\n";
		tempQueue.pop();
	}
	reportFile << "\t| Total Customers : " << i - 1 << "\t\t Total Wait Time : " << bank->TotalWaitingTimeForCustomers() << "\t\t Total Service Time : " << bank->TotalServiceTime() << endl;
	reportFile << "\t --------------------------------------------------------------------------------------------------------------------------\n";
	reportFile << "\t\t\t " << "\t\t Averge Wait Time : " << bank->AverageWaitingTime() << "\t\t Average Service Time : " << bank->avgServiceTimeForAll() << endl;
	reportFile << "\t --------------------------------------------------------------------------------------------------------------------------\n";

	reportFile << "\n\n===========================================================================================================================================\n\n\n";
	reportFile << "\t -------------------------------------------| Tallers Report |--------------------------------------------------------------\n";
	reportFile << "\t| No. \t\t Service Time \t\t No. of Customers \t\t Avg. Service Time\t\t Utilization Rates  |\n";
	reportFile << "\t ----------------------------------------------------------------------------------------------------------------------------\n";
	vector<int> AvgServiceTime = bank->AverageServiceTime();
	vector<int> ServiceTime = bank->ServiceTimeForEachTaller();
	vector<int> numOfCustomers = bank->NumberOfServiedCustomerForEachTaller();

	for (int i = 0; i < AvgServiceTime.size(); i++)
	{
		reportFile << "\t   " << i + 1 << " \t\t  " << ServiceTime[i] << " \t\t\t     " << numOfCustomers[i] << "\t\t\t\t     " << AvgServiceTime[i];
		reportFile << "\t\t\t\t     " << setprecision(3) << ((float)ServiceTime[i] / 420) * 100 << " %" << endl;
		reportFile << "\t ----------------------------------------------------------------------------------------------------------------------------\n";
	}
	reportFile << "\n=============================================================================================================================================\n";
	reportFile.close();
}

