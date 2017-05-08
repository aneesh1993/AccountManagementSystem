//////////////////////////////// Final Project - Account Management System ////////////////////////////////
//////// Name - Aneesh Abhyankar
//////// NetID - ana85
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Node_aneesh.h"
#include <iostream>
#include <string>

#pragma once
///// abstract class sort
//// declares a virtual function called sort
class Sort_aneesh
{
public:
	virtual void sort(Node_aneesh *head, int size) = 0;
	Sort_aneesh();
	~Sort_aneesh();
};

