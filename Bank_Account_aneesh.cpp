//////////////////////////////// Final Project - Account Management System ////////////////////////////////
//////// Name - Aneesh Abhyankar
//////// NetID - ana85
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Bank_Account_aneesh.h"
#include "Account_aneesh.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;


Bank_Account_aneesh::Bank_Account_aneesh() { setBalance(10000.00); }
Bank_Account_aneesh::~Bank_Account_aneesh() {}

Bank_Account_aneesh::Bank_Account_aneesh(float bal) {
	setBalance(bal);
}

// display balance in account
void Bank_Account_aneesh::displayBalance() {
	cout << "You have $" << this->getBalance() << " in your bank account." << endl;
}

// add money to account
void Bank_Account_aneesh::depositMoney(float amt) {
	this->setBalance(this->getBalance() + amt);
	logTransaction(amt, false);
}

// withdraw
void Bank_Account_aneesh::withdrawMoney(float amt) {
	if (this->getBalance() < amt)
		cout << "Transaction failed. Required Balance Not Available!" << endl;
	else {
		this->setBalance(this->getBalance() - amt);
	}
	logTransaction(amt, true);
}

// log transaction to text file
void Bank_Account_aneesh::logTransaction(float amt, bool withdraw) {
	std::ofstream file;

	if (std::ifstream("bank_transaction_history.txt")) 
		file.open("bank_transaction_history.txt", ios::app); // append
	else {
		file.open("bank_transaction_history.txt");
		file << setw(12) << left << "Event" << setw(10) << left << "Amount($)" << setw(11) << left << "Date" 
			<< setw(11) << left << "Balance" << endl;
	}

	file << setw(12) << left << ((withdraw == true) ? "Withdrawal" : "Deposit") << setw(10) << left << amt 
		<< setw(11) << left << getTimeStamp(true) << setw(11) << left << this->getBalance() << endl;
	file.close();
}

// print transaction history to console
void Account_aneesh::printHistory() {
	//std::ifstream file;
	if (!std::ifstream("bank_transaction_history.txt"))
		cout << "\nNo History Available" << endl;
	else {
		std::ifstream file("bank_transaction_history.txt");
		std::string line;
		cout << "\n";
		while (getline(file, line)) {
			cout << line << endl;
		}
	}
}

// get balance to restore state
float Bank_Account_aneesh::getSavedBalance() {
	float bal;
	std::ifstream file;
	if (std::ifstream("current_balance.txt")) {
		file.open("current_balance.txt");
		file >> bal;
		file.close();
	}
	else {
		bal = 10000.00;
	}
	return bal;
}

// save balance to file before exiting
void Bank_Account_aneesh::SaveBalance() {
	std::ofstream file;
	file.open("current_balance.txt", ios::trunc); // overwrite
	file << getBalance();
	file.close();
}