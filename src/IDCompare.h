/****************************************
 * Yossi Silberhaft & Nava Shemoul						*
 * Exercise 6							*
 * File: IDCompare.h					*
 ****************************************/
#ifndef IDCOMPARE_H
#define IDCOMPARE_H
#include "Professionals.h"

class IDCompare {

public:
	bool operator()(const Professionals* first, const Professionals* second);
};

#endif
