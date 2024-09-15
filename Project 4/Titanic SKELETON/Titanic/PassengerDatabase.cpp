//
//  PassengerDatabase.cpp
//  Titanic
//
//  Created by Tori Wang on 11/16/23.
//

#include "PassengerDatabase.h"
#include "CSVFile.h"
#include <iostream>
using namespace std;


namespace cs32 {
PassengerDatabase::PassengerDatabase():isLoaded(false){}

PassengerDatabase::~PassengerDatabase(){
    clearAllPassengers();
}

int PassengerDatabase::load( std::string filePath )
{
    //load the passengers vector using CSVFile object with this passed as an argument
    CSVFile file( this );
    int recordCount = file.readFile( filePath );
    //if we loaded more than 0 records set isLoaded to true
    if(recordCount >0){
        isLoaded = true;
    }
    else{
        isLoaded = false;
    }
    return( recordCount );
}

void PassengerDatabase::clearAllPassengers(){
    //for each passenger, delete the item in the vector passengers
    for(std::vector<Passenger*>::iterator iter = passengers.begin(); iter != passengers.end(); iter++){
        delete *iter;
    }
    //erase the passengers vector
    passengers.erase(passengers.begin(), passengers.end());
}

bool PassengerDatabase::loaded(){
    if(passengers.size() >0){
        return(true);
    }
    return(false);
}

std::vector<Passenger *> PassengerDatabase::getPassengers(){
    return passengers;
}

Passenger * PassengerDatabase::getPassenger_byName(std::string name){
    //create iterator to go through pointers to passengers
    for(std::vector<Passenger*>::iterator iter = passengers.begin(); iter != passengers.end(); iter++){
        if((*iter)->getName() == name){//if we find a match to name
            //return the pointer to the passenger
            return(*iter);
        }
    }
    //else return a nullptr
    return nullptr;
}

std::vector< Passenger *> PassengerDatabase::getPassengers_byClass( Class paidClass, bool survived, double minimumFare){
    //create a vector of passengers pointers
    std::vector<Passenger*> matchingClassPassengers;
    //for each pointer in Passengers
    for(std::vector<Passenger*>::iterator iter = passengers.begin(); iter != passengers.end(); iter++){
        //if the passengers class, survived status, and fare matches
        if((*iter)->getClass() == paidClass && (*iter)->getSurvived() == survived && (*iter)->getFare() > minimumFare){
            //add the passenger pointer to our new vector
            matchingClassPassengers.push_back(*iter);
        }
    }
    //return the original vector
    return matchingClassPassengers;
}

std::vector< Passenger *> PassengerDatabase::getPassengers_byEmbarcation(Embarcation embarked, bool Survived, double minimumFare){
    //create a vector of passengers pointers
    std::vector<Passenger*> matchingEmbarcationPassengers;
    //for each pointer in Passengers
    for(std::vector<Passenger*>::iterator iter = passengers.begin(); iter != passengers.end(); iter++){
        //if the passengers embarcation, survived status, and fare matches
        if((*iter)->getEmbarcation() == embarked && (*iter)->getSurvived() == Survived && (*iter)->getFare() > minimumFare){
            matchingEmbarcationPassengers.push_back(*iter);
        }
    }
    //return the original vector
    return(matchingEmbarcationPassengers);
}


void PassengerDatabase::csvData( std::map< std::string, std::string > row ){

    // add all pasengers to std::vector<Passenger*> passengers;
    // we pass one row as the argument in map format. Since it's a map we can extract the passenger info
    Passenger* newp = new Passenger;
    newp-> setFare(row.at("fare"));
    newp-> setName(row.at("name"));
    newp-> setClass(row.at("pclass"));
    newp-> setSurvived(row.at("survived"));
    newp-> setEmbarcation(row.at("embarked"));
    
    passengers.push_back(newp);
}

}
