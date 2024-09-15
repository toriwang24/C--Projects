#ifndef DEQUENODE_CPP
#define DEQUENODE_CPP


#include "DequeNode.h"
using namespace std;

namespace cs32 {

template <typename Type>
DequeNode<Type>::DequeNode( const Type& v,
                      DequeNode * node,
                      DequeNode * pre ):value(v), next(node),previous(pre) // Initializing the member variables
{
    if(node != nullptr){
        node->setPrevious(this);
    }
    if(pre != nullptr){
        pre->setNext(this);
    }
    
}

template <typename Type>
Type DequeNode<Type>::getElement() const {
	return( value );
}

template <typename Type>
DequeNode<Type> * DequeNode<Type>::getNext() const {
    // TODO: CS 32 Students to complete code here
	return( next );
}

template <typename Type>
void DequeNode<Type>::setNext( DequeNode<Type> * node ) {
    // TODO: CS 32 Students to complete code here
    next = node;
}

template <typename Type>
DequeNode<Type> * DequeNode<Type>::getPrevious() const {
    // TODO: CS 32 Students to complete code here
    return( previous );
}

template <typename Type>
void DequeNode<Type>::setPrevious( DequeNode<Type> * node ) {
    // TODO: CS 32 Students to complete code here
    previous = node;
}

}


#endif
