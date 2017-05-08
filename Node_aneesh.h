//////////////////////////////// Final Project - Account Management System ////////////////////////////////
//////// Name - Aneesh Abhyankar
//////// NetID - ana85
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>

using namespace std;

#pragma once
///////// Node class holds information for each node
class Node_aneesh
{
	friend class LinkedList_aneesh;

	string stockName;
	int numShares;
	float pricePerShare;
	Node_aneesh *next, *prev;

public:
	Node_aneesh(string stockName, int numShares, float pricePerShare);
	Node_aneesh();
	~Node_aneesh();

	void setName(string name);
	void setNumShares(int num);
	void setpricePerShare(float price);
	void setNextLink(Node_aneesh * next);
	void setPrevLink(Node_aneesh *prev);

	string getName();
	int getNumShares();
	float getpricePerShare();
	float getValue();

	Node_aneesh* getNextLink();
	Node_aneesh* getPrevLink();
};

