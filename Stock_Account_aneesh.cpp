//////////////////////////////// Final Project - Account Management System ////////////////////////////////
//////// Name - Aneesh Abhyankar
//////// NetID - ana85
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Stock_Account_aneesh.h"
#include "Bank_Account_aneesh.h"
#include "Account_aneesh.h"
#include "Node_aneesh.h"
#include "LinkedList_aneesh.h"
#include "engine.h"
#include "SelSort_aneesh.h"
#include "BubSort_aneesh.h"
#include "Sort_aneesh.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>

using namespace std;


Stock_Account_aneesh::Stock_Account_aneesh() { setBalance(10000.00); }
Stock_Account_aneesh::~Stock_Account_aneesh() {}

Stock_Account_aneesh::Stock_Account_aneesh(float bal) {
	setBalance(bal);
}

// get price of the share from one of the text files
float Stock_Account_aneesh::getPrice(string symbol) {
	
	srand(time(0));
	int num = rand() % 100 + 1;
	string fileExt;
	if (num < 50)
		fileExt = "1.txt";						// use random number generator to choose file
	else 
		fileExt = "2.txt";
	
	std::ifstream file("Result_" + fileExt);
	string line, sym = "XXX", date;
	float val;

	while (!file.eof() && sym != symbol) {
		file >> sym >> val >> date;				// search for symbol	
	}
	return (sym == symbol) ? val : -1;			// if found return value else -1
}

// display share proce to console
void Stock_Account_aneesh::displayPrice() {
	string symbol;
	cout << "Please enter the stock symbol: ";
	cin >> symbol;
	cout << getPrice(symbol);
}

