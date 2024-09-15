// Menu.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <cassert>
#include "List.h"
#include "ListNode.h"

using namespace std;
using namespace cs32;

//enum class CHOICE {MAKEEMPTY, ISEMPTY, ADDTOFRONT, ADDTOREAR, DELETE, FIND, QUIT, PRINT, OPERATOR };

//CHOICE menu();

int main() {
    
    List l1;
    assert(l1.size() == 0);
    assert(l1.min() == "" );
    assert(l1.position("Hawk")==-1);
    assert(l1.before("Hawk","black widow")==false);
    string testdata1="";
    assert(l1.get(4, testdata1)==false);
    assert(testdata1=="");

    
    l1.addToFront("Hawkeye");
    l1.addToFront("Thor");
    l1.addToFront("Hulk");
    l1.addToFront("Black Widow");
    l1.addToFront("Iron Man");
    l1.addToFront("Captain America");
    for (int k = 0; k < l1.size(); k++)
    {
        string x;
        l1.get(k, x);
        cerr << x << endl;
    }
    assert(l1.size() == 6);
    // should print:
    // Captain America
    // Iron Man
    // Black Widow
    // Hulk
    // Thor
    // Hawkeye
    assert( l1.position( "Hawkeye" ) == 5 );
    assert( l1.position( "Thor" ) == 4 );
    assert( l1.position( "Hulk" ) == 3 );
    assert( l1.position( "Black Widow" ) == 2 );
    assert( l1.position( "Iron Man" ) == 1 );
    assert( l1.position( "Captain America" ) == 0 );
    assert( l1.position( "Not there" ) == -1 );

    assert( l1.before( "Not there", "Hulk" ) == false );
    assert( l1.before( "Hulk", "Not there" ) == false );
    assert( l1.before( "Hulk", "Captain America" ) == false );
    assert( l1.before( "Black Widow", "Hulk" ) == true );
    assert( l1.before( "Captain America", "Hulk" ) == true );
    assert( l1.min() == "Black Widow" );
    
    string getCpt = "";
    assert(l1.get(0, getCpt)==true);
    assert(l1.get(9, getCpt)==false);
    assert(getCpt=="Captain America");
    
    l1.removeAllBiggerThan( "Happy" );
    // now just "Captain America", "Black Widow"
    assert( l1.size() == 2 );
    assert( l1.position( "Hawkeye" ) == -1 );
    assert( l1.position( "Thor" ) == -1 );
    assert( l1.position( "Hulk" ) == -1 );
    assert( l1.position( "Black Widow" ) == 1 );
    assert( l1.position( "Iron Man" ) == -1 );
    assert( l1.position( "Captain America" ) == 0 );
    assert( l1.position( "Not there" ) == -1 );

    
    List test;
    test.addToRear("Apple");
    test.addToRear("Banana");
    test.addToRear("Pear");
    test.addToRear("Strawberry");
    test.addToRear("Kiwi");
    test.addToRear("Cherry");
    test.addToRear("Orange");
    test.addToRear("Grape");
    test.addToFront("Guava");

    assert(test.size() == 9);
    assert(test.position("Banana") == 2);
    assert(test.position("Strawberry") == 4);
    assert(test.position("Guava") == 0);
    assert(test.position("Grape") == 8);
    assert(test.position("Melon") == -1);


    assert(test.before("Kiwi", "Orange") == true);
    assert(test.before("Pear", "Apple") == false);
    assert(test.before("Melon", "Cherry") == false);
    assert(test.before("Cherry", "Melon") == false);


    string element;
    assert(test.get(1, element) == true);
    assert(element == "Apple");
    assert(test.get(10, element) == false);

    assert(test.min() == "Apple");

    test.removeAllBiggerThan("Drake");
    assert(test.size() == 3);
    assert(test.position("Apple") == 0);
    assert(test.position("Cherry") == 2);
    
    cerr << "all tests passed!" << endl;
    return(0);
}
