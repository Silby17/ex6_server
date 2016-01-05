/****************************************
* Yossi Silberhaft & Nava Shemoul						*
* Exercise 5							*
* FIle: Director.h						*
****************************************/
#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "Professionals.h"

class Director: public Professionals{
public:


	/************************************************************************
	 * This is the Director Constructor										*
	 ************************************************************************/
	Director(int type, int id, int age, std::string desc,
			std::string gender, std::string name);


	/************************************************************************
	 * This function will print all the information of the Director			*
	 ************************************************************************/
	std::string printInfo();


	/************************************************************************
	 * This is the Director Destructor									*
	 ************************************************************************/
	~Director();
};
#endif