// buy new shares
void Stock_Account_aneesh::buyShares(Bank_Account_aneesh &bankAcc, LinkedList_aneesh& myList) {
	string symbol;
	float price, amt, temp;
	int numShares;

	cout << "\nPlease enter the stock symbol you wish to purchase: ";
	cin >> symbol;
	price = getPrice(symbol);

	if (price == -1) {
		cout << "\nStock Not Available" << endl;
		return;
	}

	cout << "\nPlease enter the maximum amount you are willing to pay per share: $";
	while (true) {
		if (!(cin >> amt)) {
			cout << "\nEnter only decimal numbers" << endl;
			cout << "\nPlease enter the maximum amount you are willing to pay per share: $";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			break;
	}
	if (price > amt) {
		cout << "\nStock Costlier than what you wish to pay!" << endl;
		return;
	}

	cout << "\nPlease enter the number of shares: ";
	while (true) {
		if (!(cin >> temp && (int)temp == temp)) {
			cout << "\nEnter only whole numbers" << endl;
			cout << "\nPlease enter the number of shares: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			numShares = (int)temp;
			break;
		}
	}
	if (getBalance() < (numShares * price)) {				// cannot buy if balance not available
		cout << "Transaction failed. Required Balance Not Available!" << endl;
		return;
	}
	else {													// withdraw if alance available	
		bankAcc.withdrawMoney((numShares * price));
		Node_aneesh *node = new Node_aneesh(symbol, numShares, price);
		myList.addNode(node);								// add new node
		logTransaction(true, symbol, numShares, price);		// log transaction to file	
	}
}

// sell shares
void Stock_Account_aneesh::sellShares(Bank_Account_aneesh &bankAcc, LinkedList_aneesh& myList) {
	string symbol;
	float price, temp;
	int numShares;
	char op;

	cout << "\nPlease enter the stock symbol you wish to sell: ";
	cin >> symbol;
	price = getPrice(symbol);

	if (price == -1) {
		cout << "\nYou do not own this share!" << endl;
		return;
	}

	Node_aneesh *tempNode = myList.getHead();
	while (tempNode != NULL && tempNode->getName() != symbol) {
		tempNode = tempNode->getNextLink();
	}
	if (tempNode == NULL) {
		cout << "\nYou do not own this share!" << endl;
		delete tempNode;
		return;
	}

	cout << "\nPlease enter the number of shares: ";
	while (true) {
		if (!(cin >> temp && (int)temp == temp)) {
			cout << "\nEnter only whole numbers" << endl;
			cout << "\nPlease enter the number of shares: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			numShares = (int)temp;
			break;
		}
	}
	if (tempNode->getNumShares() < numShares) {				// if entered number more than available shares
		cout << "Not enough shares available to sell\nDo you want to sell all your shares? (Y/N)" << endl;
		cin >> op;											// give option to sell all shares
		if (op == 'Y' || op == 'y')
			numShares = tempNode->getNumShares();
		else {
			delete tempNode;
			return;
		}
	}

	if (tempNode->getNumShares() == numShares) 
		myList.modNode(tempNode, true, numShares);		// sell all shares (i.e. delete node) 
	else 
		myList.modNode(tempNode, false, numShares);		// sell few of the shares (i.e. decrease number of shares)
	
	bankAcc.depositMoney(numShares*price);				// credit money to bank 
	logTransaction(false, symbol, numShares, price);	// log transaction to file	
	
}

// log transaction to file
void Stock_Account_aneesh::logTransaction(bool buy, string symbol, int numShares, float pricePerShare) {
	std::ofstream file;

	if (std::ifstream("stock_transaction_history.txt"))
		file.open("stock_transaction_history.txt", ios::app); // append
	else {
		file.open("stock_transaction_history.txt");
		file << setw(6) << left << "Event" << setw(7) << left << "Symbol" << setw(7) << left << "Number" 
			<< setw(17) << left << "PricePerShare($)" << setw(14) << left << "TotalValue($)" << setw(10) << left << "Time" << endl;
	}
	file << setw(6) << left << ((buy == true) ? "Buy" : "Sell") << setw(7) << left << symbol << setw(7) << left << numShares
		<< setw(17) << left << pricePerShare << setw(14) << left << (numShares*pricePerShare) << setw(10) << left
			<< getTimeStamp(false) << endl;
	file.close();
}

//// display porfolio to console
void Stock_Account_aneesh::displayPortFolio(float balance, LinkedList_aneesh& myList) {
	cout << "\nCash Balance = " << balance << endl;
	
	if (myList.getSize() == 0) {							// if no shares available
		cout << "Portfolio does not contain any shares!" << endl;
		return;
	}
	
	cout << setw(16) << left << "Company-Symbol" << setw(8) << left << "Number" 
		<< setw(17) << left << "Price-per-share" << setw(12) << left << "Total value" << endl;
	
	Node_aneesh *temp = myList.getHead();
	float total = 0.0;
	while (temp != NULL) {
		float price = getPrice(temp->getName());
		int num = temp->getNumShares();
		total += (num*price);
		cout << setw(16) << left << temp->getName() << setw(8) << left << num 
			<< setw(17) << left << price << setw(12) << left << num*price << endl;
		temp = temp->getNextLink();
	}
	cout << "Total portfolio value: $" << total + balance;
}

// display transaction history on console
void Stock_Account_aneesh::displayTransHistory() {
	if (!std::ifstream("stock_transaction_history.txt"))
		cout << "\nNo History Available" << endl;
	else {
		std::ifstream file("stock_transaction_history.txt");
		std::string line;
		cout << "\n";
		while (getline(file, line)) {
			cout << line << endl;
		}
	}
}

// display graph using MATLAB
void Stock_Account_aneesh::displayGraph() {

	if (!(fstream("portfolio_history.txt"))) {
		cout << "\nNo Portfolio Histry Available" << endl;
		return;
	}

	Engine *ep;
	ep = engOpen(NULL);
	if (ep == NULL)
	{
		cout << "\nError: MATLAB Not Found" << endl;
		return;
	}

	double y_arr[20] = {0}, a;
	int i = 0;
	string x_arr[100], str_date, str_time;
	ifstream file;
	file.open("portfolio_history.txt");
	while (i < 100 && file >> a >> str_date >> str_time) {
		y_arr[i] = a;
		x_arr[i] = str_date + str_time;
		i++;
	}

	mxArray *A;
	A = mxCreateDoubleMatrix(1, i, mxREAL);
	memcpy((void *)mxGetPr(A), (void *)y_arr, i * sizeof(double));
	engPutVariable(ep, "y", A);
	
	// plotting function.
	engEvalString(ep, "plot(y);");

	// setting up the title for graph
	engEvalString(ep, "title('Portfolio Value Variation graph');");

	mxDestroyArray(A);
	
}