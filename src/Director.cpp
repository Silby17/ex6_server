/****************************************
* Yossi Silberhaft & Nava Shemoul						*
* Exercise 5							*
* File: Director.cpp					*
****************************************/
#include <iostream>
#include "Director.h"
using namespace std;


/************************************************************************
 * This is the Director class constructor which is a Professional		*
 ************************************************************************/
Director::Director(int type, int id, int age, std::string desc,
		std::string gender, std::string name)
: Professionals(type, id, age, desc, gender, name){

}


/************************************************************************
 * This function will print all the information of the Director			*
 ************************************************************************/
string Director::printInfo() {

	string fullOut;
	fullOut = this->getName();
	//cout << fullOut << endl;
	return fullOut;
}


/************************************************************************
 * This is the Director class Destructor								*
 ************************************************************************/
Director::~Director(){}
