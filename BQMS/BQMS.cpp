// BQMS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "customer.h"
#include "Queue.h"
#include "Taller.h"
#include <vector>
#include<cmath>
using namespace std;

int Taller::count = 0;

static Customer* AddCustomer()
{
	string name;
	cout << "Enter Name :";
	cin >> name;
	int age;
	cout << "Enter Age :";
	cin >> age;
	AccountType acc;
	int choice;
	cout << "Enter AccType [ 1 = Platinum , 2 = Gold , 3 = Selver , 4 = Reguler(Defult) ] : ";
	cin >> choice;
	choice == 1 ? acc = PLATINUM : choice == 2 ? acc = GOLD : choice == 3 ? acc = SELVER : acc = REGULER;
	int arrTimeHour;
	cout << "Enter Arrivaing Time hour : ";
	cin >> arrTimeHour;
	int arrTimeMin;
	cout << "Enter Arrivaing Time hour : ";
	cin >> arrTimeMin;
	return new Customer(name, age, acc, arrTimeHour, arrTimeMin);
}


int main()
{
	
	Queue* Customers = new Queue();
	vector <Customer*> custumersArr{
		new Customer("Mahmoud",23,PLATINUM,8,23),
		new Customer("Sadek",63,GOLD,9,12),
		new Customer("Ali",63,PLATINUM,9,23),
		new Customer("Ahmed",53,REGULER,10,2),
		new Customer("ibrahem",62,PLATINUM,11,33),
		new Customer("Taha",23,PLATINUM,12,14),
		new Customer("Taha",69,PLATINUM,12,14),

	};
	
	
	/*char ch;
	do
	{
		custumersArr.push_back(AddCustomer());
		cout << "Continue ? Y - N : ";
		cin >> ch;
	} 
	while (ch != 'n' && ch != 'N');*/

	for (int i = 0; i < custumersArr.size(); i++)
	{
		Customers->enqueue(custumersArr[i]);
		Customers->Display();
	}
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
