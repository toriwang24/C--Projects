#include <iostream>
#include <string>
#include <cassert>
#include "Enums.h"
#include "Passenger.h"
#include "PassengerDatabase.h"
#include "PassengerOutputTable.h"
#include "CSVFile.h"
#include "DataCollectorCallback.h"
#include "OutputTableRow.h"
#include "Settings.h"
using namespace std;
using namespace cs32;

bool startsWith( std::string s, std::string value )
{
    bool result = false;
    if (s.size() >= value.size())
    {
        // null value will always return true
        result = true;
        for( size_t i = 0; i < value.size(); i++ )
        {
            if (s.at(i) != value.at(i))
            {
                result = false;
                break;
            }
        }
    }
    return( result );
}

void testone(int n)
{
    vector< Passenger * > v;
    string s;
    Passenger p;
    Passenger p1;
    Passenger p2;
    Passenger p3;
    Passenger p4;
    Passenger p5;
    Passenger p6;
    Passenger p7;
    Passenger p8;
    Passenger p9;
    PassengerDatabase db;

    p.setName( "Jack Dawson" );
    p.setEmbarcation( "S" );
    p.setClass( "3" );
    p.setSurvived( "0" );
    p.setFare( "12.50" );
    
    p1.setName( "Rose Dewitt Bukater" );
    p1.setEmbarcation( "S" );
    p1.setClass( "1" );
    p1.setSurvived( "1" );
    p1.setFare( "52.50" );
    
    p2.setName( "Cal Hockley" );
    p2.setEmbarcation( "S" );
    p2.setClass( "1" );
    p2.setSurvived( "1" );
    p2.setFare( "52.50" );
    
    p3.setName( "Ruth Dewitt Bukater" );
    p3.setEmbarcation( "S" );
    p3.setClass( "1" );
    p3.setSurvived( "1" );
    p3.setFare( "52.50" );
    
    p4.setName( "Molly Brown" );
    p4.setEmbarcation( "C" );
    p4.setClass( "1" );
    p4.setSurvived( "1" );
    p4.setFare( "72.50" );
    
    p5.setName( "Spicer Lovejoy" );
    p5.setEmbarcation( "C" );
    p5.setClass( "1" );
    p5.setSurvived( "0" );
    p5.setFare( "52.50" );
    
    p6.setName( "Bruce Ismay" );
    p6.setEmbarcation( "Q" );
    p6.setClass( "1" );
    p6.setSurvived( "1" );
    p6.setFare( "44.50" );
    
    p7.setName( "Thomas Andrews" );
    p7.setEmbarcation( "Q" );
    p7.setClass( "2" );
    p7.setSurvived( "0" );
    p7.setFare( "44.50" );
    
    p8.setName( "Tommy Ryan" );
    p8.setEmbarcation( "Q" );
    p8.setClass( "3" );
    p8.setSurvived( "0" );
    p8.setFare( "4.50" );
    
    p9.setName( "Fabrizio" );
    p9.setEmbarcation( "Q" );
    p9.setClass( "3" );
    p9.setSurvived( "0" );
    p9.setFare( "4.50" );
    
    PassengerOutputTable table( v );
    
    OutputTableRow row;
    
    switch (n)
    {
        case  1:
                p.setName( "Jack Dawson" );
                p.setEmbarcation( "S" );
                p.setClass( "3" );
                p.setSurvived( "0" );
                p.setFare( "12.50" );
                assert( p.getName() == "Jack Dawson" );
                assert( p.getClass() == Class::THIRD );
                assert( p.getEmbarcation() == Embarcation::SOUTHHAMPTON );
                assert( std::to_string(p.getFare()) == "12.500000" );
                assert( p.getSurvived() == false );
                break;
                       
        case  2:
                row.setDescription( "testing" );
                row.setSurvived( 10 );
                row.setTotal( 10 );
                    
                assert( row.getDescription() == "testing" );
                assert( row.getSurvived() == 10 );
                assert( row.getTotal() == 10 );
                assert( std::to_string(row.getPercentage()) == "1.000000" );
                break;
            
        case  3:
                assert( db.loaded() == false );
                v = db.getPassengers();
                assert( v.size() == 0 );
                    
                v = db.getPassengers_byClass( Class::FIRST, true, -10 );
                assert( v.size() == 0 );
                v = db.getPassengers_byClass( Class::FIRST, false, -10 );
                assert( v.size() == 0 );
                v = db.getPassengers_byEmbarcation( Embarcation::CHERBOURG, false, -10 );
                assert( v.size() == 0 );
                v = db.getPassengers_byEmbarcation( Embarcation::CHERBOURG, true, -10 );
                assert( v.size() == 0 );
                    
                v = db.getPassengers_byEmbarcation( Embarcation::QUEENSTOWN, true, -10 );
                assert( v.size() == 0 );
                    
                v = db.getPassengers_byEmbarcation( Embarcation::QUEENSTOWN, false, -10 );
                assert( v.size() == 0 );
                    
                v = db.getPassengers_byEmbarcation( Embarcation::SOUTHHAMPTON, true, -10 );
                assert( v.size() == 0 );
                    
                v = db.getPassengers_byEmbarcation( Embarcation::SOUTHHAMPTON, false, -10 );
                assert( v.size() == 0 );
                break;
             
         
        case  4:
                table.setDescription( "testing" );
                table.setOutputField( Field::BYCLASS );
                  
                assert( table.getDescription() == "testing" );
                assert( table.getOutputField() == Field::BYCLASS );
                break;
            
        case  5:
                v.push_back( &p );
                v.push_back( &p1 );
                v.push_back( &p2 );
                table = PassengerOutputTable( v );
                table.setDescription( "testing" );
                table.setOutputField( Field::BYCLASS );
                
                assert( table.getDescription() == "testing" );
                assert( table.getOutputField() ==Field::BYCLASS );
                
                table.display();
                assert( table.rowCount() == 4 );
                // first class
                row = table.getRow( 0 );
                assert( row.getSurvived() == 2 );
                assert( row.getTotal() == 2 );
                assert( std::to_string(row.getPercentage()) == "1.000000" );
                // second class
                row = table.getRow( 1 );
                assert( row.getSurvived() == 0 );
                assert( row.getTotal() == 0 );
                assert( std::to_string(row.getPercentage()) == "0.000000" );
                // third class
                row = table.getRow( 2 );
                assert( row.getSurvived() == 0 );
                assert( row.getTotal() == 1 );
                assert( std::to_string(row.getPercentage()) == "0.000000" );
                // unknown
                row = table.getRow( 3 );
                assert( row.getSurvived() == 0 );
                assert( row.getTotal() == 0 );
                assert( std::to_string(row.getPercentage()) == "0.000000" );
                break;
            
        case  6:
                v.push_back( &p );
                v.push_back( &p1 );
                v.push_back( &p2 );
                v.push_back( &p3 );
                v.push_back( &p4 );
                v.push_back( &p5 );
                v.push_back( &p6 );
                v.push_back( &p7 );
                v.push_back( &p8 );
                v.push_back( &p9 );
                table = PassengerOutputTable( v );
                table.setDescription( "testing" );
                table.setOutputField( Field::BYCLASS );
                
                assert( table.getDescription() == "testing" );
                assert( table.getOutputField() == Field::BYCLASS );
                
                table.display();
                assert( table.rowCount() == 4 );
                // first class
                row = table.getRow( 0 );
                assert( row.getSurvived() == 5 );
                assert( row.getTotal() == 6 );
                assert( std::to_string(row.getPercentage()) == "0.833333" );
                // second class
                row = table.getRow( 1 );
                assert( row.getSurvived() == 0 );
                assert( row.getTotal() == 1 );
                assert( std::to_string(row.getPercentage()) == "0.000000" );
                // third class
                row = table.getRow( 2 );
                assert( row.getSurvived() == 0 );
                assert( row.getTotal() == 3 );
                assert( std::to_string(row.getPercentage()) == "0.000000" );
                // unknown
                row = table.getRow( 3 );
                assert( row.getSurvived() == 0 );
                assert( row.getTotal() == 0 );
                assert( std::to_string(row.getPercentage()) == "0.000000" );
                break;
                         
        case  7:
                v.push_back( &p );
                v.push_back( &p1 );
                v.push_back( &p2 );
                v.push_back( &p3 );
                v.push_back( &p4 );
                v.push_back( &p5 );
                v.push_back( &p6 );
                v.push_back( &p7 );
                v.push_back( &p8 );
                v.push_back( &p9 );
                table = PassengerOutputTable( v );
                table.setDescription( "testing" );
                table.setOutputField( Field::BYEMBARCATION );
                
                assert( table.getDescription() == "testing" );
                assert( table.getOutputField() == Field::BYEMBARCATION );
                
                table.display();
                assert( table.rowCount() == 4 );
                // first class
                row = table.getRow( 0 );
                assert( row.getSurvived() == 1 );
                assert( row.getTotal() == 2 );
                assert( std::to_string(row.getPercentage()) == "0.500000" );
                // second class
                row = table.getRow( 1 );
                assert( row.getSurvived() == 1 );
                assert( row.getTotal() == 4 );
                assert( std::to_string(row.getPercentage()) == "0.250000" );
                // third class
                row = table.getRow( 2 );
                assert( row.getSurvived() == 3 );
                assert( row.getTotal() == 4 );
                assert( std::to_string(row.getPercentage()) == "0.750000" );
                // unknown
                row = table.getRow( 3 );
                assert( row.getSurvived() == 0 );
                assert( row.getTotal() == 0 );
                assert( std::to_string(row.getPercentage()) == "0.000000" );
                break;
        
        case  8:
                v.push_back( &p );
                v.push_back( &p1 );
                v.push_back( &p2 );
                v.push_back( &p3 );
                v.push_back( &p4 );
                v.push_back( &p5 );
                v.push_back( &p6 );
                v.push_back( &p7 );
                v.push_back( &p8 );
                v.push_back( &p9 );
                table = PassengerOutputTable( v );
                table.setDescription( "testing" );
                table.setOutputField( Field::BYFARE );
                
                assert( table.getDescription() == "testing" );
                assert( table.getOutputField() == Field::BYFARE );
                
                table.display();
                assert( table.rowCount() == 5 );
                // support not known at either the beginning or the end
                row = table.getRow( 0 );
                if (startsWith( row.getDescription(), "Not Known" ))
                {
                   // Not Known at the beginning

                   assert( row.getSurvived() == 0 );
                   assert( row.getTotal() == 0 );
                   assert( std::to_string(row.getPercentage()) == "0.000000" );
                   // 1-10
                   row = table.getRow( 1 );
                   assert( row.getSurvived() == 0 );
                   assert( row.getTotal() == 2 );
                   assert( std::to_string(row.getPercentage()) == "0.000000" );
                   // 10-25
                   row = table.getRow( 2 );
                   assert( row.getSurvived() == 0 );
                   assert( row.getTotal() == 1 );
                   assert( std::to_string(row.getPercentage()) == "0.000000" );
                   // 25-50
                   row = table.getRow( 3 );
                   assert( row.getSurvived() == 1 );
                   assert( row.getTotal() == 2 );
                   assert( std::to_string(row.getPercentage()) == "0.500000" );
                   // > 50
                   row = table.getRow( 4 );
                   assert( row.getSurvived() == 4 );
                   assert( row.getTotal() == 5 );
                   assert( std::to_string(row.getPercentage()) == "0.800000" );
                }
                else
                {
                   // Not Known at the end

                   // 1-10
                   assert( row.getSurvived() == 0 );
                   assert( row.getTotal() == 2 );
                   assert( std::to_string(row.getPercentage()) == "0.000000" );
                   // 10-25
                   row = table.getRow( 1 );
                   assert( row.getSurvived() == 0 );
                   assert( row.getTotal() == 1 );
                   assert( std::to_string(row.getPercentage()) == "0.000000" );
                   // 25-50
                   row = table.getRow( 2 );
                   assert( row.getSurvived() == 1 );
                   assert( row.getTotal() == 2 );
                   assert( std::to_string(row.getPercentage()) == "0.500000" );
                   // > 50
                   row = table.getRow( 3 );
                   assert( row.getSurvived() == 4 );
                   assert( row.getTotal() == 5 );
                   assert( std::to_string(row.getPercentage()) == "0.800000" );
                   // Not Known
                   row = table.getRow( 4 );
                   assert( row.getSurvived() == 0 );
                   assert( row.getTotal() == 0 );
                   assert( std::to_string(row.getPercentage()) == "0.000000" );
                }
                break;
                         
        case  9:
                db.load( "/Users/howardstahl/Documents/My_Courses/UCLA/Fall,_2023/homeworks/project4/datafiles/sample.csv");
                assert( db.loaded() );
                
                v = db.getPassengers();
                assert( v.size() == 11 );
                
                v = db.getPassengers_byClass( Class::FIRST, true, -10 );
                assert( v.size() == 5 );
                
                v = db.getPassengers_byClass( Class::FIRST, false, -10 );
                assert( v.size() == 4 );
                
                v = db.getPassengers_byClass( Class::SECOND, true, -10 );
                assert( v.size() == 1 );
                
                v = db.getPassengers_byClass( Class::SECOND, false, -10 );
                assert( v.size() == 0 );
                
                v = db.getPassengers_byClass( Class::THIRD, true, -10 );
                assert( v.size() == 1 );
                
                v = db.getPassengers_byClass( Class::THIRD, false, -10 );
                assert( v.size() == 0 );
                
                v = db.getPassengers_byClass( Class::NOTKNOWN, true, -10 );
                assert( v.size() == 0 );
                
                v = db.getPassengers_byClass( Class::NOTKNOWN, false, -10 );
                assert( v.size() == 0 );
                break;
                        
        case  10:
                db.load( "/Users/howardstahl/Documents/My_Courses/UCLA/Fall,_2023/homeworks/project4/datafiles/titanic.csv");
                assert( db.loaded() );
                
                v = db.getPassengers();
                assert( v.size() == 1309 );
                
                v = db.getPassengers_byClass( Class::FIRST, true, -10 );
                assert( v.size() == 200 );
                
                v = db.getPassengers_byClass( Class::FIRST, false, -10 );
                assert( v.size() == 123 );
                
                v = db.getPassengers_byClass( Class::SECOND, true, -10 );
                assert( v.size() == 119 );
                
                v = db.getPassengers_byClass( Class::SECOND, false, -10 );
                assert( v.size() == 158 );
                
                v = db.getPassengers_byClass( Class::THIRD, true, -10 );
                assert( v.size() == 181 );
                
                v = db.getPassengers_byClass( Class::THIRD, false, -10 );
                assert( v.size() == 528 );
                
                v = db.getPassengers_byClass( Class::NOTKNOWN, true, -10 );
                assert( v.size() == 0 );
                
                v = db.getPassengers_byClass( Class::NOTKNOWN, false, -10 );
                assert( v.size() == 0 );
                break;

         case 11:
                db.load( "/Users/howardstahl/Documents/My_Courses/UCLA/Fall,_2023/homeworks/project4/datafiles/titanic.csv");
                assert( db.loaded() );
                
                v = db.getPassengers();
                assert( v.size() == 1309 );
                
                v = db.getPassengers_byEmbarcation( Embarcation::CHERBOURG, true, -10 );
                assert( v.size() == 150 );
                
                v = db.getPassengers_byEmbarcation( Embarcation::CHERBOURG, false, -10 );
                assert( v.size() == 120 );
                
                v = db.getPassengers_byEmbarcation( Embarcation::QUEENSTOWN, true, -10 );
                assert( v.size() == 44 );
                
                v = db.getPassengers_byEmbarcation( Embarcation::QUEENSTOWN, false, -10 );
                assert( v.size() == 79 );
                
                v = db.getPassengers_byEmbarcation( Embarcation::SOUTHHAMPTON, true, -10 );
                assert( v.size() == 304 );
                
                v = db.getPassengers_byEmbarcation( Embarcation::SOUTHHAMPTON, false, -10 );
                assert( v.size() == 610 );
                
                v = db.getPassengers_byEmbarcation( Embarcation::NOTKNOWN, true, -10 );
                assert( v.size() == 2 );
                
                v = db.getPassengers_byEmbarcation( Embarcation::NOTKNOWN, false, -10 );
                assert( v.size() == 0 );
                break;
                      
         case 12:
                db.load( "/Users/howardstahl/Documents/My_Courses/UCLA/Fall,_2023/homeworks/project4/datafiles/sample.csv");
                assert( db.loaded() );
                
                v = db.getPassengers();
                assert( v.size() == 11 );
                
                v = db.getPassengers_byEmbarcation( Embarcation::CHERBOURG, true, -10 );
                assert( v.size() == 1 );
                
                v = db.getPassengers_byEmbarcation( Embarcation::CHERBOURG, false, -10 );
                assert( v.size() == 0 );
                
                v = db.getPassengers_byEmbarcation( Embarcation::QUEENSTOWN, true, -10 );
                assert( v.size() == 1 );
                
                v = db.getPassengers_byEmbarcation( Embarcation::QUEENSTOWN, false, -10 );
                assert( v.size() == 0 );
                
                v = db.getPassengers_byEmbarcation( Embarcation::SOUTHHAMPTON, true, -10 );
                assert( v.size() == 5 );
                
                v = db.getPassengers_byEmbarcation( Embarcation::SOUTHHAMPTON, false, -10 );
                assert( v.size() == 4 );
                
                v = db.getPassengers_byEmbarcation( Embarcation::NOTKNOWN, true, -10 );
                assert( v.size() == 0 );
                
                v = db.getPassengers_byEmbarcation( Embarcation::NOTKNOWN, false, -10 );
                assert( v.size() == 0 );
                break;
                       
         case 13:
                db.load( "/Users/howardstahl/Documents/My_Courses/UCLA/Fall,_2023/homeworks/project4/datafiles/titanic.csv");
                assert( db.loaded() );
                        
                v = db.getPassengers();
                        
                table = PassengerOutputTable( v );
                table.setDescription( "testing" );
                table.setOutputField( Field::BYCLASS );
                        
                assert( table.getDescription() == "testing" );
                assert( table.getOutputField() == Field::BYCLASS );
                        
                table.display();
                assert( table.rowCount() == 4 );
                // first class
                row = table.getRow( 0 );
                assert( row.getSurvived() == 200 );
                assert( row.getTotal() == 323 );
                assert( startsWith( std::to_string( row.getPercentage() ), "0.61" ) );

                // second class
                row = table.getRow( 1 );
                assert( row.getSurvived() == 119 );
                assert( row.getTotal() == 277 );
                assert( startsWith( std::to_string( row.getPercentage() ), "0.42" ) );
    
                // third class
                row = table.getRow( 2 );
                assert( row.getSurvived() == 181 );
                assert( row.getTotal() == 709 );
                assert( startsWith( std::to_string( row.getPercentage() ), "0.25" ) );
             
                // unknown
                row = table.getRow( 3 );
                assert( row.getSurvived() == 0 );
                assert( row.getTotal() == 0 );
                break;
            
         case 14:
                db.load( "/Users/howardstahl/Documents/My_Courses/UCLA/Fall,_2023/homeworks/project4/datafiles/titanic.csv");
                assert( db.loaded() );
                
                v = db.getPassengers();
                
                table = PassengerOutputTable( v );
                table.setDescription( "testing" );
                table.setOutputField( Field::BYEMBARCATION );
                
                assert( table.getDescription() == "testing" );
                assert( table.getOutputField() == Field::BYEMBARCATION );
                
                table.display();
                assert( table.rowCount() == 4 );
                // Cherbourg
                row = table.getRow( 0 );
                assert( row.getSurvived() == 150 );
                assert( row.getTotal() == 270 );
                assert( startsWith( std::to_string( row.getPercentage() ), "0.55" ) );
                // Queenstown
                row = table.getRow( 1 );
                assert( row.getSurvived() == 44 );
                assert( row.getTotal() == 123 );
                assert( startsWith( std::to_string( row.getPercentage() ), "0.35" ) );
                // Southhampton
                row = table.getRow( 2 );
                assert( row.getSurvived() == 304 );
                assert( row.getTotal() == 914 );
                assert( startsWith( std::to_string( row.getPercentage() ), "0.33" ) );
                // unknown
                row = table.getRow( 3 );
                assert( row.getSurvived() == 2 );
                assert( row.getTotal() == 2 );
                assert( startsWith( std::to_string( row.getPercentage() ), "1" ) );
                break;
            
            
         case 15:
                db.load(PATH_TO_BIGGER_DATA_MAC);
                assert( db.loaded() );
                
                v = db.getPassengers();

                table = PassengerOutputTable( v );
                table.setDescription( "testing" );
                table.setOutputField( Field::BYFARE );
                
                assert( table.getDescription() == "testing" );
                assert( table.getOutputField() == Field::BYFARE );
                
                table.display();
                assert( table.rowCount() == 5 );
                // support Not Known at the beginning or at the end

                row = table.getRow( 0 );
                if (startsWith( row.getDescription(), "Not Known"))
                {
                   // not known
                   assert( row.getSurvived() == 2 );
                   assert( row.getTotal() == 18 );
                   assert( startsWith( std::to_string( row.getPercentage() ), "0.11" ) );
                   // 1-10
                   row = table.getRow( 1 );
                   assert( row.getSurvived() == 108 );
                   assert( row.getTotal() == 474 );
                   assert( startsWith( std::to_string( row.getPercentage() ), "0.22" ) );
                   // 10-25
                   row = table.getRow( 2 );
                   assert( row.getSurvived() == 128 );
                   assert( row.getTotal() == 330 );
                   assert( startsWith( std::to_string( row.getPercentage() ), "0.38" ) );
                   // 25-50
                   row = table.getRow( 3 );
                   assert( row.getSurvived() == 104 );
                   assert( row.getTotal() == 247 );
                   assert( startsWith( std::to_string( row.getPercentage() ), "0.42" ) );
                   // > 50
                   row = table.getRow( 4 );
                   assert( row.getSurvived() == 158 );
                   assert( row.getTotal() == 240 );
                   assert( startsWith( std::to_string( row.getPercentage() ), "0.65" ) );
                }
                else
                {
                   // Not Known at the end
                   // 1-10
                   assert( row.getSurvived() == 108 );
                   assert( row.getTotal() == 474 );
                   assert( startsWith( std::to_string( row.getPercentage() ), "0.22" ) );
                   // 10-25
                   row = table.getRow( 1 );
                   assert( row.getSurvived() == 128 );
                   assert( row.getTotal() == 330 );
                   assert( startsWith( std::to_string( row.getPercentage() ), "0.38" ) );
                   // 25-50
                   row = table.getRow( 2 );
                   assert( row.getSurvived() == 104 );
                   assert( row.getTotal() == 247 );
                   assert( startsWith( std::to_string( row.getPercentage() ), "0.42" ) );
                   // > 50
                   row = table.getRow( 3 );
                   assert( row.getSurvived() == 158 );
                   assert( row.getTotal() == 240 );
                   assert( startsWith( std::to_string( row.getPercentage() ), "0.65" ) );
                   // Not Known
                   row = table.getRow( 4 );
                   assert( row.getSurvived() == 2 );
                   assert( row.getTotal() == 18 );
                   assert( startsWith( std::to_string( row.getPercentage() ), "0.11" ) );
                }
                break;
            
         case 16:
                db.load( "/Users/howardstahl/Documents/My_Courses/UCLA/Fall,_2023/homeworks/project4/datafiles/titanic.csv");
                assert( db.loaded() );
                                         
                v = db.getPassengers();

                table = PassengerOutputTable( v );
                table.setDescription( "testing" );
                // by default, should report as NOVALUE
                assert( table.getDescription() == "testing" );
                assert( table.getOutputField() == Field::NOVALUE );
                assert( table.rowCount() == 0 );
                break;

         default:
                cout << "Bad argument" ;
                break;
    }
}

int main()
{
   cout << "Enter test number: ";
   int n;
   cin >> n;
   testone(n);
   cout << "Passed!" << endl;
   return( 0 );
}
