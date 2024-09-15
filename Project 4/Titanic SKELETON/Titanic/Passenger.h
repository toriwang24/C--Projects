//
//  Passenger.hpp
//  Titanic
//
//  Created by Tori Wang on 11/13/23.
//

#ifndef Passenger_h
#define Passenger_h

#include <stdio.h>
#include <iostream>
#include <string>
#include "Enums.h"

namespace cs32 {

class Passenger
{
public:
    Passenger();
    void setName(std::string name);
    void setEmbarcation(std::string embarked);
    void setClass ( std::string classofFare);
    void setSurvived( std::string survived);
    void setFare( std::string fare );
    
    std::string getName();
    Embarcation getEmbarcation();
    Class getClass();
    bool getSurvived();
    double getFare();
    
    
private:
    //member variables
    //attributes of a passenger
    Class mClass;
    Embarcation mEmbarked;
    std::string mName;
    bool mSurvived;
    double mFare;

};

}
#endif /* Passenger_h */
