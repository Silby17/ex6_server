/****************************************
 * Yossi Silberhaft & Nava Shemoul		*
 * Exercise 5							*
 * File: Cinema.cpp						*
 ****************************************/
#include "Inputs.h"
#include "Cinema.h"
#include "Producer.h"
#include "Director.h"
#include "Screenwriter.h"
#include "Actor.h"
#include <algorithm>
#include <iterator>
#include <sstream>
using namespace std;

Cinema* Cinema::instance = NULL;

/************************************************************************
 * This is the constructor method for the Cinema class					*
 ************************************************************************/
Cinema::Cinema()
{
    inUse = false;
}


/************************************************************************
 * This function returns an instance of cinema, null if was bulid	    *
 ************************************************************************/
Cinema* Cinema::getInstance()
{
    if (!instance)
        Cinema::instance = new Cinema;
    return instance;
}


/************************************************************************
 * This function returns true if new cinema was not build yet and false
 * if cinema was build*
 ************************************************************************/
bool Cinema::Occupy()
{
    if (!inUse)
    {
        inUse = true;
        return true;
    }
    return false;
}


/************************************************************************
 * This function is responsible for the constant running of the program	*
 * it will receive a Type and port which will be used to create			*
 * the necessary server													*
 ************************************************************************/
string Cinema::runCinema(vector<string> inputVec){
    int option = atoi(inputVec.at(0).c_str());
    int code;

    //Switch case for the users entries
    switch(option){
        //Add movie to the movie vector
        case 1:
            return addMovie(inputVec);

            //Adds a Professional to the Pro List
        case 2:
            return addPro(inputVec);
        case 3:
        {
            int proId = atoi(inputVec.at(2).c_str());
            return addProToMovie(inputVec.at(1), proId);
        }
        case 4:
            return addGenreToMovie(inputVec);

        case 5:
            return sortPros(inputVec.at(1), atoi(inputVec.at(2).c_str()));
        case 6:
            return printProsOfMovie(inputVec.at(1));

        case 7:
        {
            return printMovie(inputVec.at(1));
        }
        case 8:
        {
            //joinMovies(inputVec);
            return "Failure\n";
        }
        case 9:
            return printMoviesByPro(atoi(inputVec.at(1).c_str()));

        case 10:
            return removeMovie(inputVec.at(1));

        case 11:
        {
            code = atoi(inputVec.at(1).c_str());
            return removeProfessional(code);
        }
        case 12:{
            int proID =atoi(inputVec.at(2).c_str());
            return removeProFromMovie(inputVec.at(1), proID);
        }
        case 13:
            return printAllMovies();

        case 14:
            return printAllPros();

        case 15:
            return printMovieByGenre(inputVec.at(1));

        default:
            return NULL;
    }
}


/************************************************************************
 * This function sends a string to server and server prints it out.     *
 ************************************************************************/
void Cinema::printStringByServer(string printMe) {
    //char *y1 = new char[printMe.length() + 1];
    // strcpy(y1, printMe.c_str());

    //this->tcpServer->sendTCP(y1, BUFFER_SIZE);
}


/************************************************************************
 * 1) This function will create a new movie by receiving all the		*
 * necessary parameters of a movie										*
 ************************************************************************/
string Cinema::addMovie(vector<string> inputVector){
    //Deceleration of variables
    string code, name, description;
    int len, year, size;
    double rating;
    code = inputVector.at(1);
    size = inputVector.size();
    string ans;

    len = atoi(inputVector.at(3).c_str());

    //Checks if the movie Exists
    int atIndex = getMovieIndex(code);
    if(atIndex != -1 || len < 0){
        ans = "Failure";
    }
        //If it doesn't exist and it returns -1 then add the Movie
    else {
        //Placing the details into their variables
        name = inputVector.at(2);
        year = atoi(inputVector.at(4).c_str());
        rating = atof(inputVector.at(5).c_str());

        //Pieces together the description
        stringstream ss;
        for(int i = 6; i < size; i++){
            ss << inputVector.at(i);
            if(i < size - 1){
                ss << " ";
            }
        }
        description = ss.str();
        int vectorSize = movies.size();
        //Creates the the movie
        Movie tempMovie(code, name, len, year, rating, description);
        //Add movie to the list
        movies.push_back(tempMovie);
        //Checks that the Movie was added to the list
        if(movies.size() - vectorSize == 1){
            ans ="Success";
        }
    }
    return ans;

}


/************************************************************************
 * 2) This function adds a new Professional my receiving all the		*
 * necessary attributes													*
 ************************************************************************/
