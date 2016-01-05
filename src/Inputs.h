/****************************************
 * Yossi Silberhaft & Nava Shemoul		*
 * Exercise 5							*
 * File: Inputs.cpp						*
 ****************************************/
#ifndef IO_H
#define IO_H
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

class Inputs{

public:

	/************************************************************************
	 * This is the Inputs Class Constructor									*
	 ************************************************************************/
	Inputs();

	/************************************************************************
	 * This gets the input from the User									*
	 ************************************************************************/
	std::string getInputFromUser();


	/************************************************************************
	 * This is checks if the given number is negative 		    			*
	 ************************************************************************/
	bool checkNegatvie(int n);


	/************************************************************************
	 * This is the Actor Constructor										*
	 ************************************************************************/
	bool checkOptionNumber(int n);


	/************************************************************************
	 * This is the Actor Constructor										*
	 ************************************************************************/
	int getOption(std::string input);


	/************************************************************************
	 * This is the Actor Constructor										*
	 ************************************************************************/
	std::vector<std::string> getInputVector(std::string input);


    virtual ~Inputs();

};

#endif