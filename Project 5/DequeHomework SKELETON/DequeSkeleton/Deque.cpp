#ifndef DEQUE_CPP
#define DEQUE_CPP

#include "Deque.h"
#include <string>
#include <sstream>

using namespace std;

namespace cs32 {

template <typename Type>
Deque<Type>::Deque(): head(nullptr), tail(nullptr)
{
    
}

template <typename Type>
Deque<Type>::Deque( const Deque& rhs ) {
    if (rhs.head == nullptr)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = new DequeNode<Type>( rhs.head->getElement() );
        tail = head;
        DequeNode<Type> *q = head;
        DequeNode<Type> *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new DequeNode<Type>( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            q->getNext()->setPrevious( q );
            tail = q->getNext();
            p = p->getNext();
            q = q->getNext();
        }
    }
}

template <typename Type>
Deque<Type>::~Deque() {
	makeEmpty();
}

template <typename Type>
bool Deque<Type>::isEmpty() const {
    //if the head and tail and null then it's empty
    if(head == nullptr && tail == nullptr){
        return(true);
    }
    return( false );
}

template <typename Type>
void Deque<Type>::makeEmpty() {
    //copy the head to another node
    while(!isEmpty()){
        deleteFront();
    }
}

template <typename Type>
void Deque<Type>::addToFront( const Type & data )
{
    
    if(isEmpty()){//if the deque is empty, create a new dequenode to be the head with the next to be tail and previous to be nullptr
        head = new DequeNode<Type>(data, tail,  nullptr);
    }
    else if(head != nullptr && tail == nullptr){//there is only one element at head
        //create a new node with the head as the next node and previous is nullptr
        DequeNode<Type> * newnode = new DequeNode<Type>(data, head, nullptr);
        //set the previous head to be tail
        tail = head;
        //set head to the new node
        head = newnode;
        //set the previous of tail to head
        tail->setPrevious(head);
    }
    else{//if the deque has a head and tail
        //create a new node with head as it's next and previous to be nullptr
        DequeNode<Type> * newnode = new DequeNode<Type>(data, head,  nullptr);
        //set the previous of the former head to the new node
        head->setPrevious(newnode);
        //set the new node to head
        head = newnode;
    }
    
}

template <typename Type>
void Deque<Type>::addToRear( const Type & data )
{
    if(isEmpty()){ ///if the deque is empty, create a new dequenode to be the head with the next to be tail and previous to be nullptr
        head = new DequeNode<Type>(data, tail,  nullptr);
        tail = nullptr;
    }
    else if(head != nullptr && tail == nullptr){//there is only one element at head
        //create a new node with next to be nullptr and the former to be head
        DequeNode<Type> * newnode = new DequeNode<Type>(data, nullptr, head);
        //set the tail to be the new node
        tail = newnode;
        //set the next of head to be tail
        head->setNext(tail);
    }
    else{//there is a head and tail
        //create a new node with the next to be nullptr and previous to be tail
        DequeNode<Type> * newnode = new DequeNode<Type>(data, nullptr, tail);
        //set the next of the previous tail to the new node
        tail -> setNext(newnode);
        //set the tail to new node
        tail = newnode;
    }
}

template <typename Type>
void Deque<Type>::deleteFront( )
{
    if(head == nullptr && tail == nullptr){//empty deque do nothing
        
    }
    else if(head != nullptr && tail == nullptr){//only one item at head
        DequeNode<Type> * newnode = head;
        head = nullptr;
        delete(newnode);
    }
    else if(head != nullptr && tail != nullptr){//there are items at both head and tail
        //check if the next element of head is tail (there are only 2 eleemnts) becaue we need to then set head to the next element and tail to nullptr
            DequeNode<Type> * newnode = head;
            if(head -> getNext() == tail){
                head = tail;
                head->setPrevious(nullptr);
                tail = nullptr;
                head->setNext(tail);
            }
            else{
                head = head -> getNext();
                if(head != nullptr){
                    head -> setPrevious(nullptr);
                }
            }
            delete(newnode);
        }
}

