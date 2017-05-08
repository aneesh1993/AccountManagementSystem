//////////////////////////////// Final Project - Account Management System ////////////////////////////////
//////// Name - Aneesh Abhyankar
//////// NetID - ana85
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Sort_aneesh.h"
#include "Node_aneesh.h"
#include <iostream>
#include <string>

#pragma once
//////////// derived from Sort abstract class 
////// an example of adapter pattern //////////
class SelSort_aneesh : public Sort_aneesh
{
	void swapNodes(Node_aneesh *maxPtr, Node_aneesh *toPlace);

public:
	SelSort_aneesh();
	~SelSort_aneesh();
	//void sel_sort(LinkedList_aneesh &list);
	virtual void sort(Node_aneesh *head, int size);
};

