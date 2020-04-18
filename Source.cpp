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

	BST * tree = nullptr; // !!!!!!!!!!!!!!!!

	// read in data
	inFile.open("CSS343_A1_F1.txt");

	// check if file was opened if failed end program with 1 (error state)
	if (inFile.fail())
	{
		return 1; 
	}

	// Create BST with file information
	while (inFile >> data)							
	{
		// keep top
		tree = tree->addNode(tree, data);
	}


	// delete the tree
	tree = tree->deleteTree();

	// testing for delete tree
	/*
	if (tree == nullptr)
	{
		cout << "was deleted!";
	}
	*/

	system("pause");
	return 0;
}
/*

I march before armies, a thousand salute me.
My fall can bring victory, but no one would shoot me.
The wind is my lover, one - legged am I.
Name me and see me at home in the sky.

I march before armies, a thousand salute me.
My fall can bring victory, but no one would shoot me.
Thou one - legged I am, 
The wind is my lover, one - legged am I.
Name me and see me at home in the sky.

*/