/****************************************
 * Yossi Silberhaft & Nava Shemoul						*
 * Exercise 5							*
 * File: AgeCompare.h					*
 ****************************************/
#ifndef AGECOMPARE_H
#define AGECOMPARE_H
#include "Professionals.h"

class AgeCompare{

public:
	bool operator()(const Professionals* first, const Professionals* second);
};

#endif
