//
//  Passenger.cpp
//  Titanic
//
//  Created by Tori Wang on 11/13/23.
//

#include "Passenger.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "Enums.h"

namespace cs32 {

Passenger::Passenger()
{
    //constructor
    //Here we initialize the name to empty string, fare to 0 (unknown), and survived to false. The ret of the fields are also set to not known
    mName = "";
    mEmbarked= Embarcation::NOTKNOWN;
    mClass = Class::NOTKNOWN;
    mFare = 0;
    mSurvived=false;
};

//Setters:
void Passenger::setName(std::string name){
    mName = name;
}

void Passenger::setEmbarcation(std::string embarked){
    if(embarked=="C"){
        mEmbarked = Embarcation::CHERBOURG;
    }
    else if (embarked=="Q"){
        mEmbarked = Embarcation::QUEENSTOWN;
    }
    else if (embarked=="S"){
        mEmbarked = Embarcation::SOUTHHAMPTON;
    }
    else{
        mEmbarked = Embarcation::NOTKNOWN;
    }
}


void Passenger::setClass ( std::string classofFare){
    if(classofFare=="1"){
        mClass = Class::FIRST;
    }
    else if(classofFare=="2"){
        mClass = Class::SECOND;
    }
    else if(classofFare=="3"){
        mClass = Class::THIRD;
    }
    else{
        mClass = Class::NOTKNOWN;
    }
};
void Passenger::setSurvived( std::string survived){
    if(survived == "1"){
        mSurvived = true;
    }
    else{
        mSurvived = false;
    }
}

void Passenger::setFare( std::string fare ){
    //if empty string is passed then set to 0
    //else set to integer of the string
    if(fare == ""){
        mFare = 0;
    }
    else if(fare >= "0"){
        mFare = std::stof(fare);
    }
    else{
        mFare=0;
    }
}

//Getters:
std::string Passenger::getName(){
    return (mName);
}

Embarcation Passenger::getEmbarcation(){
    return(mEmbarked);
}

Class Passenger::getClass(){
    return (mClass);
}

bool Passenger::getSurvived(){
    return (mSurvived);
}

double Passenger::getFare(){
    return(mFare);
}
}
