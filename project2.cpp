//
//  main.cpp
//  Project2
//
//  Created by Tori Wang on 10/11/23.
//

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int modulo( unsigned int m, unsigned int n ){
    // - Returns the remainder of two positive integers, m and n
    if(m==0)
        return 0;
    if(m<n)
        return m;
    else
        return modulo(m-n, n);
};


int occurrences( int number, int d ){
    // - Returns the number of occurrences of the value d found in the parameter number.
    if(number == 0)
        return(0);
    else if(number % 10 ==d){
        return(1+occurrences(number/10, d));
    }
    else
        return occurrences(number/10, d);
    
    return(0);
};


string lucky7s( string s ){
    // - Returns a string where repeated matching characters in the value s get separated by the string "77".  You can assume that the input string s will have any 7's in it.
    if(s.size() == 1 || s.size()==0){
        return s;
    }
    else
        if(s[0] == s[1])
            return string(1,s[0]) + "77" +  lucky7s(s.substr(1));
        else
            return string(1,s[0]) + lucky7s(s.substr(1));
};


bool combinations( int array[ ], int size, int target ){
    //- Returns true if the total of any combination of elements in the array parameter equals the target value.
    if(target == 0)
        return true;
    if(size == 0 && target !=0)
        return false;
    int* arr = array+1;
 
    if(combinations(arr, size-1, target - array[0])){
        return true;
    }
    else
        return (combinations(arr, size-1, target));
};



int main() {
    
    // test code
    assert( modulo( 100, 10 ) == 0 );
    assert( modulo( 1, 13 ) == 1 );
    assert( modulo( 12, 5 ) == 2 );
    assert( modulo( 33, 6 ) == 3 );
    assert( modulo( 109, 100 ) == 9 );
    assert( modulo( 0, 1 ) == 0 );
    assert( modulo( 2, 7 ) == 2 );
    assert( modulo( 3, 2 ) == 1 );
    assert( modulo( 10938, 200 ) == 138 );
    
    assert( occurrences( 567, 2 ) ==  0 );
    assert( occurrences( 128874, 2 ) == 1 );
    assert( occurrences( 212121, 2 ) == 3 );
    assert( occurrences( 19038972, 9 ) == 2 );
    assert( occurrences( 233828, 3 ) == 2 );
    assert( occurrences( 329283, 8 ) == 1 );
    assert( occurrences( 100030, 0 ) == 4 );
    assert( occurrences( 29840, 2 ) == 1 );
    assert( occurrences( 0, 0 ) == 0 );
    assert( occurrences( 10, 0 ) == 1 );



    assert( lucky7s( "cs32" ) == "cs32" );
    assert( lucky7s( "Apple Baseball" ) == "Ap77ple Basebal77l" );
    assert( lucky7s( "abbba" ) == "ab77b77ba" );
    assert( lucky7s( "hello" ) == "hel77lo" );
    assert( lucky7s( "aaaaa" ) == "a77a77a77a77a" );
    assert( lucky7s( "ssoll" ) == "s77sol77l" );
    assert( lucky7s( "barel" ) == "barel" );
    assert( lucky7s( "slkdd" ) == "slkd77d" );

    int array[ 5 ] = { 2, 4, 6, 8, 10 };
    assert( combinations( array, 5, 10 ) == true );
    assert( combinations( array, 5, 18 ) == true );
    assert( combinations( array, 5, 15 ) == false );
    assert( combinations( array, 5, 2 ) == true );
    assert( combinations( array, 5, 3 ) == false );
    assert( combinations( array, 5, 4 ) == true );
    assert( combinations( array, 5, 8 ) == true );
    assert( combinations( array, 5, 11 ) == false );
    assert( combinations( array, 5, 20 ) == true );
    assert( combinations( array, 5, 24 ) == true );

    int other[ 6 ] = { 10, 8, 2, 6, 4, 34 };
    assert( combinations( other, 6, 10 ) == true );
    assert( combinations( other, 6, 18 ) == true );
    assert( combinations( other, 6, 15 ) == false );
    assert( combinations( other, 6, 34 ) == true );
    assert( combinations( other, 6, 44 ) == true );
    assert( combinations( other, 6, 52 ) == true );
    assert( combinations( other, 6, 58 ) == true );
    assert( combinations( other, 6, 62 ) == true );
    assert( combinations( other, 6, 63 ) == false );
    assert( combinations( other, 6, 64 ) == true );
    assert( combinations( other, 6, 100 ) == false );


    
    cerr << "all tests passed!" << endl;
    
    return(0);
    
}