string Cinema::addPro(vector<string> inputVec){
    int id, type, age;
    string gender, name, description;
    int listSize = proPtrList.size();
    string result;

    type = atoi(inputVec.at(1).c_str());
    id = atoi(inputVec.at(2).c_str());
    age = atoi(inputVec.at(3).c_str());
    description = inputVec.at(4);
    gender = inputVec.at(5);

    //Checks that the ID number is a positive Number
    if(id < 0 || age < 0){
        result = "Failure";
    }
    else{
        int size = inputVec.size();
        stringstream ss;
        for(int i = 6; i != size; i++){
            ss << inputVec.at(i) << " ";
        }
        name = ss.str();
        int atIndex = getProIndex(id);
        if(atIndex != - 1){
            result = "Failure";
        }
        else {
            //Switch case to make each type of Professional
            switch(type){
                //Director
                case 0:
                {
                    Professionals* newDirector =
                            new Director(type, id, age, description, gender, name);
                    proPtrList.push_back(newDirector);
                    break;
                }
                    //Actor
                case 1:
                {
                    Professionals* newActor =
                            new Actor(type, id, age, description, gender, name);
                    proPtrList.push_back(newActor);
                    break;
                }
                    //Screenwriter
                case 2:
                {
                    Professionals* newScreen =
                            new Screenwriter(type, id, age,
                                             description, gender, name);
                    proPtrList.push_back(newScreen);
                    break;
                }
                    //Producer
                case 3:
                {
                    Professionals* newProducer =
                            new Producer(type, id, age, description, gender, name);
                    proPtrList.push_back(newProducer);
                    break;
                }
            }
            if(proPtrList.size() - listSize == 1){
                result= "Success";
            }
        }
    }
    return result;
}


/************************************************************************
 * 3) This function add a Professional to a certain movie by his ID   	*
 * and the movie code 													*
 ************************************************************************/
string Cinema::addProToMovie(string code, int id){
    //Gets the index of the movie and pro in their lists
    int movieIndex = getMovieIndex(code);
    int proIndex = getProIndex(id);
    string result;

    //Checks that both the movie and the professional exist
    if(movieIndex != -1 && proIndex != -1){
        //Checks that the Professional is not already in that movie
        if(movies.at(movieIndex).getProIndex(id) == -1){
            result = movies.at(movieIndex).addPro(proPtrList.at(proIndex), 1);
        }
    }
        //If the movie does not exist print error messages
    else {
        result = "Failure";
    }
    return result;
}


/************************************************************************
 * 4) This function a Genre to a certain Movie							*
 ************************************************************************/
string Cinema::addGenreToMovie(vector<string> vecInput){
    string movieCode = vecInput.at(1);
    string genre = vecInput.at(2);
    string result;

    //Checks if the movie exists
    int atIndex = getMovieIndex(movieCode);
    //If the movie does exist then add the Genre to the Movie
    if(atIndex != -1){
        result = movies.at(atIndex).addGenre(genre, 1);
    }
        //Else print an error message
    else{
        result = "Failure";
    }
    return result;
}


/************************************************************************
 * 5) This function will sort the Professionals of a given movie		*
 * it will find the index of the movie to be sorted and then			*
 * activate its sort method by passing an number which is the option	*
 * of the different sort method											*
 ************************************************************************/
string Cinema::sortPros(string code, int sortOption){
    string ans;
    //Gets the movie index
    int movieIndex = getMovieIndex(code);
    if(movieIndex != -1){
        ans = movies.at(movieIndex).sortPros(sortOption);
    }
        //If the movie doesn't exist
    else {
        ans = "Failure";
    }
    printStringByServer(ans);
}


/************************************************************************
 * 6) This function prints the list of Professionals of a certain movie	*
 * given by the movie code												*
 ************************************************************************/
string Cinema::printProsOfMovie(std::string code){
    int movieIndex = getMovieIndex(code);
    string result;
    //Checks if the movie exists in the movies List
    if(movieIndex != -1){
        result = movies.at(movieIndex).printAllPros();
    }
    else{
        result = "Failure";
    }
    return result;
}


/************************************************************************
 * 7) Prints the movie from the list using its code						*
 ************************************************************************/
string Cinema::printMovie(string code){
    int index = getMovieIndex(code);
    string ans;
    //Checks if the movie exists
    if(index != -1){
        //If it does then print
        ans = movies.at(index).printMovie();
    }
        //If it doesn't then print error message
    else{
        ans = "Failure";
    }
    return ans;
}


/************************************************************************
 * This function will find the index of a Professional by iterating		*
 * through the list and looking for a Professional with the given id	*
 * if the Professional doesn't exist it will return -1					*
 ************************************************************************/
int Cinema::getProIndex(int id){
    vector<Professionals*>::iterator it;
    for(it = proPtrList.begin(); it < proPtrList.end(); it++){
        if((*it)->getID() == id){
            return it - proPtrList.begin();
        }
    }
    return -1;
}


/************************************************************************
 * This function will find the index of a movie by iterating through	*
 * the list and looking for a movie with the given code					*
 * if the movie doesn't exist it will return -1							*
 ************************************************************************/
