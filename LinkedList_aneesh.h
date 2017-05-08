//////////////////////////////// Final Project - Account Management System ////////////////////////////////
//////// Name - Aneesh Abhyankar
//////// NetID - ana85
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Sort_aneesh.h"
#include "Node_aneesh.h"
#include "SelSort_aneesh.h"
#include "BubSort_aneesh.h"
#include <iostream>
#include <string>

using namespace std;

#pragma once
//////// class holds linked list and all its operations
class LinkedList_aneesh
{
	Node_aneesh *myHead;
	Node_aneesh *myTail;
	int mySize;
	int sort_method;
	Sort_aneesh *sort;

public:
	LinkedList_aneesh();
	~LinkedList_aneesh();

	int getSortMethod();
	void setSortMethod(int method);

	Node_aneesh* getHead();
	void setHead(Node_aneesh *head);

	Node_aneesh* getTail();
	void setTail(Node_aneesh *tail);
	
	void setSize(int size);
	int getSize();

	void addNode(Node_aneesh *node);
	void modNode(Node_aneesh *toMod, bool del, int numShares);
	//void swapNodes(Node_aneesh *minPtr, Node_aneesh *toPlace);
	//void sortList();
};

