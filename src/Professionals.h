/****************************************
 * Yossi Silberhaft & Nava Shemoul						*
 * Exercise 1							*
 * File: Professionals.h					*
 ****************************************/
#ifndef PROFESSIONALS_H
#define PROFESSIONALS_H

#include <string>

class Professionals {
protected:
	int pType;
	int pID;
	int pAge;
	std::string pJobDescription;
	std::string pName;
	std::string pGender;
	int pMovieCounter;

public:
	/************************************************************************
	 * Constructor method for Professional that will receive all its		*
	 * necessary attributes													*
	 ************************************************************************/
	Professionals(int type, int id, int age, std::string desc,
			std::string gender, std::string name);


	/************************************************************************
	 * Prints all the info of a Professional according to their ID	*
	 ************************************************************************/
	virtual std::string printInfo();

	void incMovieCount();

	void decMovieCounter();


	/************************************************************************
	 * Returns the ID of a professional				*
	 ************************************************************************/
	virtual int getID() const;

	virtual std::string getName();

	std::string getJobDescription();
	/************************************************************************
	 * Returns the age of a Professional				*
	 ************************************************************************/
	int getAge() const;


	/************************************************************************
	 * Returns the amount of movies that the professional appears in*
	 ************************************************************************/
	int getNumMovies() const;

	int getType();

	virtual ~Professionals();


};
#endif
