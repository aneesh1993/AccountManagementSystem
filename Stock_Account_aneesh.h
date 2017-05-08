//////////////////////////////// Final Project - Account Management System ////////////////////////////////
//////// Name - Aneesh Abhyankar
//////// NetID - ana85
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Account_aneesh.h"
#include "Bank_Account_aneesh.h"
#include "Node_aneesh.h"
#include "LinkedList_aneesh.h"

#pragma once
///////////// Inherits from Acount class ////////////////
class Stock_Account_aneesh : public Account_aneesh
{
	
	string fileExtension;
	
public:
	Stock_Account_aneesh();
	Stock_Account_aneesh(float bal);
	~Stock_Account_aneesh();

	float getPrice(string symbol);
	void buyShares(Bank_Account_aneesh &bankAcc, LinkedList_aneesh& myList);
	void sellShares(Bank_Account_aneesh &bankAcc, LinkedList_aneesh& myList);
	void displayPrice();
	void logTransaction(bool buy, string symbol, int numShares, float pricePerShare);
	void displayPortFolio(float balance, LinkedList_aneesh& myList);
	void displayTransHistory();
	void displayGraph();
};

