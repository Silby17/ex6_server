/****************************************
 * Yossi Silberhaft & Nava Shemoul		*
 * Exercise 5							*
 * File: Movie.cpp						*
 ****************************************/
#include "Movie.h"
#include "Cinema.h"
#include <iomanip>
#include <algorithm>
#include <sstream>

using namespace std;

/************************************************************************
 * This is the constructor for the Movie Object Class					*
 ************************************************************************/
Movie::Movie(string code, string name, int len, int year, double rating,
		string link, string description){
	this->mCode = code;
	this->mName = name;
	this->mLength = len;
	this->mYear = year;
	this->mRating = rating;
    this->imageLink = link;
	this->mSummary = description;
}


/************************************************************************
 * This function will sort the professionals by one of the	    		*
 * three options below													*
 * 1) By ascending order of the ID numbers								*
 * 2) By age from Oldest to youngest									*
 * 3) By the number of movies they appear in from most to least			*
 ************************************************************************/
string Movie::sortPros(int option){
	bool finished = false;

	switch(option){
	case 1:
	{
		IDCompare idCompare;
		sort(this->mProfessionals.begin(),
				this->mProfessionals.end(), idCompare);
		return "Success";
	}
	case 2:
	{
		AgeCompare ageCompare;
		sort(this->mProfessionals.begin(),
				this->mProfessionals.end(), ageCompare);
		return "Success";
	}
	case 3:
	{
		CntrCompare cntrCompare;
		sort(this->mProfessionals.begin(),
				this->mProfessionals.end(), cntrCompare);
		return "Success";
	}
	}
	if(finished == false){
		return "Failure";
	}
}



/************************************************************************
 * This function receives the new Professional and adds it to the list	*
 * of Professionals in the current movie								*
 ************************************************************************/
string Movie::addPro(Professionals* proTo, int flag){
	int size = mProfessionals.size();

	proTo->incMovieCount();
	//Adds the Professional to the list
	this->mProfessionals.push_back(proTo);

	if(flag == 1){
		//Checks if the size of the list has grown
		if(mProfessionals.size() - size == 1){
			return "Success";
		}
	}
}


/************************************************************************
 * This function will add the Genre to the movie by adding the Genre	*
 * that was passed as a string to the list of genres in the movie		*
 ************************************************************************/
string Movie::addGenre(string newGenre, int flag){
	int size = mGenre.size();

	//Add the new Genre to the vector of Genres
	mGenre.push_back(newGenre);

	if(flag == 1){
		//Checks that the list has grown after insertion
		if(mGenre.size() - size == 1){
			return "Success";
		}
		else {
			return "Failure";
		}
	}
}


/************************************************************************
 * This function will print the movie my printing each of its members	*
 * and for the Genres it will iterate through the list of Genres		*
 * and print them in their correct form									*
 ************************************************************************/
 string Movie::printMovie(){
    //Converts the Rating to a string with 1 decimal precision
    stringstream stream;
    stream << fixed << setprecision(1) << mRating;
    string rating = stream.str();

    ostringstream convert;
    convert << mLength;
    string strLen = convert.str();

    ostringstream convertYear;
    convertYear << mYear;
    string strYear = convertYear.str();

	//Starts printing the first part of the movie members
	string print = mCode + " " + mName + " " + strLen + " "
			+ strYear  + " " + rating + " " + imageLink + " ";

	if(mGenre.size() == 1){
		print = print + mGenre.at(0) + " ";
	}
	else if(mGenre.size() > 1){
		print = print + mGenre.at(0);
		vector<string>::iterator it;
		for(it = mGenre.begin() + 1; it != mGenre.end(); it++){

			print = print +  "," + *it;
		}

		print = print + " ";
	}

	print = print + mSummary ;

	//Now to print the Professionals of the current movie
	vector<Professionals*>::iterator it2;
	for(it2 = mProfessionals.begin(); it2  != mProfessionals.end(); it2++){
			print = print +"\n" + (*it2)->printInfo();
	}
	return print;
}


/************************************************************************
 * This function will receive the ID of a professional and will find	*
 * the index of it in the list of Professionals and return that index	*
 ************************************************************************/
int Movie::getProIndex(int id){
	vector<Professionals*>::iterator it;
	for(it = mProfessionals.begin(); it < mProfessionals.end(); it++){
		if((*it)->getID() == id){
			return it - mProfessionals.begin();
		}
	}
	return -1;
}


/************************************************************************
 * This Function will receive a Genre string and run through the list	*
 * if Genre and if it contains the Genre it will return true, else 		*
 * it will return false													*
 ************************************************************************/
bool Movie::checkGenre(string genre){
	vector<string>::iterator i;
	for(i = mGenre.begin(); i != mGenre.end(); i++){
		if(i->c_str() == genre){
			return true;
		}
	}
	return false;
}


/************************************************************************
 * This function will get the ID of a professional and remove them from	*
 * the list of professionals of this movie								*
 ************************************************************************/
string Movie::removePro(int id, int flag){
	int index = getProIndex(id);
	int size = getProListSize();

	mProfessionals.at(index)->decMovieCounter();
	//Removes the Professional from the List of the current Movie
	mProfessionals.erase(mProfessionals.begin() + index);

	//If we are deleting the Pro only from the Current Movie
	if(flag == 1){
		if(size - getProListSize() == 1){
			return "Success";
		}
		else {
			return "Failure";
		}
	}
    return "Done";
}


/************************************************************************
 * Prints all the Professionals of the chosen movie	                	*
 ************************************************************************/
string Movie::printAllPros(){
	string print;
	if(mProfessionals.size() != 0){
		vector<Professionals*>::iterator it;
		for(it = mProfessionals.begin(); it != mProfessionals.end(); it++){
			if(it ==  mProfessionals.begin()){
				print = print + (*it)->printInfo();
			}
			else{
				print = print +"\n" + (*it)->printInfo();
			}
		}
	}
		return print;
}


/************************************************************************
 * Returns the code of a movie											*
 ************************************************************************/
string Movie::getCode(){
	return mCode;
}

/************************************************************************
* This returns the size of the list of professionals                    *
************************************************************************/
int Movie::getProListSize(){
	return mProfessionals.size();
}

/*************************************************************************
 * This is the destructor						                         *
 ************************************************************************/
Movie::~Movie(){}
