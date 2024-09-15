//
//  PassengerOutputTable.cpp
//  Titanic
//
//  Created by Tori Wang on 11/13/23.
//

#include "PassengerOutputTable.h"
#include <stdio.h>
#include "OutputTableRow.h"
#include "Passenger.h"
#include <vector>
#include "Enums.h"

using namespace std;

//constructor
namespace cs32{
PassengerOutputTable::PassengerOutputTable(std::vector< Passenger *> passengers):   mPassengerlist(passengers), mField(Field::NOVALUE){
}

/*My helper functions!!*/
//helper function to calculate the number of survivors in vector of passengers given a field
std::vector< int > PassengerOutputTable::getSurvived(Field f){
    //initialize a vector of size 5
    //we use 5 here because this is the highest number of categories that a field can have
    //we are counting the total number of passengers in each category of a field using this vector
    std::vector< int > counts(5);
    
    switch (f) {
        case Field::BYEMBARCATION:
        {//Create a vector iterator to go throuh passengers
            for(std::vector< Passenger *>::iterator iter = mPassengerlist.begin(); iter != mPassengerlist.end(); iter ++){
                //if the passenger survived than we count them
                if((*iter) -> getSurvived() ==true){
                    //Sort them into the corresponding place in vector depending on embarcation
                    if((*iter)->getEmbarcation() == Embarcation::CHERBOURG){
                        counts.at(0)++;
                    }
                    if((*iter)->getEmbarcation() == Embarcation::QUEENSTOWN){
                        counts.at(1)++;
                    }
                    if((*iter)->getEmbarcation() == Embarcation::SOUTHHAMPTON){
                        counts.at(2)++;
                    }
                    if((*iter)->getEmbarcation() == Embarcation::NOTKNOWN){
                        counts.at(3)++;
                    }
                }
            }
            break;
        }
        case Field::BYCLASS:
        {//Create a vector iterator to go throuh passengers
            for(std::vector< Passenger *>::iterator iter = mPassengerlist.begin(); iter != mPassengerlist.end(); iter ++){
                if((*iter) -> getSurvived() ==true){
                    //Sort them into the corresponding place in vector depending on class
                    if((*iter)->getClass() == Class::FIRST){
                        counts.at(0)++;
                    }
                    if((*iter)->getClass() == Class::SECOND){
                        counts.at(1)++;
                    }
                    if((*iter)->getClass() == Class::THIRD){
                        counts.at(2)++;
                    }
                    if((*iter)->getClass() == Class::NOTKNOWN){
                        counts.at(3)++;
                    }
                }
            }
            break;
        }
        case Field::BYFARE:
        {//Create a vector iterator to go throuh passengers
            for(std::vector< Passenger *>::iterator iter = mPassengerlist.begin(); iter != mPassengerlist.end(); iter ++){
                if((*iter) -> getSurvived() ==true){
                    //Sort them into the corresponding place in vector depending on Fare
                    if((*iter)->getFare() ==0)
                    {//a value of 0 means it is unknown
                        counts.at(0)++;
                    }
                    if((*iter)->getFare() >0 && (*iter)->getFare() <= 10){
                        counts.at(1)++;
                    }
                    if((*iter)->getFare() > 10 && (*iter)->getFare() <= 25){
                        counts.at(2)++;
                    }
                    if((*iter)->getFare() > 25 && (*iter)->getFare() <= 50){
                        counts.at(3)++;
                    }
                    if((*iter)->getFare() > 50){
                        counts.at(4)++;
                    }
                }
            }
            break;
        }
        case Field::NOVALUE:
        {//if the field has no value we don't do anything
            break;
        }
    }
    
    return(counts);
}


//Helper function to calculate the total amount of passengers in each category of a field
std::vector< int > PassengerOutputTable::getTotal(Field f){
    // This function is basically the same as above, however we take away the criteria for the passenger to have survived so we count all passengers
    std::vector< int > counts(5);
    switch (f) {
        case Field::BYEMBARCATION:
        {
            for(std::vector< Passenger *>::iterator iter = mPassengerlist.begin(); iter != mPassengerlist.end(); iter ++){
                if((*iter)->getEmbarcation() == Embarcation::CHERBOURG){
                    counts.at(0)++;
                }
                if((*iter)->getEmbarcation() == Embarcation::QUEENSTOWN){
                    counts.at(1)++;
                }
                if((*iter)->getEmbarcation() == Embarcation::SOUTHHAMPTON){
                    counts.at(2)++;
                }
                if((*iter)->getEmbarcation() == Embarcation::NOTKNOWN){
                    counts.at(3)++;
                }
            }
            break;
        }
        case Field::BYCLASS:
        {
            for(std::vector< Passenger *>::iterator iter = mPassengerlist.begin(); iter != mPassengerlist.end(); iter ++){
                if((*iter)->getClass() == Class::FIRST){
                    counts.at(0)++;
                }
                if((*iter)->getClass() == Class::SECOND){
                    counts.at(1)++;
                }
                if((*iter)->getClass() == Class::THIRD){
                    counts.at(2)++;
                }
                if((*iter)->getClass() == Class::NOTKNOWN){
                    counts.at(3)++;
                }
            }
            break;
        }
        case Field::BYFARE:
        {
            for(std::vector< Passenger *>::iterator iter = mPassengerlist.begin(); iter != mPassengerlist.end(); iter ++){
                if((*iter)->getFare() ==0)//What determines an "unknown value", is it 0?
                {
                    counts.at(0)++;
                }
                if((*iter)->getFare() >= 1 && (*iter)->getFare() < 10){
                    counts.at(1)++;
                }
                if((*iter)->getFare() >= 10 && (*iter)->getFare() < 25){
                    counts.at(2)++;
                }
                if((*iter)->getFare() >= 25 && (*iter)->getFare() <= 50){
                    counts.at(3)++;
                }
                if((*iter)->getFare() > 50){
                    counts.at(4)++;
                }
            }
            break;
        }
        case Field::NOVALUE:
        {
            break;
        }
    }
    return(counts);
}


void PassengerOutputTable::setOutputField( Field f){
    mField = f;
}

void PassengerOutputTable::setDescription( std::string description){
    mDescription = description;
}

Field PassengerOutputTable::getOutputField(){
    return(mField);
}


std::string PassengerOutputTable::getDescription(){
    return(mDescription);
}


void PassengerOutputTable::display(){
    //clear mRows
    mRows.clear();
    //print the output table rows
    switch(mField)//Depending of the field we set
    {
        case(Field::BYCLASS):
        {

            //create 4 outputtablerow objects in mRows
            OutputTableRow class1;
            OutputTableRow class2;
            OutputTableRow class3;
            OutputTableRow classUnknown;
            class1.setDescription("First Class -      ");
            class2.setDescription("Second Class-      ");
            class3.setDescription("Third Class -      ");
            classUnknown.setDescription("Not Known   -      ");
            
            mRows.push_back(class1);
            mRows.push_back(class2);
            mRows.push_back(class3);
            mRows.push_back(classUnknown);
            
            std::vector< int > classSurviveVector = this->getSurvived(Field::BYCLASS);
            std::vector< int > classTotalVector = this-> getTotal(Field::BYCLASS);
            
            //print the description:
            cout << this->getDescription() << endl;
            //print Survived/Total
            cout << "                    Survived/Total         %"<< endl;
            
            //mRows, and the three vectors above all use [] protocal.
            for(int i =0; i<4; i++){//we use 4 of the spots
                //for each of the classes, set the appropriate survived and total values
                mRows[i].setSurvived(classSurviveVector[i]);
                mRows[i].setTotal(classTotalVector[i]);
                mRows[i].display();
            }
            break;
        }
            
        case(Field::BYEMBARCATION):
        {
            
            //print the description:
            cout << this->getDescription() << endl;
            //print Survived/Total
            cout <<"                    Survived/Total         %"<< endl;
            
            //create output table row objects
            OutputTableRow Cherbourg;
            OutputTableRow Queenstown;
            OutputTableRow Southhampton;
            OutputTableRow classUnknown;
            
            //set the descriptions
            Cherbourg.setDescription("Cherbourg-         ");
            Queenstown.setDescription("Queenstown-        ");
            Southhampton.setDescription("Southhampton-      ");
            classUnknown.setDescription("Not Known-         ");
            
            //add them to mRows vector
            mRows.push_back(Cherbourg);
            mRows.push_back(Queenstown);
            mRows.push_back(Southhampton);
            mRows.push_back(classUnknown);
            
            //create vectors that contain the survived and total numbers for this field
            std::vector< int > classSurviveVector = this->getSurvived(Field::BYEMBARCATION);
            std::vector< int > classTotalVector = this-> getTotal(Field::BYEMBARCATION);

            //for each embarcation category, add it to the corresponding OutputTableRow object in mRows and call display on it
            for(int i =0; i<4; i++){//we use 4 of the spots
                //for each of the embarcation categories, set the appropriate survived and total values
                mRows[i].setSurvived(classSurviveVector[i]);
                mRows[i].setTotal(classTotalVector[i]);
                mRows[i].display();
            }
            break;
        }
            
        case(Field::BYFARE):
        {
            //print the description:
            cout << this->getDescription() << endl;
            //print Survived/Total
            cout << "                 Survived/Total         %"<< endl;
             
            //create 5 output table row 
            OutputTableRow classUnknown;
            OutputTableRow class2;
            OutputTableRow class3;
            OutputTableRow class4;
            OutputTableRow class5;
            
            classUnknown.setDescription("Not Known-      ");
            class2.setDescription("$ 1-$10-        ");
            class3.setDescription("$10-$25-        ");
            class4.setDescription("$10-$25-        ");
            class5.setDescription("   >$50-        ");
            
            mRows.push_back(classUnknown);
            mRows.push_back(class2);
            mRows.push_back(class3);
            mRows.push_back(class4);
            mRows.push_back(class5);
            
            std::vector< int > classSurviveVector = this->getSurvived(Field::BYFARE);
            std::vector< int > classTotalVector = this-> getTotal(Field::BYFARE);

            for(int i =0; i<5; i++){//we use 4 of the spots
                //for each of the fare categories, set the appropriate survived and total values
                mRows[i].setSurvived(classSurviveVector[i]);
                mRows[i].setTotal(classTotalVector[i]);
                mRows[i].display();
            }
            break;
        }
        case(Field::NOVALUE):
        {
            //do nothing
            break;
        }
    }
}

size_t PassengerOutputTable::rowCount(){
    return(mRows.size());
}


 OutputTableRow PassengerOutputTable::getRow(int index){
     return mRows.at(index);
     //.at performs size check so will not go beyond the size of the vector
     
 }

}
