#include <iostream>
#include <cmath>
#include "customer.h"
#include <cstdlib> 
#include <string>
#include "Utility.h"

Customer::Customer(std::string name, int age,AccountType acc, int HOUR , int MIN) {
	 setName(name);
	 setAge(age);
	 setAccType(acc);
	 setPriority();
	 setArrivingTime(HOUR, MIN);
 }

 void Customer::setAccType(AccountType acc) {
	 this->AccType = acc;
 }

 AccountType Customer::getAccType() const {
	 return this->AccType;
 }

 void Customer::setAge(int age) {
	 this->age = age;
 }

 int Customer::getAge() const {
	 return this->age;
 }

 void Customer::increasePriority() {
	 priority++;
 }

 int Customer::getPriority() const {
	 return priority;
 }

 void Customer::setName(std::string name) {
	 this->name = name;
 }

 std::string Customer::getName() const {
	 return name;
 }

 void Customer::setArrivingTime(int h, int m)
 {
	 ArrivaingTime = (h * 60) + m;
 }

 int Customer::getArrivingTime() const
 {
	 return ArrivaingTime;
 }

 int Customer::getServiceTime() const
 {
	 return ServiceTime;
 }

 void Customer::setWaitingTime(int witingTime)
 {
	 WaitingTime = witingTime;
 }

 int Customer::getWitingTime() const
 {
	 return WaitingTime;
 }

 void Customer::setPriority() {
	 priority = 0;
	 if (getAccType() == PLATINUM)
		 priority += 5;
	 else if (getAccType() == GOLD)
		 priority += 3;
	 else if (getAccType() == SELVER)
		 priority++;
	 if (getAge() > 60)
		 priority += 3;
 }

 void Customer::setServiceTime(int time)
 {
	 ServiceTime = time;
 }

 void Customer::TallerNumber(int n)
 {
	 tallerNumber = n;
 }

 int Customer::TallerNumber() const
 {
	 return tallerNumber;
 }

 std::string Customer::toString()
 {
	 std::string name = getName();
	 std::string age = std::to_string(getAge());
	 std::string arrive = Utility::GetInHourFormat(getArrivingTime());
	 std::string wait = std::to_string(getWitingTime());
	 std::string priorty = std::to_string(getPriority());
	 std::string serive = std::to_string(getServiceTime());
	 int leavetime = getServiceTime() + getWitingTime() + getArrivingTime();
	 std::string leave = Utility::GetInHourFormat(leavetime);
	 std::string taller = std::to_string(TallerNumber());

	 return name + "\t\t " + age + "\t " + priorty + "\t\t" + arrive + "\t\t" + wait + "\t\t" + serive + "\t\t" + leave + "\t\t" + taller + "\t   |";
 }
