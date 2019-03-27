// Povezane liste

//
//

#include "pch.h"
#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node *next;
};

void insertElementFront(Node *&head, int value)    //dodavanje elementa na početak liste
{
	Node *temp = new Node;
	temp->value = value;
	temp->next = head;
	head = temp;
}

void insertElementEnd(Node *&head, int value)    //dodavanje elementa na kraj liste
{
	Node *n = new Node;
	n->value = value;
	n->next = nullptr;

	Node *temp = head;
	if (temp == nullptr)
	{
		temp = n;
		head = temp;
	}
	else
	{
			while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = n;
	}
}

int main()
{
	/*Node *head = nullptr;
	Node *tail = nullptr;

	insertElementEnd(head, 1);*/

	

}


