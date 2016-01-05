/****************************************
 * Yossi Silberhaft & Nava Shemoul						*
 * Exercise 5							*
 * File: AgeCOmpare.cpp					*
 ****************************************/
#include "AgeCompare.h"
#include "Professionals.h"

bool AgeCompare::operator()(const Professionals* first,
		const Professionals* second){

	return (first->getAge() > second->getAge());
}
