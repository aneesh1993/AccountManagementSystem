//////////////////////////////// Final Project - Account Management System ////////////////////////////////
//////// Name - Aneesh Abhyankar
//////// NetID - ana85
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Account_aneesh.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

Account_aneesh::Account_aneesh() {}


Account_aneesh::~Account_aneesh() {}

// setter
void Account_aneesh::setBalance(float bal) {
	this->balance = bal;
}
// getter
float Account_aneesh::getBalance() {
	return this->balance;
}

// return time stamp as a string
string Account_aneesh::getTimeStamp(bool bank) {
	time_t t;
	struct tm myTime;
	time(&t);
	localtime_s(&myTime, &t);

	int Month = myTime.tm_mon + 1;
	int Day = myTime.tm_mday;
	int Year = myTime.tm_year + 1900;
	int Hour = myTime.tm_hour;
	int Min = myTime.tm_min;
	int Sec = myTime.tm_sec;

	if (bank) {
		string res =  to_string(Month) + string("/") + to_string(Day) + string("/") + to_string(Year);
		return res;
	}
	else {
		string res = to_string(Hour) + string(":") + to_string(Min) + string(":") + to_string(Sec);
		return res;
	}
}