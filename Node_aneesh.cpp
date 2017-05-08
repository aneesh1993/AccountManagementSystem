//////////////////////////////// Final Project - Account Management System ////////////////////////////////
//////// Name - Aneesh Abhyankar
//////// NetID - ana85
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Node_aneesh.h"
#include "LinkedList_aneesh.h"
#include <iostream>
#include <string>

using namespace std;

Node_aneesh::Node_aneesh(){}
Node_aneesh::~Node_aneesh(){}

///// overloaded constructor
Node_aneesh::Node_aneesh(string stockName, int numShares, float pricePerShare) {
	setName(stockName);
	setNumShares(numShares);
	setpricePerShare(pricePerShare);
	setNextLink(NULL);
	setPrevLink(NULL);
}

// setter
void Node_aneesh::setName(string name) {
	this->stockName = name;
}
// setter
void Node_aneesh::setNumShares(int num) {
	this->numShares = num;
}
// setter
void Node_aneesh::setpricePerShare(float price) {
	this->pricePerShare = price;
}
// setter
void Node_aneesh::setNextLink(Node_aneesh * next) {
	this->next = next;
}
// setter
void Node_aneesh::setPrevLink(Node_aneesh *prev) {
	this->prev = prev;
}
// getter
string Node_aneesh::getName() {
	return this->stockName;
}
// getter
int Node_aneesh::getNumShares() {
	return this->numShares;
}
// getter
float Node_aneesh::getpricePerShare() {
	return this->pricePerShare;
}
// getter
Node_aneesh* Node_aneesh::getNextLink() {
	return this->next;
}
// getter
Node_aneesh* Node_aneesh::getPrevLink() {
	return this->prev;
}
// getter
float Node_aneesh::getValue() {
	return getpricePerShare() * getNumShares();
}