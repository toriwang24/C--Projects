//
//  PassengerOutputTable.hpp
//  Titanic
//
//  Created by Tori Wang on 11/13/23.
//

#ifndef PassengerOutputTable_h
#define PassengerOutputTable_h

#include <stdio.h>
#include "OutputTableRow.h"
#include "Passenger.h"
#include <vector>
#include "Enums.h"


namespace cs32 {
class PassengerOutputTable{
public:
    PassengerOutputTable(std::vector< Passenger *> passengers);
    void setOutputField( Field f);
    void setDescription( std::string description);
    Field getOutputField();
    std::string getDescription();
    
    void display();
    
    size_t rowCount();
    OutputTableRow getRow(int index);
    
    //My helper functions
    std::vector< int > getSurvived(Field f);
    std::vector< int > getTotal(Field f);

    
private:
    std::vector< Passenger *> mPassengerlist;
    std::vector< OutputTableRow > mRows;
    Field mField;
    std::string mDescription;
};
}




#endif /* PassengerOutputTable_h */



