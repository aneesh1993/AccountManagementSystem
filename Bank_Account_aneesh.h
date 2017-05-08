//////////////////////////////// Final Project - Account Management System ////////////////////////////////
//////// Name - Aneesh Abhyankar
//////// NetID - ana85
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Account_aneesh.h"

#pragma once
///////////// Inherits from Acount class ////////////////
class Bank_Account_aneesh : public Account_aneesh
{
	void logTransaction(float amt, bool withdraw);
public:
	Bank_Account_aneesh();
	~Bank_Account_aneesh();
	Bank_Account_aneesh(float bal);

	void displayBalance();
	void depositMoney(float amt);
	void withdrawMoney(float amt);
	float getSavedBalance();
	void SaveBalance();
};

