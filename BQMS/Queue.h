#pragma once
#include <iostream>
#include "Node.h"
#include "customer.h"
class Queue
{
private:
	Node *head;
	Node *tail;
	int len;
	void SortByPriority(Node*node);
	void IncreasePriorityInQueue();
	void CalculateWaitingTime();
public:
	Queue();
	void enqueue(Customer *customer);
	Customer* dequeue();
	void Display();
};