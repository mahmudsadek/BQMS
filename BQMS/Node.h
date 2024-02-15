#pragma once
#include "customer.h"
class Node
{
public:
	Customer *customer;
	Node *next;
	Node *prev;
	Node() {
		customer = nullptr;
		next = prev = nullptr;
	}
};

