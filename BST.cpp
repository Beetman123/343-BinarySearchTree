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
	else if (data < root->data) 
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

int BST::largestBranch()
{
	int sizeLeft = 0,
		sizeRight = 0;

	// check left
	if (right != nullptr)
	{
		sizeRight = right->largestBranch();
	}

	if (left != nullptr)
	{
		sizeLeft = left->largestBranch();
	}

	// if both are empty
	if (left == nullptr && right == nullptr)
	{
		return 1;
	}

	// if left is bigger then right
	else if (sizeLeft > sizeRight)
	{
		return 1 + sizeLeft;
	}

	// if right is bigger then left 
	else
	{
		return 1 + sizeRight;
	}
}

int BST::smallestBranch()
{
	int sizeLeft = 0,
		sizeRight = 0;

	// check left
	if (right != nullptr)
	{
		sizeRight = right->smallestBranch();
	}

	if (left != nullptr)
	{
		sizeLeft = left->smallestBranch();
	}

	// if both are empty
	if (left == nullptr && right == nullptr)
	{
		return 1;
	}

	// if left is bigger then right
	else if (sizeLeft > sizeRight)
	{
		return 1 + sizeRight;
	}

	// if right is bigger then left 
	else
	{
		return 1 + sizeLeft;
	}
}

// NOT GIVING CORRECT ANSWER
int BST::numberOfNodes()
{
	int sizeLeft = 0,
		sizeRight = 0;

	// check left
	if (right != nullptr)
	{
		sizeRight = right->largestBranch();
	}

	if (left != nullptr)
	{
		sizeLeft = left->largestBranch();
	}

	return 1 + sizeLeft + sizeRight;
}

bool BST::balancedTree()
{
	// if the difference between them is more then 1
	if (this->largestBranch() - this->smallestBranch() > 1)
	{
		return false;
	}
	
	else
	{
		return true;
	}
}

bool BST::complete()
{
	// check that all the nodes are only one difference apart
	if (!this->balancedTree())
	{
		return false;
	}

	// if there are no seperate levels then it is automaticly complete
	else if (this->largestBranch() == this->smallestBranch())
	{
		return true;
	}

	// go from left to right checking that the length is equal to largestBranch 
	// until it is equal to smallest branch
	// iff any after that are equal to largestBranch 
	// then return false 
	// else return true
	else
	{
		bool ifCompleteTree = true;
		this->checkComplete(ifCompleteTree);

		if (ifCompleteTree)
		{
			return true;
		}

		else
		{
			return false;
		}

	}

}

int BST::checkComplete(bool ifComplete)
{
	int sizeLeft = 0,
		sizeRight = 0;

	// check left
	if (right != nullptr)
	{
		sizeRight = right->largestBranch();
	}

	if (left != nullptr)
	{
		sizeLeft = left->largestBranch();
	}

	// if both are empty
	if (left == nullptr && right == nullptr)
	{
		return 1;
	}

	// if left is bigger then right
	else if (sizeLeft > sizeRight)
	{
		return 1 + sizeLeft;
	}

	// if right is bigger then left 
	else
	{
		ifComplete = false;
		return 1 + sizeRight;
	}
}

BST * BST::deleteTree()
{
	// go all the way to the right then all the way to the left then delete 
	
	if (right != nullptr)
	{
		right = right->deleteTree();
	}

	if (left != nullptr)
	{
		left = left->deleteTree();
	}

	delete this;
	
	return nullptr;
	
	// repeat till all gone
}
