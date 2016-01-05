/****************************************
 * Yossi Silberhaft & Nava Shemoul						*
 * Exercise 1							*
 * File: Movie.h							*
 ****************************************/
#ifndef MOVIE_H
#define MOVIE_H
#include <stdio.h>
#include <string>
#include<list>
#include <vector>
#include "Professionals.h"
#include "AgeCompare.h"
#include "IDCompare.h"
#include "CntrCompare.h"

class Movie{
private:
	std::string mCode;
	std::string mName;
	int mLength;
	int mYear;
	double mRating;
	std::vector<std::string> mGenre;
	std::string mSummary;
	std::vector<Professionals*> mProfessionals;


public:
	/************************************************************************
	 * This is the Movie Constructor which will receive all its				*
	 * necessary attributes													*
	 ************************************************************************/
	Movie(std::string code, std::string name, int len, int year, double rating,
			std::string sum);

	/************************************************************************
	 * This function will print the movie									*
	 ************************************************************************/
	std::string printMovie();

	std::string addPro(Professionals* proTo, int flag);


	int getProIndex(int id);

	/************************************************************************
	 * Removes a professional by using his ID								*
	 ************************************************************************/
	std::string removePro(int id, int flag);

	/************************************************************************
	 * Prints all the Professionals of the chosen movie						*
	 ************************************************************************/
	std::string printAllPros();

	/************************************************************************
	 * Returns the code of a movie											*
	 ************************************************************************/
	std::string getCode();

	/************************************************************************
	 * Sorts the Professional according to the chosen option				*
	 ************************************************************************/
	std::string sortPros(int option);

	/************************************************************************
	 * Returns the name of the current Movie								*
	 ************************************************************************/
	std::string getMovieName();


	/************************************************************************
	 * This Function adds a genre to the current Movie						*
	 ************************************************************************/
	std::string addGenre(std::string newGenre, int flag);


	bool checkGenre(std::string genre);

	/************************************************************************
	 *This function returns themovie`s date                                 *
	 ***********************************************************************/
	int getYear ();

	/************************************************************************
	 *This function returns the duration in minutes of the movie            *
	 ***********************************************************************/
	int getLength ();

	/************************************************************************
	 *This function returns the rate of the movie                           *
	 ***********************************************************************/
	double getRating ();

	/************************************************************************
	 *This function returns the summary of the movie                        *
	 ***********************************************************************/

	std::string getSummary ();

	/************************************************************************
	 *This function returns all genres of the movie                         *
	 ***********************************************************************/
	std::vector<std::string> getGenreList ();


	/***********************************************************************
	 *This function returns the vector of the Genres                      *
	 ***********************************************************************/
	std::vector<Professionals*> getProList();


	int getProListSize();
	/***********************************************************************
	 *This is the Movie destructor											*
	 ***********************************************************************/
	~Movie();

};

#endif
