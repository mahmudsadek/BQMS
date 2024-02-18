#include <iostream>
#include <cmath>
#include "customer.h"
#include <cstdlib> 


Customer::Customer(std::string name, int age,AccountType acc, int HOUR , int MIN) {
	 setName(name);
	 setAge(age);
	 setAccType(acc);
	 setPriority();
	 setArrivingTime(HOUR, MIN);
	 setServiceTime();
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
