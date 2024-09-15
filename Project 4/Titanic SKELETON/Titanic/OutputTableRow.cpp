//
//  OutputTableRow.cpp
//  Titanic
//
//  Created by Tori Wang on 11/13/23.
//

#include "OutputTableRow.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include "Enums.h"


namespace cs32 {

//constructor
OutputTableRow::OutputTableRow():mDescription(""),mSurvived(0), mTotal(0){}

void OutputTableRow::setDescription(std::string description){
    mDescription = description;
}

void OutputTableRow:: setSurvived ( int survived ){
    mSurvived = survived;
}

void OutputTableRow:: setTotal( int total){
    mTotal = total;
}

std::string OutputTableRow::getDescription(){
    return(mDescription);
}

int OutputTableRow::getSurvived(){
    return(mSurvived);
}
int OutputTableRow::getTotal(){
    return(mTotal);
}

double OutputTableRow::getPercentage(){
    if(mSurvived ==0){//if mSurvived is 0, this means total is also 0 so we automatically return 0
        return(0.0);
    }
    else{//if mSurvived > 0 than we can divide by the total
        //convert to double by multiplying by 1.0
        return(((1.0*mSurvived)/(1.0*mTotal)));
    }
}

void OutputTableRow::display(){
    //Here we display one row
    std::cout << getDescription() << "   " << padToThreeCharacters(getSurvived()) << "   " << "/"<< "   " << padToThreeCharacters(getTotal()) << "        "<< int(getPercentage()*100) << std::endl;
}

std::string OutputTableRow::padToThreeCharacters(int value){
    /*It is a helper function that you can use to format the percentage in the output. What it does is that adds extra empty spaces to  numbers if their length as a string is less than 3 */
    
    //initialize the new string
    std::string newvalue = "";
    if(value<10)//0-9 1 character taken
    {
        newvalue+="  ";
        newvalue += std::to_string(value);
    }
    else if(10<=value && value <100)
    {//{10-99) 2 characters taken
        newvalue+= " ";
        newvalue += std::to_string(value);
    }
    else{//3 characters taken
        newvalue +=std::to_string(value);
    }
    return(newvalue);
}


}
