/****************************************
 * Yossi Silberhaft & Nava Shemoul						*
 * Exercise 6							*
 * File: Professional.cpp				*
 ****************************************/
#include "Professionals.h"
#include <list>
#include <iostream>
using namespace std;

/************************************************************************
 * Constructor method for Professional that will receive all its		*
 * necessary attributes													*
 ************************************************************************/
Professionals::Professionals(int type, int id, int age, std::string desc,
		std::string gender, std::string name){
	this->pType = type;
	this->pID = id;
	this->pAge = age;
	this->pJobDescription = desc;
	this->pGender = gender;
	this->pName = name;
	this->pMovieCounter = 0;
}

/************************************************************************
 * Prints all the info of a Professional								*
 ************************************************************************/
string Professionals::printInfo(){}


/************************************************************************
 * This function increments the movie Counter of the Professional		*
 ************************************************************************/
void Professionals::incMovieCount(){
	pMovieCounter++;
}


/************************************************************************
 * This function decrements the movie counter of the Professional		*
 ************************************************************************/
void Professionals::decMovieCounter(){
	pMovieCounter--;
}


/************************************************************************
 * Returns the name of the Professional									*
 ************************************************************************/
string Professionals::getName(){
	return pName;
}


/************************************************************************
 * Returns the ID of a professional										*
 ************************************************************************/
int Professionals::getID() const{
	return this->pID;
}


/************************************************************************
 * Returns the age of a Professional									*
 ************************************************************************/
int Professionals::getAge() const{
	return this->pAge;
}


/************************************************************************
 * Returns the amount of movies that the professional appears in		*
 ************************************************************************/
int Professionals::getNumMovies() const{
	return this->pMovieCounter;
}


/************************************************************************
 * This returns the type of Professional it is							*
 ************************************************************************/
int Professionals::getType(){
	return this->pType;
}


/************************************************************************
 * This returns the Job Description of the Professional					*
 ************************************************************************/
string Professionals::getJobDescription(){
	return this->pJobDescription;
}


/************************************************************************
 * This is the destructor of the Professional Class						*
 ************************************************************************/
Professionals::~Professionals(){}
