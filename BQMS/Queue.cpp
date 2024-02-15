#include <iostream>
#include "Queue.h"

Queue::Queue() {
	head = tail = nullptr;
	len = 0;
}

void Queue::SortByPriority(Node*node)
{
	bool flag = true;
	Node* temp = node;
	while (flag && temp->next != nullptr)
	{
		if (temp->customer->getArrivingTime() <= temp->next->customer->getArrivingTime() + temp->next->customer->getServiceTime())
		{
			if (temp->customer->getPriority() > temp->next->customer->getPriority())
			{
				std::swap(temp->customer, temp->next->customer);
				temp = temp->next;
			}
			else
			{
				flag = false;
			}
		}
		else
		{
			flag = false;
		}
	}
}

void Queue::IncreasePriorityInQueue()
{
	Node* temp = tail;
	while (temp != nullptr)
	{
		temp->customer->increasePriority();
		temp = temp->next;
	}
}

void Queue::CalculateWaitingTime()
{
	Node* temp = head;
	int  waitingTime = 0;
	while (temp != nullptr)
	{
		temp->customer->setWaitingTime(waitingTime);
		waitingTime += temp->customer->getServiceTime();
		temp = temp->prev;
	}
}

void Queue::enqueue(Customer *customer)
{
	Node *newNode = new Node();
	newNode->customer = customer;
	if (head == nullptr) {
		head = tail = newNode;
	}
	else {
		newNode->next = tail;
		tail->prev = newNode;
		tail = newNode;
		SortByPriority(tail);
		IncreasePriorityInQueue();
	}
	CalculateWaitingTime();
	len++;
}

Customer* Queue::dequeue()
{
	if (head == nullptr)
		return nullptr;
	else
	{
		Node* temp = head;
		head = head->prev;
		head->next = nullptr;
		temp->prev = nullptr;
		return temp->customer;
	}
}

void Queue::Display()
{
	Node* temp = head;
	std::cout << "=========================\n";
	while (temp != nullptr)
	{
		int min = temp->customer->getArrivingTime() % 60;
		int hour = (temp->customer->getArrivingTime() - min) / 60;
		std::cout << "NAME: " << temp->customer->getName() << "    PRIORTIY: " << temp->customer->getPriority();
		std::cout << "    ARRTIME: " << hour << ":" << min << "    SERVICETIME: " << temp->customer->getServiceTime();
		std::cout << "\n";
		temp = temp->prev;
	}
	std::cout << "\n=========================";
}
