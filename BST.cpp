#include "BST.h"

#include <iostream>

using namespace std;


BST::BST()
{
	left = nullptr;
	right = nullptr;
	data = NULL;
}

BST::BST(const int value)
{
	left = nullptr;
	right = nullptr;
	data = value;
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

//Node BST::newNode(const int data)
//{
//	Node newNode;
//	newNode.data = data;
//	newNode.left = nullptr;
//	newNode.right = nullptr;
//
//	return newNode;
//}

BST * BST::addNode(BST* root, const int data) // root == curr (current)
{
	// if empty
	if (!root)
	{
		//head = &newNode(data);
		//curr = head; // so to get rid of an error
		return new BST(data);
	}

	// if current is empty
	//else if (curr == nullptr) // never got hit (curr was undefined but not nullptr)
	//{
	//	curr = &newNode(data);
	//}

	// if data is smaller then current
	else if (data < root->data) // EXCEPTION (this->curr was 0xCCCCCC) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!(bigger problem at moment)!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	{
		root->left = addNode(root->left, data);
	}

	// if data is larger then current
	else if (data > root->data)
	{
		root->right = addNode(root->right, data);
	}

	return root;
}
