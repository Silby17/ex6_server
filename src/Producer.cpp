/****************************************
* Yossi Silberhaft & Nava Shemoul						*
* Exercise 5							*
* File: Producer.cpp					*
****************************************/

#include <iostream>
#include "Producer.h"
using namespace std;

/************************************************************************
 * This is the Producer class constructor which is a Professional		*
 ************************************************************************/
Producer::Producer(int type, int id, int age, string desc,
		std::string gender, std::string name)
:Professionals(type, id, age, desc, gender, name){

}


/************************************************************************
 * This function prints out the Producer in its correct format			*
 ************************************************************************/
std::string Producer::printInfo(){
	string fullOutput = this->getName();
	return fullOutput;
	//cout << fullOutput << endl;
}


/************************************************************************
 * This is the Producer Class Destructor								*
 ************************************************************************/
Producer::~Producer(){}
