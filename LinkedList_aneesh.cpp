//////////////////////////////// Final Project - Account Management System ////////////////////////////////
//////// Name - Aneesh Abhyankar
//////// NetID - ana85
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "LinkedList_aneesh.h"
#include <iostream>
#include <string>


LinkedList_aneesh::LinkedList_aneesh(){
	setHead(NULL);
	setTail(NULL);
	setSize(0);
	setSortMethod(0);
}
LinkedList_aneesh::~LinkedList_aneesh(){ setSortMethod(0); }

// setter
void LinkedList_aneesh::setHead(Node_aneesh *head) {
	this->myHead = head;
}
// setter
void LinkedList_aneesh::setTail(Node_aneesh *tail) {
	this->myTail = tail;
}
// setter
void LinkedList_aneesh::setSize(int size) {
	this->mySize = size;
}
// getter
Node_aneesh* LinkedList_aneesh::getHead() {
	return this->myHead;
}
// getter
Node_aneesh* LinkedList_aneesh::getTail() {
	return this->myTail;
}
// getter
int LinkedList_aneesh::getSize() {
	return this->mySize;
}
// getter
int LinkedList_aneesh::getSortMethod() {
	return sort_method;
}
// setter
void LinkedList_aneesh::setSortMethod(int method) {

	sort_method = method;
	if (method == 1)
		sort = new SelSort_aneesh;					// Select class depending on input from user
	else if (method == 2)							// example of adapter pattern
		sort = new BubSort_aneesh;

}

// add new node
void LinkedList_aneesh::addNode(Node_aneesh *node) {
	if (getSize() == 0) {
		setHead(node);
		setTail(node);
	}
	else {
		Node_aneesh *temp = getHead();
		while (temp != NULL) {
			if (temp->getName() == node->getName())
				break;
			temp = temp->getNextLink();
		}
		if (temp == NULL) {
			Node_aneesh *last = getTail();
			last->setNextLink(node);
			node->setPrevLink(last);
			setTail(node);
		}
		else {
			temp->setNumShares(temp->getNumShares() + node->getNumShares());
			setSize(getSize() - 1);
		}
	}
	setSize(getSize() + 1);

	if(sort != NULL && getSize() >= 2)
		sort->sort(getHead(), getSize());			// call sort function from either bubSort or SelSort class

}

// modify information inside a node
void LinkedList_aneesh::modNode(Node_aneesh *toMod, bool del, int numShares) {
	if (del) {
		if (getSize() == 1) {
			setHead(NULL);
			setTail(NULL);
		}
		else {
			if (toMod->getPrevLink() == NULL) {
				setHead(toMod->getNextLink());
			}
			else if (toMod->getNextLink() == NULL) {
				setTail(toMod->getPrevLink());
			}
			else {
				Node_aneesh *temp = toMod->getPrevLink();
				temp->setNextLink(toMod->getNextLink());
				toMod->getNextLink()->setPrevLink(temp);
				delete temp;
			}
		}
		setSize(getSize() - 1);
	}
	else {
		toMod->setNumShares(toMod->getNumShares() - numShares);
	}
	if (sort != NULL && getSize() >= 2)
		sort->sort(getHead(), getSize());
}
