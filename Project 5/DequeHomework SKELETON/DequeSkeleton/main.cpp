// Menu.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <cassert>
#include "Deque.h"
#include "Deque.cpp"
#include "DequeNode.h"
#include "DequeNode.cpp"
#include "Garage.h"




int main()
{
    using namespace std;
    using namespace cs32;

    // Deque Tests

           Deque< int > dInt;
           int x;
           Deque< std::string > dString;
           std::string s;

           dInt.deleteFront( );
           dInt.deleteRear( );
           x = 12;
           assert( dInt.deleteItem( x ) == false );
           assert( dInt.size( ) == 0 );
           assert( dInt.get( -10, x ) == false );
           assert( dInt.isEmpty( )  );
    
    
    
    

           s = "Hello";
           dString.addToFront( s );
           s = "World!";
           dString.addToRear( s );
           s = "Howard";
           assert( dString.deleteItem( s ) == false );
           assert( dString.size( ) == 2 );
           assert( dString.get( -10, s ) == false );
           assert( dString.isEmpty( ) == false );
           assert( dString.get( 0, s ) && s == "Hello" );
           assert( dString.get( 1, s ) && s == "World!" );

           dString.deleteFront( );
           s = "Hello";
           assert( dString.deleteItem( s ) == false );
           assert( dString.size( ) == 1 );
           assert( dString.get( 0, s ) && s == "World!" );
           assert( dString.isEmpty( ) == false );
           dString.deleteRear( );
           s = "World!";
           assert( dString.deleteItem( s ) == false );
           assert( dString.size( ) == 0 );
           assert( dString.get( 0, s ) == false );
           assert( dString.isEmpty( ) );

    // Garage Tests
           Garage g;
           Garage gSix( 6 );

           assert( g.size( ) == 0 );
           assert( g.capacity( ) == 10 );
            
           assert( gSix.size( ) == 0 );
           assert( gSix.capacity( ) == 6 );
           gSix.tossIn( "shoes" );
           gSix.tossIn( "shirts" );
           gSix.tossIn( "books" );
           assert( gSix.size( ) == 3 );
           assert( gSix.capacity( ) == 6 );
           gSix.tossIn( "suitcases" );
           assert( gSix.tossIn( "tables" ) == false );  // nothing thrown away
           assert( gSix.tossIn( "chairs" ) == false );  // nothing thrown away
           assert( gSix.size( ) == 6 );
           assert( gSix.capacity( ) == 6 );
           assert( gSix.find( "shoes" ) );
           assert( gSix.find( "shirts" ) );
           assert( gSix.find( "books" ) );
           assert( gSix.find( "suitcases" ) );
           assert( gSix.find( "tables" ) );
           assert( gSix.find( "chairs" ) );

           assert( gSix.tossIn( "boxes" ) );  // shoes thrown away...
    //cerr << gSix.printItems() << endl;
           assert( gSix.size( ) == 6 );
           assert( gSix.capacity( ) == 6 );
           assert( gSix.find( "boxes" ) );
           assert( gSix.find( "shoes" )  == false );
           assert( gSix.find( "shirts" ) );
           assert( gSix.find( "books" ) );
           assert( gSix.find( "suitcases" ) );
           assert( gSix.find( "tables" ) );
           assert( gSix.find( "chairs" ) );

           assert( gSix.tossOut( "shoes" ) == false );   // shoes not found...
           assert( gSix.use( "shoes" ) == false );       // shoes not found...
           assert( gSix.use( "tables" ) );
    //cerr << gSix.printItems() << endl;

           assert( gSix.tossIn( "records" ) );     // shirts thrown away...
           assert( gSix.size( ) == 6 );
           assert( gSix.capacity( ) == 6 );
           assert( gSix.find( "records" ) );
           assert( gSix.find( "tables" ) );
           assert( gSix.find( "boxes" ) );
           assert( gSix.find( "shoes" ) == false );
           assert( gSix.find( "shirts" ) == false );
           assert( gSix.find( "books" ) );
           assert( gSix.find( "suitcases" ) );

           assert( gSix.tossOut( "books" ) );
           assert( gSix.tossOut( "records" ) );
           assert( gSix.tossOut( "shoes" ) == false);
    //cerr << gSix.printItems() << endl;
           assert( gSix.size( ) == 4 );
           assert( gSix.capacity( ) == 6 );
           assert( gSix.find( "records" ) == false );
           assert( gSix.find( "tables" ) );
           assert( gSix.find( "chairs" ) );
           assert( gSix.find( "boxes" ) );
           assert( gSix.find( "shoes" ) == false );
           assert( gSix.find( "shirts" ) == false );
           assert( gSix.find( "books" ) == false );
           assert( gSix.find( "suitcases" ) );

           assert( gSix.tossOut( "tables" ) );
           assert( gSix.tossOut( "boxes" ) );
           assert( gSix.tossOut( "suitcases" ) );
           assert( gSix.size( ) == 1 );
           assert( gSix.capacity( ) == 6 );
           assert( gSix.find( "records" ) == false );
           assert( gSix.find( "tables" ) == false );
           assert( gSix.find( "boxes" ) == false );
           assert( gSix.find( "shoes" ) == false );
           assert( gSix.find( "shirts" ) == false );
           assert( gSix.find( "books" ) == false );
           assert( gSix.find( "suitcases" ) == false );
           assert( gSix.find( "chairs" ) );
    
    Deque< string > d; //delete functions on empty, size 1, and size 2 cases
    d.deleteFront();
    d.deleteRear();
    d.deleteItem("a");
    d.addToRear("first");//"first
    d.deleteFront();//empty
    d.addToFront("first");//"first"
    d.addToRear("second");//"first second
    d.deleteFront();//"second"
    assert(d.front() == "second");
    d.addToFront("first");//"first second"
    d.deleteRear();//"first
    assert(d.front() == "first");
    d.addToRear("second");//"first second
    d.deleteItem("first");//"second
    assert(d.front() == d.rear() && d.front() == "second");//front and rear should both be //second
    d.addToFront("first");//first second
    d.deleteItem("second");//first
    assert(d.front() == d.rear() && d.front() == "first");//front and rear both first
    d.deleteItem("first");//empty
    assert(d.isEmpty());
    d.addToRear("first");//first
    assert(d.size() == 1);


     

     Deque<string > d2; //assignment operator
     d2 = d;
     d2.addToRear("second");
     assert(d2.front() == "first");
     d.addToFront("zero");
     assert(d2.size() == 2);
     assert(d2.front() == "first");
  

     Garage h(3); //Garage
     h.tossIn("first");
     h.tossOut("first");
     assert(h.size() == 0);
     h.tossIn("first");
     h.tossIn("second");
     h.tossIn("third");
     assert(h.tossIn("fourth") == true);
     assert(h.find("first") == false);
     assert(h.use("second") == true);
     assert(h.tossIn("first") == true);
     assert(h.find("third") == false);

           //cerr << "all tests passed!" << endl;
           return( 0 );
}
