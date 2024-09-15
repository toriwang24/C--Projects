#include "Garage.h"

namespace cs32
{

Garage::Garage( size_t capacity ):mCapacity(capacity)
{
    // TODO: CS 32 Students to complete code here
}

//  Once the capacity is reached, silently, the Garage should remove the rear Deque item to accommodate this new value
bool Garage::tossIn( std::string s )
{
    /*
     tossIn on a Garage should wind up calling addToFront( … ) on a Deque.  Whenever tossIn has to remove an old item to fit the new item, it should return true; otherwise, it should return false
     */
    if(size() < capacity()){//the number of elements is less than capacity
        //ad the element to the front
        mDeque.addToFront(s);
        return( false );
    }
    else{//the size is equal to capacity
        //delete the rear and add the element to front, thus keeping size equal to capacity
        mDeque.deleteRear();
        mDeque.addToFront(s);
        return( true );
    }
    
}

bool Garage::tossOut( std::string s )
{

    /*
     tossOut on a Garage should wind up calling deleteItem( … ) on a Deque and return true if it was able to successfully toss something out from the Garage.
     */
    return(mDeque.deleteItem(s));
}


// use something from the garage
// must be findable, then moved to the used pile
bool Garage::use( std::string s )
{
    /*
     Calls to use( … ) on a Garage should bring that item to the front of the underlying Deque.  By doing so, a Garage will be implementing a least-recently-used eviction strategy.  
     Only calls to use( ... ) move items in the underlying Deque.
     
     use( ... ) should return true whenever it successfully move items in the underlying Deque; otherwise, it should return false.
     */
    
    if(find(s)){//if the item exists
        //create a copy of mDeque
        Deque<std::string> copy(mDeque);
        //clear the original deque
        mDeque.makeEmpty();
        //while the copy is not empty
        while(!copy.isEmpty()){
            //if the tail item is not a match
            if(copy.rear() != s){
                //add the item to the front of mDeque (first items going in goes to the end of deque)
                mDeque.addToFront(copy.rear());
            }
            //delete the item at the end of the copy
            copy.deleteRear();
        }
        //after going through the copy, add the item to the front
        mDeque.addToFront(s);
        //return true
        return(true);

    }
    else{
        return( false );
    }
}

// is it in the garage?
bool Garage::find( std::string s )
{
    /*
     Calls to find( ... ) should not change the placement of items in the underlying Deque.  find( ... ) should return true whenever it successfully found the requested item in the Garage; otherwise, it should return false.
     */
    string value;
    for(int i =0; i < mDeque.size(); i++){
        mDeque.get(i, value);
        if(value == s){
            return(true);
        }
    }
    return( false );
}

// how much can this garage maximally hold?
size_t Garage::capacity()
{
    /*
     capacity( ) on a Garage should return the self-imposed limit on the amount of items allowed in the Garage
     */
    return( mCapacity );
}

size_t Garage::size( )
{
/*
 size( ) on a Garage should wind up calling size on a Deque.
 */
    return(mDeque.size());
}

std::string Garage::printItems( )
{
    return(mDeque.printItems());
}


}