template <typename Type>
bool Deque<Type>::deleteItem( const Type & data )
{
    //set result to false (did not find the item)
    bool result = false;
    //if the head is null it's empty - return false
    if(head == nullptr){
        return(result);
    }
    else if(head != nullptr && tail == nullptr){//if there is only a head
        if(head ->getElement() == data){//if the head matches the data
            //create a node holding head
            DequeNode<Type> * node = head;
            //set head and tail to nullptr
            head = nullptr;
            tail = nullptr;
            //delete the node
            delete(node);
            //set node to true
            result = true;
        }
    }
    else{//there is a head and tail
        //create two nodes- one head and one prior
        DequeNode<Type> * node = head;
        DequeNode<Type> * priornode = nullptr;

        while(node != nullptr){//iterate through the deque
            if(node ->getElement() == data){//if node's element matches
                //if it is the head
                if(node == head){
                    //set head to next
                    head = node->getNext();
                    head -> setPrevious(nullptr);
                    //if the head is now the tail
                    if(head == tail){
                        //set tail to nullptr
                        tail = nullptr;
                        head->setNext(tail);
                    }
                }
                else if(node == tail){//if it is the tail
                    tail = tail -> getPrevious();
                    tail -> setNext(nullptr);
                    if(head == tail){
                        tail = nullptr;
                        head->setNext(tail);
                    }
                }
                else{
                    //set priornodes next to be the next of node
                    priornode->setNext( node->getNext() );
                    //check that it is not nullptr (meaning the node is not tail)
                    if(node->getNext()  != nullptr){
                        //set the previous of this node to priornode
                        (node->getNext()) -> setPrevious(priornode);
                    }
                    else{//the node was tail
                        //set the priornode to the new tail
                        tail = priornode;
                        tail->setNext(nullptr);
                    }
                }
                //delete the node with matching element
                delete(node);
                //set result to true and break
                result = true;
                break;
            }
            //to iterate through the list, set priornode ot the node
            priornode = node;
            //set node to next node
            node = node->getNext();
        }
    }
    return( result );
}


template <typename Type>
Type Deque<Type>::front( ) const
{
    //create default value
    Type result = Type();
    //return the front element
    if(head != nullptr){
        result = head ->getElement();
    }
    return( result );
}

template <typename Type>
Type Deque<Type>::rear( ) const
{
    //create default
    Type result = Type();
    if(head != nullptr && tail == nullptr){//only 1 element
        result = head ->getElement();
    }
    else if(tail != nullptr){//return tail element
        result = tail ->getElement();
    }
    return( result );
}

template <typename Type>
void Deque<Type>::deleteRear()
{
    if(head == nullptr && tail == nullptr){//empty deque do nothing
        
    }
    else if(head != nullptr && tail == nullptr){//only one item at head
        DequeNode<Type> * newnode = head;
        head = nullptr;
        delete(newnode);

    }
    else if (head != nullptr && tail != nullptr){//there are items at both head and tail
        //check if the next element of head is tail (there are only 2 eleemnts) becaue we set tail to nullptr
        DequeNode<Type> * newnode = tail;
        if(head -> getNext() == tail){
            tail = nullptr;
            head->setNext(tail);
        }
        else{
            tail = tail->getPrevious();
            if(tail != nullptr){
                tail->setNext(nullptr);
            }
        }
        delete(newnode);
    }
}

// Howard is supplying code to convert a Type to a string using its operator <<
template <typename Type>
std::string Deque<Type>::to_string( const Type & value ) const
{
    stringstream s;
    // call the Type's operator <<
    s << value;
    return( s.str() );
}


template <typename Type>
std::string Deque<Type>::printItems( ) const
{
    string s = "";
    DequeNode<Type> * node = head;
    while(node != nullptr){
        s += to_string(node->getElement());
        s+= ", ";
        node = node->getNext();
    }

    //stringstream s;
    return( s );
}


// Deep copy of linked list
template <typename Type>
const Deque<Type> & Deque<Type>::operator =( const Deque<Type> & rhs ) {
    // TODO: CS 32 Students to complete code here
    if(this != &rhs){
        makeEmpty();
        DequeNode<Type>* node = rhs.head;
        while(node!=nullptr){
            addToRear(node->getElement());
            node = node->getNext();
        }
    }
    return( *this );
	
}

template <typename Type>
size_t Deque<Type>::size() const
{
    size_t result = 0;
    if(head == nullptr && tail == nullptr){
        return(result);
    }
    else{
        DequeNode<Type>* newnode = head;
        while(newnode != nullptr){
            result++;
            newnode = newnode->getNext();
        }
    }
    return( result );
}


template <typename Type>
bool   Deque<Type>::get( int i, Type & data ) const
{
    //index 0 is the first element
    //size of 1- can only get 0 element thus 0 !> 1
    if(i <0 || i >= size()){//if the index is greater than or equal to size or negative return false
        return( false );
    }
    else{
        //otherwise, create a new node to be head
        DequeNode<Type>* newnode = head;
        for(int j = 0; j<i; j++){
            //go through the deque until we reach index
            newnode = newnode-> getNext();
        }
        //set the data to be the element of the node and return true
        data = newnode->getElement();
        return(true);
    }
}


}


#endif
