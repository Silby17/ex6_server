/****************************************
* Yossi Silberhaft & Nava Shemoul						*
* Exercise 6							*
* File: Screenwriter.cpp				*
****************************************/
#include <iostream>
#include "Screenwriter.h"
using namespace std;


/************************************************************************
 * This is the Screenwriter class constructor which is a Professional		*
 ************************************************************************/
Screenwriter::Screenwriter(int type, int id, int age, std::string desc,
		std::string gender, std::string name)
:Professionals(type, id, age, desc, gender, name){

}


/************************************************************************
 * This function prints the Screenwriter in its correct Format			*
 ************************************************************************/
string Screenwriter::printInfo(){
	string output = this->getName() + this->getJobDescription();
	return output;
}


/************************************************************************
 * This is the Screenwriter Destructor									*
 ************************************************************************/
Screenwriter::~Screenwriter(){}

