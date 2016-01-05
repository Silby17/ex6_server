/****************************************
 * Yossi Silberhaft & Nava Shemoul						*
 * Exercise 5							*
 * File: Actor.cpp						*
 ****************************************/
#include "Actor.h"
#include <iostream>
#include <sstream>
#include "Cinema.h"
using namespace std;


/************************************************************************
 * This is the Actor class constructor which is a Professional			*
 ************************************************************************/
Actor::Actor(int type, int id, int age, std::string desc,
		std::string gender, std::string name)
:Professionals(type, id, age, desc, gender, name){}


/************************************************************************
 * This function will print all the information of the Actor			*
 ************************************************************************/
string Actor::printInfo(){
	string fullOutput;
	string age;

	//Converts the age from an int to a string
	ostringstream convert;
	convert << this->getAge();
	age = convert.str();


	//Puts the string together for output
	fullOutput = this->getName() + age;

	//cout << fullOutput << endl;
	return fullOutput;
}


/************************************************************************
 * This is the Actor class Destrctor 									*
 ************************************************************************/
Actor::~Actor(){}
