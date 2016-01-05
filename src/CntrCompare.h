/****************************************
 * Yossi Silberhaft & Nava Shemoul						*
 * Exercise 5							*
 * File: CntrCompare.h				*
 ****************************************/
#ifndef CNTRCOMPARE_H
#define CNTRCOMPARE_H
#include "Professionals.h"

class CntrCompare {

public:
	bool operator()(const Professionals* first, const Professionals* second);
};

#endif
