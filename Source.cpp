#include <iostream>
#include <fstream>
#include "BST.h"

using namespace std;

/*
Construct a Binary Search Tree (BST) program in C++.  The program is required to:

1) load the BST from a dataset (I will provide the datasets-see below) in the order they exist in the dataset.

2) after the BST is built analyze the BST and display the following values:

2.1) the smallest branch height

2.2) the highest branch height

2.3) the number of nodes in the tree

2.4) the determination if the tree is balanced

2.5) the determination if the tree is complete

Submit (in Canvas) the C++ code and copies of the execution of each of the datasets that display the five values (from above).
*/




int main()
{
	// open file with data
	ifstream inFile;
	int data;

	BST tree; // !!!!!!!!!!!!!!!!

	// read in data
	inFile.open("CSS343_A1_F1.txt");

	// check if it failed
	if (inFile.fail())
	{
		return 1; // ????????????????????????????????????????
	}

	while (inFile >> data)							// does this work ???
	{
		// keep top
		tree.addNode(data);       // ERROR: when function ends the data is erased and is rendered null !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}

	system("pause");
	return 0;
}