int Cinema::getMovieIndex(string code){
    vector<Movie>::iterator it;

    for(it = movies.begin(); it < movies.end(); it++){
        if(it->getCode() == code){
            return it - movies.begin();
        }
    }
    return -1;
}


/************************************************************************
 * 9) This function goes through the list of movies and prints the		*
 * movies that have the professionals by their ID						*
 ************************************************************************/
string Cinema::printMoviesByPro(int id){
    vector<Movie>::iterator mIT;
    bool printed = false;
    string ans;

    for(mIT = movies.begin(); mIT != movies.end(); mIT++){
        if(mIT->getProIndex(id) != -1){
            if(mIT ==  movies.begin()){
                ans = ans + mIT->printMovie();
            }
            else{
                ans = ans + "\n" +mIT->printMovie();
            }

            printed = true;
        }
    }
    if(printed == false){
        ans = "Failure";
    }
    return ans;
}


/************************************************************************
 * 10)This function will remove a movie from the list by its code		*
 ************************************************************************/
string Cinema::removeMovie(string code){
    int index = getMovieIndex(code);
    int size = movies.size();
    string ans;

    //Checks if the movie is in the Movie List
    //if it doesn't then print Failure
    if(index == -1){
        ans = "Failure";
    }
        //if it is then remove the movie
    else {
        movies.erase(movies.begin() + index);
        if(size - movies.size() == 1){
            ans = "Success";
        }
    }
    return ans;
}


/************************************************************************
 * 11)This function will remove a Professional from the list by its code*
 ************************************************************************/
string Cinema::removeProfessional(int id){
    int index = getProIndex(id);
    int size = proPtrList.size();
    string result;

    //Checks if the Pro exists in the List
    //if it doesn't then print Failure
    if(index == -1){
        result = "Failure";
    }
        //If it does then remove it
    else {
        if(proPtrList.at(index)->getNumMovies() > 0){
            //Runs through the Movies and removes the Professional from them
            vector<Movie>::iterator it;
            for(it = movies.begin(); it != movies.end(); it++){
                if(it->getProIndex(id) != -1){
                    string result = it->removePro(id, 0);
                }
            }
        }
        delete proPtrList.at(index);
        proPtrList.erase(proPtrList.begin() + index);

        if(size - proPtrList.size() == 1){
            result = "Success";
        }
    }
    return result;
}


/************************************************************************
 * 12) Removes a professional from a movie by the Movie code			*
 * and the Professionals ID number										*
 ************************************************************************/
string Cinema::removeProFromMovie(string code, int id){
    int movieIndex = getMovieIndex(code);
    string result;

    if(movieIndex != -1){
        result = this->movies.at(movieIndex).removePro(id, 1);
    }
    else {
        result = "Failure";
    }
    return result;
}


/************************************************************************
 * 13) Prints all the Movies in the List								*
 ************************************************************************/
string Cinema::printAllMovies(){
    //Define the iterator
    string ans;
    if(movies.size() != 0){
        vector<Movie>::iterator it;
        for(it = movies.begin(); it != movies.end(); it++){
            if(it == movies.begin()) {
                ans = ans + it->printMovie();
            }
            else{
                ans = ans +"\n" + it->printMovie();
            }
        }
    }
    else{
        ans = "Failure";
    }
    return ans;
}

/************************************************************************
 * 14) Prints all the Professionals of a movie given by the code		*
 ************************************************************************/
string Cinema::printAllPros(){
    string ans;
    if(proPtrList.size() != 0){
        //Define the iterator
        vector<Professionals*>::iterator it;
        for(it = proPtrList.begin(); it != proPtrList.end(); it++){
            if(it == proPtrList.begin()){
                ans = ans + (*it)->printInfo();
            }
            else{
                ans = ans +  "\n" + (*it)->printInfo();
            }

        }
    }
    else {
        ans = "Failure";
    }
    return ans;
}


/************************************************************************
 * 15) This function will go through the list of movies and check their	*
 * given genres and will print the movie if it has that Genre			*
 ************************************************************************/
string Cinema::printMovieByGenre(string genre){
    bool foundAny = false;
    vector<Movie>::iterator it;
    string ans;

    for(it = movies.begin(); it != movies.end(); it++){
        if(it->checkGenre(genre) == true){
            foundAny = true;
            if(it == movies.begin()){
                ans = ans + it->printMovie();
            }
            else{
                ans = ans +"\n" + it->printMovie();
            }
        }
    }
    if(foundAny == false){
        ans = "Failure";
    }
    return ans;
}


/************************************************************************
 * Returns the List of movies											*
 ************************************************************************/
vector<Movie> Cinema::getMovieList(){
    return movies;
}


/************************************************************************
 * Returns the list of Professionals									*
 ************************************************************************/
vector<Professionals*> Cinema::getProList(){
    return proPtrList;
}


/************************************************************************
 * This is a destructor of a Cinema                                     *
 ************************************************************************/
Cinema::~Cinema(){}