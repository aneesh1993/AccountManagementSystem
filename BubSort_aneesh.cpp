//////////////////////////////// Final Project - Account Management System ////////////////////////////////
//////// Name - Aneesh Abhyankar
//////// NetID - ana85
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "BubSort_aneesh.h"
#include <iostream>
#include <string>


using namespace std;


BubSort_aneesh::BubSort_aneesh(){}
BubSort_aneesh::~BubSort_aneesh(){}

/// swap nodes in place
void BubSort_aneesh::swapNodes(Node_aneesh *maxPtr, Node_aneesh *toPlace) {

	string stockName = toPlace->getName();
	int numShares = toPlace->getNumShares();
	float pricePerShare = toPlace->getpricePerShare();

	toPlace->setName(maxPtr->getName());
	toPlace->setNumShares(maxPtr->getNumShares());
	toPlace->setpricePerShare(maxPtr->getpricePerShare());

	maxPtr->setName(stockName);
	maxPtr->setNumShares(numShares);
	maxPtr->setpricePerShare(pricePerShare);

}

// bubble sort - overridden from Sort
void BubSort_aneesh::sort(Node_aneesh *head, int size) {

	Node_aneesh *toPlace = head;

	for (int i = 0; i < size - 1; i++) {
		toPlace = head;
		for (int j = 0; j < size - i - 1 && toPlace->getNextLink() != NULL; j++) {
			if (toPlace->getValue() < toPlace->getNextLink()->getValue()) {
				swapNodes(toPlace, toPlace->getNextLink());
			}
			toPlace = toPlace->getNextLink();
		}

	}
}
