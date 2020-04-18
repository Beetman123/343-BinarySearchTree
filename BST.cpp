#include "BST.h"

#include <iostream>

using namespace std;


BST::BST()
{
	head = nullptr;
	curr = nullptr;
	temp = nullptr;
}

// error is that none of it is saved !!!!!!!!!!!!!!!!!

// add a node to the BST
//void BST::addNode(const int data)
//{
//	// if empty
//	if (head == nullptr)
//	{
//		head = &newNode(data);
//		curr = head; // so to get rid of an error
//	}
//
//	// if current is empty
//	else if (curr == nullptr) // never got hit (curr was undefined but not nullptr)
//	{
//		curr = &newNode(data);
//	}
//
//	// if data is smaller then current
//	else if (data < curr->data) // EXCEPTION (this->curr was 0xCCCCCC) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!(bigger problem at moment)!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//	{
//		curr = curr->left;
//	}
//
//	// if data is larger then current
//	else if (data > curr->data)
//	{
//		curr = curr->right;
//	}
//}

/*
void BST::addNode(const int data)
{
	// if empty
	if (head == nullptr)
	{
		head = &newNode(data);
		curr = head; // so to get rid of an error
	}

	// if current is empty
	else if (curr == nullptr) // never got hit (curr was undefined but not nullptr)
	{
		curr = &newNode(data);
	}

	// if data is smaller then current
	else if (data < curr->data) // EXCEPTION (this->curr was 0xCCCCCC) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!(bigger problem at moment)!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	{
		curr = curr->left;
	}

	// if data is larger then current
	else if (data > curr->data)
	{
		curr = curr->right;
	}
}
*/


Node BST::newNode(const int data)
{
	Node newNode;
	newNode.data = data;
	newNode.left = nullptr;
	newNode.right = nullptr;

	return newNode;
}

void BST::addNode(const int data, BST* current)
{
	// if empty
	if (head == nullptr)
	{
		head = &newNode(data);
		curr = head; // so to get rid of an error
	}

	// if current is empty
	else if (curr == nullptr) // never got hit (curr was undefined but not nullptr)
	{
		curr = &newNode(data);
	}

	// if data is smaller then current
	else if (data < curr->data) // EXCEPTION (this->curr was 0xCCCCCC) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!(bigger problem at moment)!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	{
		curr = curr->left;
	}

	// if data is larger then current
	else if (data > curr->data)
	{
		curr = curr->right;
	}
}
