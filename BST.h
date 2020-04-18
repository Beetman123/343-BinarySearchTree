#pragma once


class BST
{
public:
	
	//typedef struct Node
	//{
	//	Node* left;
	//	Node* right;
	//	int data;

	//	//Node newNode(const int data);
	//};

	BST * left;
	BST * right;
	int data;

	BST();

	BST(const int data);
	
	//BST newNode(const int data);
	
	//void addNode(const int data);
	BST * addNode(BST* root, const int data);

	void deleteTree(); // deletes entire tree

	// void deleteNode (const int data) // deletes only one Node

private:


};

