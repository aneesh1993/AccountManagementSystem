//////////////////////////////// Final Project - Account Management System ////////////////////////////////
//////// Name - Aneesh Abhyankar
//////// NetID - ana85
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "SelSort_aneesh.h"
#include <iostream>
#include <string>

using namespace std;

SelSort_aneesh::SelSort_aneesh(){}
SelSort_aneesh::~SelSort_aneesh(){}

/////// Swap nodes in place
void SelSort_aneesh::swapNodes(Node_aneesh *maxPtr, Node_aneesh *toPlace) {

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

////// Selection sort - overridden from Sort
void SelSort_aneesh::sort(Node_aneesh *head, int size) {

	Node_aneesh *toPlace = head;

	for (int i = 0; i < size - 1 && toPlace != NULL; i++) {

		Node_aneesh *iterate = toPlace;
		Node_aneesh *maxPtr = NULL;
		float maxVal = FLT_MIN;

		while (iterate != NULL) {							// find max in the list
			if (iterate->getValue() > maxVal) {
				maxVal = iterate->getValue();
				maxPtr = iterate;
			}
			iterate = iterate->getNextLink();
		}
		if (maxVal != NULL && maxPtr->getName() != toPlace->getName()) {
			swapNodes(maxPtr, toPlace);						// swap it to the front position
			toPlace = maxPtr->getNextLink();
		}
		else {
			toPlace = toPlace->getNextLink();				// move to next position
		}

	}
}