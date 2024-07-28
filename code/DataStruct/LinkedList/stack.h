#pragma once

#include <iostream>

using namespace std;

class Node {
public:
	double data; // data
	Node* next; // pointer to next
};

class List {
public:
	List(void);// constructor	
	~List(void);// destructor
	bool IsEmpty();
	int InsertNode(int index, double x);
	int DeleteNode(double x);
	void DeleteAll();
	void DisplayList();
private:
	Node* head;
	friend class Stack;
};

class Stack : public List
{
public:
	Stack() {}// constructor
	~Stack() {}// destructor
	double Top();
	void Push(double x);
	double Pop();
	void DisplayStack();
};


List::List(void) {
	head = NULL;
}

List::~List(void) {
	delete head;
}

bool List::IsEmpty() {
	if (head == NULL) {
		return true;
	}
	return false;
}

int List::InsertNode(int index, double x) {
	if (index < 0)
		return -1;
	int currIndex = 1;
	Node* currNode = head;
	while (currNode && index > currIndex) {
		currNode = currNode->next;
		currIndex++;
	}
	//³¬³öÕ»µÄ·¶Î§
	if (index > 0 && currNode == NULL)
		return -1;
	Node* newNode = new Node;
	newNode->data = x;
	//²åÈëÕ»ding
	if (index == 0) {
		newNode->next = head;
		head = newNode;
	}
	else {
		newNode->next = currNode->next;
		currNode->next = newNode;
	}
	return 0;
}

int List::DeleteNode(double x) {
	Node* prevNode = NULL;
	Node* currNode = head;
	int currIndex = 1;
	while (currNode && currNode->data != x) {
		prevNode = currNode;
		currNode = currNode->next;
		currIndex++;
	}
	if (currNode) {
		if (prevNode) {
			prevNode->next = currNode->next;
			delete currNode;
		}
		else {
			head = currNode->next;
			delete currNode;
		}
		return currIndex;
	}
	return 0;
}

void List::DeleteAll()
{
	Node* currNode = head->next;
	Node* newNode = new Node;
	while (currNode != NULL)
	{
		newNode = currNode;
		currNode = currNode->next;
		head->next = currNode;
		newNode->next = NULL;
		delete newNode;
	}
	head = NULL;
}

void List::DisplayList() {
	int num = 0;
	Node* currNode = head;
	while (currNode != NULL) {
		cout << currNode->data << endl;
		currNode = currNode->next;
		num++;
	}
	cout << "Number of nodes in the list: " << num << endl;
}

double Stack::Top()
{
	if (head == NULL)
	{
		cout << "Error: the stack is empty." << endl;
		return -1;
	}
	else
		return head->data;
}

void Stack::Push(double x)
{
	InsertNode(0, x);
}

double Stack::Pop()
{
	if (head == NULL)
	{
		cout << "Error: the stack is empty." << endl;
		return -1;
	}
	else
	{
		double val = head->data;
		DeleteNode(val);
		return val;
	}
}

void Stack::DisplayStack()
{
	DisplayList();
}