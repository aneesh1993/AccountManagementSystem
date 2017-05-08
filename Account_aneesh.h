//////////////////////////////// Final Project - Account Management System ////////////////////////////////
//////// Name - Aneesh Abhyankar
//////// NetID - ana85
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <string>

using namespace std;

#pragma once
//////////////////// Base Class of Bank Account and Stock Account /////////////////
class Account_aneesh
{
	float balance;
public:
	Account_aneesh();
	~Account_aneesh();
	float getBalance();
	void setBalance(float bal);
	string getTimeStamp(bool bank);
	void printHistory();
};
