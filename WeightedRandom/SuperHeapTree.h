#pragma once
#include "NumberWeight.h"


//Complete binary tree class.  Yes it looks like a list, but it's not.  That's the magic of complete binary trees.
//Super heap trees are different than heap trees.
//Heap Tree-Every child node is less than parent.  
//Super Heap Tree-Every node at depth X+1 < every node at depth X.
//The neat thing about complete trees is you can represent them as linear arrays and calculate the children/parent node based on a simple formula
//Root = index 0.
class SuperHeapTree : private std::vector<NumberWeight> //private to make thread friendly
{
	//METHODS----------------------------------------------------------------------------------
public:
	SuperHeapTree(const std::vector<NumberWeight>& _weights);
	//theres a bug in STL where virtual destructors don't work as intended.
private:
	//Makes the super heap tree and stores it internally
	void superHeapify(std::vector<NumberWeight>& _weightList); //Put numbers with highest probability at top of binary tree.  Reduces number of times we have to go down tree.



	//ATTRIBUTES---------------------------------------------------------------------------
public:
private:
};

