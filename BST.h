#pragma once

typedef struct Node
{
	Node* left;
	Node* right;
	int data;

	//Node newNode(const int data);
};


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


	BST();
	
	Node newNode(const int data);
	
	//void addNode(const int data);
	void addNode(const int data, BST* current);
	// void deleteNode(const int data);

	

	Node* head,
		* curr,
		* temp; // ?



private:


};

