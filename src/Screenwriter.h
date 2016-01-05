/****************************************
* Yossi Silberhaft & Nava Shemoul						*
* Exercise 1							*
* FIle: Screenwrite.h					*
****************************************/
#ifndef SCREENWRITER_H
#define SCREENWRITER_H
#include "Professionals.h"

class Screenwriter: public Professionals{
public:

	Screenwriter(int type, int id, int age, std::string desc,
			std::string gender, std::string name);
	/************************************************************************
	 * This function will print all the information of the Screenwriter	*
	 ************************************************************************/
	std::string printInfo();

	~Screenwriter();
};


#endif
