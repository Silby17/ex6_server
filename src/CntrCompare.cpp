/****************************************
 * Yossi Silberhaft & Nava Shemoul						*
 * Exercise 6							*
 * File: CntrCOmpare.cpp				*
 ****************************************/
#include "CntrCompare.h"
#include "Professionals.h"

bool CntrCompare::operator()(const Professionals* first,
		const Professionals* second){

	return (first->getNumMovies() < second->getNumMovies());
}
