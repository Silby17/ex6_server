/****************************************
 * Yossi Silberhaft & Nava Shemoul		*
 * Exercise 6							*
 * FIle: Cinema.h						*
 ****************************************/
#ifndef CINEMA_H
#define CINEMA_H
#include <string>
#include <list>
#include "Movie.h"
#include "Inputs.h"
#include <vector>
#include "Professionals.h"
#include "TCPServer.h"


class Cinema{
private:
	/************************************************************************
	 * This is the constructor method for the Cinema class					*
	 ************************************************************************/
	Cinema(); // prevent the class instantiation
	static Cinema* instance;
	bool inUse;
	std::vector<Movie> movies;
	std::vector<Professionals*> proPtrList;
	std::vector<std::string> usrInput;
	Inputs myInputs;


public:
	/************************************************************************
 	* This function returns an instance of cinema, null if was build	    *
 	************************************************************************/
	static Cinema* getInstance();

	/************************************************************************
 	* This function returns true if new cinema was not build yet and false *
 	* if cinema was build                                                  *
 	************************************************************************/
	bool Occupy();


	/************************************************************************
	 * This function will start the running of the Program					*
	 ************************************************************************/
	std::string runCinema(std::vector<std::string> input);


	/************************************************************************
	 * This function will create a new movie by receiving all the			*
	 * necessary parameters of a movie										*
	 ************************************************************************/
	std::string addMovie(std::vector<std::string> input);


	/************************************************************************
	 * This function will add a Professional to a certain movie by his ID   *
	 * and the movie code 													*
	 ************************************************************************/
	std::string  addProToMovie(std::string code, int id);


	/************************************************************************
	 * This function adds a new Professional my receiving all the			*
	 * necessary attributes													*
	 ************************************************************************/
	std::string addPro(std::vector<std::string> input);


	/************************************************************************
	 *This function adds Genre to a certain Movie							*
	 ************************************************************************/
    std::string addGenreToMovie(std::vector<std::string>);


	/************************************************************************
	 * Sorts the Professionals												*
	 * Sort Options:														*
	 * 1) By ascending														*
	 * 2) By age from Oldest to youngest									*
	 * 3) By the number of movies he appears in from the highest			*
	 * to the lowest														*
	 ************************************************************************/
    std::string sortPros(std::string code, int sortOption);


	/************************************************************************
	 * Prints all the Professionals in the List								*
	 ************************************************************************/
    std::string printAllPros();


	/************************************************************************
	 * Prints the movies by the professional using his ID					*
	 ************************************************************************/
    std::string printMoviesByPro(int id);


	/************************************************************************
	 * Prints all movies that have a certain Genre							*
	 ************************************************************************/
	std::string printMovieByGenre(std::string genre);


	/************************************************************************
	 * Remove a movie by the movie code										*
	 ************************************************************************/
    std::string removeMovie(std::string code);


	/************************************************************************
	 * Removes a professional from a movie by the Movie code				*
	 * and the Professionals ID number										*
	 ************************************************************************/
    std::string removeProFromMovie(std::string code, int id);


	/************************************************************************
	 * Removes a Professional from the List by their ID number				*
	 ************************************************************************/
    std::string removeProfessional(int id);


	/************************************************************************
	 * Prints all the Movies in the List									*
	 ************************************************************************/
    std::string printAllMovies();


	/************************************************************************
	 * Prints the movie from the list using its code						*
	 ************************************************************************/
	std::string printMovie(std::string code);


	/************************************************************************
	 * Prints the professionals of a certain movie given by the Movie Code	*
	 ************************************************************************/
    std::string printProsOfMovie(std::string code);


	/************************************************************************
	 * Given a movie code, this function will find the index of that Movie	*
	 * in the Movie List													*
	 ************************************************************************/
	int getMovieIndex(std::string code);


	/************************************************************************
	 * Given a Professional ID, this function will find the index of that	*
	 * Professional in the professional List								*
	 ************************************************************************/
	int getProIndex(int id);


	/************************************************************************
	 * This is a destructor of a the cinema Class							*
	 ************************************************************************/
	virtual ~Cinema();

};

#endif /*CINEMA_H*/
