/****************************************
 * Yossi Silberhaft & Nava Shemoul		*
 * Exercise 5							*
 * File: Inputs.cpp						*
 ****************************************/
#include "Inputs.h"
#include <list>
#include <sstream>
#include <iterator>
using namespace std;


/************************************************************************
 * This is the constructor for the Inputs Class							*
 ************************************************************************/
Inputs::Inputs(){}

/************************************************************************
 * This function gets an input string from the user						*
 ************************************************************************/
string Inputs::getInputFromUser(){
	string input;

	getline(cin, input);
	return input;
}

/************************************************************************
 * This function gets the option number from the input string of the	*
 * user and returns the number											*
 ************************************************************************/
int Inputs::getOption(string input){
	string option;
	option = input.at(0);

	if(option == "-" && input.at(1) == '1'){
		return -1;
	}
	else {
		int intOption = atoi(option.c_str());
		return intOption;
	}
	return 0;
}


/************************************************************************
 * This function takes a string and breaks it down into a string vector	*
 * and returns the string Vector										*
 ************************************************************************/
vector<string> Inputs::getInputVector(string input){
	vector<string> strVec;
	istringstream iss(input);
	copy(istream_iterator<string>(iss),
			istream_iterator<string>(),
			back_inserter(strVec));

	return strVec;
}


/************************************************************************
 * This function checks if the number provided is a negative number		*
 * if it is it returns false, if it is than it returns true				*
 ************************************************************************/
bool Inputs::checkNegatvie(int n){
	if(n < 0){
		return false;
	}
	return true;
}


/************************************************************************
 * This is the Class destructor											*
 ************************************************************************/
Inputs::~Inputs(){}