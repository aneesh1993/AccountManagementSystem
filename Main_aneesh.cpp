//////////////////////////////// Final Project - Account Management System ////////////////////////////////
//////// Name - Aneesh Abhyankar
//////// NetID - ana85
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "Account_aneesh.h"
#include "Stock_Account_aneesh.h"
#include "Bank_Account_aneesh.h"
#include "Node_aneesh.h"
#include "LinkedList_aneesh.h"

using namespace std;


float getAmount(string str) {
	float temp;
	cout << "\nPlease select the amount you wish to " + str + " : $";
	while (true) {
		if (cin >> temp)
			return temp;
		else {
			cout << "Enter only decimal numbers" << endl;
			cout << "\nPlease select the amount you wish to " + str + " : $";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

// bank account menu and switch case
void bank_account(Stock_Account_aneesh& stockAcc, Bank_Account_aneesh& bankAcc, LinkedList_aneesh& myList) {
	float temp;
	int option;

	while (true) {
		cout << "\n\nBank Account Menu" << endl;
		cout << "Please select an option:" << endl;
		cout << "1. View account balance" << endl;
		cout << "2. Deposit money" << endl;
		cout << "3. Withdraw money" << endl;
		cout << "4. Print out history" << endl;
		cout << "5. Return to previous menu" << endl;
		cout << "Option : ";
		if (cin >> temp && (int)temp == temp && temp > 0 && temp < 6) {
			option = (int)temp;
			switch (option) {

			case 1:
				// view account balance
				bankAcc.displayBalance();
				break;
			case 2:
				// deposit money
				bankAcc.depositMoney(getAmount("deposit"));
				// save balance to text file
				bankAcc.SaveBalance();
				break;
			case 3:
				// withdraw money
				bankAcc.withdrawMoney(getAmount("withdraw"));
				// save balance to text file
				bankAcc.SaveBalance();
				break;
			case 4:
				// print transaction history
				bankAcc.printHistory();
				break;
			case 5:
				return;
			}
		}
		else {
			cout << "\nEnter only integers from 1 through 3" << endl;
		}
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

// stock account menu and switch case
void stock_account(Stock_Account_aneesh& stockAcc, Bank_Account_aneesh& bankAcc, LinkedList_aneesh& myList) {

	float temp;
	int option;

	if (myList.getSortMethod() == 0) {
		while(true) {
			cout << "\nPlease select sorting method for maintaining your portfolio" << endl;
			cout << "1. Selection Sort" << endl;
			cout << "2. Bubble Sort" << endl;

			if (cin >> temp && (int)temp == temp && temp > 0 && temp < 3) {
				myList.setSortMethod((int)temp);
				break;
			}
			else {
				cout << "\nEnter only integers from 1 through 3" << endl;
			}
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	while (true) {
		cout << "\n\nStock Account Menu" << endl;
		cout << "Please select an option:" << endl;
		cout << "1. Display the price for a stock symbol" << endl;
		cout << "2. Display the current portfolio" << endl;
		cout << "3. Buy shares" << endl;
		cout << "4. Sell shares" << endl;
		cout << "5. View a graph for the portfolio value" << endl;
		cout << "6. View transaction history" << endl;
		cout << "7. Return to previous menu" << endl;
		cout << "Option : ";

		if (cin >> temp && (int)temp == temp && temp > 0 && temp < 8) {
			option = (int)temp;
			switch (option) {

			case 1:
				stockAcc.displayPrice();
				break;
			case 2:
				// display portfolio;
				stockAcc.displayPortFolio(bankAcc.getBalance(), myList);
				break;
			case 3:
				// buy shares;
				stockAcc.buyShares(bankAcc, myList);
				bankAcc.SaveBalance();
				break;
			case 4:
				//sell shares;
				stockAcc.sellShares(bankAcc, myList);
				bankAcc.SaveBalance();
				break;
			case 5:
				// view graph;
				stockAcc.displayGraph();
				break;
			case 6:
				// transaction history;
				stockAcc.displayTransHistory();
				break;
			case 7:
				return;
			}
		}
		else {
			cout << "\nEnter only integers from 1 through 7" << endl;
		}
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

}

// main menu display and value swich case
void main_menu(Stock_Account_aneesh& stockAcc, Bank_Account_aneesh& bankAcc, LinkedList_aneesh &myList) {

	float temp;
	int option;

	while (true) {
		cout << "\nMain Menu" << endl;
		cout << "Please select an account to access:" << endl;
		cout << "1. Stock Portfolio Account" << endl;
		cout << "2. Bank Account" << endl;
		cout << "3. Exit" << endl;
		cout << "Option : ";

		if (cin >> temp && (int)temp == temp && temp > 0 && temp < 4) {
			option = (int)temp;
			if (option == 1)
				stock_account(stockAcc, bankAcc, myList);		// stock account menu
			else if (option == 2)
				bank_account(stockAcc, bankAcc, myList);		// bank account menu
			else
				return;
		}
		else {
			cout << "\nEnter only integers from 1 through 3" << endl;
		}
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}


}

// load portfolio state
void loadState(LinkedList_aneesh &myList) {
	
	string name;
	int numShares;
	float pricePerShare;
	
	if (std::ifstream("portfolio_state.txt")) {
		
		std::ifstream infile("portfolio_state.txt");

		while (infile >> name >> numShares >> pricePerShare) {
			Node_aneesh *node = new Node_aneesh(name, numShares, pricePerShare);
			myList.addNode(node);
		}
		infile.close();
	}
}

void saveState(Stock_Account_aneesh& stockAcc, LinkedList_aneesh &myList) {
	std::ofstream file;
	file.open("portfolio_state.txt", ios::trunc);
	float total = 0.0;

	Node_aneesh *temp = myList.getHead();
	while (temp != NULL) {
		float price = stockAcc.getPrice(temp->getName());
		int num = temp->getNumShares();
		total += (num*price);
		file << temp->getName() << "\t" << temp->getNumShares() << "\t" << temp->getpricePerShare() << endl;
		temp = temp->getNextLink();
	}
	
	file.close();

	std::ofstream file1;
	file1.open("portfolio_history.txt", ios::app);
	file1 << total << "\t" << stockAcc.getTimeStamp(true) + " " + stockAcc.getTimeStamp(false) << endl;
	file1.close();
}

int main() {
	
	Stock_Account_aneesh stockAcc; 
	Bank_Account_aneesh bankAcc;	
	LinkedList_aneesh myList;

	///////// load from saved state
	bankAcc.setBalance(bankAcc.getSavedBalance());
	stockAcc.setBalance(bankAcc.getSavedBalance());

	// load portfolio
	loadState(myList);

	// display menu
	cout << "Welcome to the Account Management System." << endl;
	main_menu(stockAcc, bankAcc, myList);
	
	// save state before quiting
	saveState(stockAcc, myList);

	system("pause");
	return 0;
}