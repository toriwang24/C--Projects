#include "List.h"

using namespace std;

namespace cs32 {

List::List() {
	head = nullptr;
}

List::List( const List& rhs ) {//copy constructor
    if (rhs.head == nullptr) head = nullptr;
    else {
        head = new ListNode( rhs.head->getElement() );
        ListNode *q = head;
        ListNode *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new ListNode( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            p = p->getNext( );
            q = q->getNext( );
        }
    }
}

List::~List() {//destructor
	makeEmpty();
}

bool List::isEmpty() const {
	return( head == nullptr );
}

void List::makeEmpty() {
	while (!isEmpty()) {
        deleteItem( head->getElement( ) );
	}
}

void List::addToFront( const std::string & data )
{
    ListNode * newnode = new ListNode( data );
    newnode->setNext( head );
    head = newnode;
}

void List::addToRear( const std::string & data )
{
    if (head == nullptr)
    {
        addToFront( data );
    }
    else
    {
        ListNode * node = head;
        while( node->getNext() != nullptr )
        {
            node = node->getNext();
        }
        ListNode * newnode = new ListNode( data );
        newnode->setNext( nullptr );
        node->setNext( newnode );
    }
}

void List::deleteItem( const std::string & data )
{
    ListNode * node = head;
    ListNode * priornode = nullptr;

        while( node != nullptr )
        {
            if (node->getElement() == data)
            {
                if (priornode != nullptr)
                    priornode->setNext( node->getNext( ) );
                else
                    head = node->getNext();
                delete( node );
                break;
            }
            priornode = node;
            node = node->getNext();
        }
}

bool List::findItem( const std::string & data )
{
    bool result = false;
    ListNode * node = head;
    while( node != nullptr )
    {
        if (node->getElement() == data)
        {
            result = true;
            break;
        }
        node = node->getNext();
    }
    return( result );
}

std::string List::printItems( )
{
    string s = "";
    if (isEmpty())
    {
        s += "---> empty list";
    }
    else
    {
        s += "head:";
        ListNode * node = head;
        while( node != nullptr )
        {
            s += " -> ";
            s += node->getElement();
            node = node->getNext();
        }
        s += " -> nullptr ";
    }
    return( s );
}


// Deep copy of linked list
const List& List::operator =( const List& rhs ) {
	if (this != &rhs) {
		makeEmpty();

        ListNode * right = rhs.head;

		while( right != nullptr )
        {
            addToRear( right->getElement() );
            right = right->getNext();
		}
	}

	return( *this );
}

//returns total number of items in the list
size_t List::size() const{
    size_t size = 0;
    if(head == nullptr) return size;//if the list is empty
    else{//iterate through the linked list increasing the size with each iteration
        ListNode* node = head;
        while(node != nullptr){
            size++;
            node = node -> getNext();
        }
    }
    return size;
}

//returns location of first occurence of data found in the list
int List::position( const std::string& data ) const{
    ListNode * node = head;
    int pos=0;
    while( node != nullptr )
    {//iterate through the list
        //if the node's element matches the data
        if (node->getElement() == data)
        {
            return pos;//return position and break
            break;
        }
        pos++;//increase position and go to next node
        node = node->getNext();
    }
    //if item is never found (we reach the last node nullptr) return -1
    return(-1);
}


bool List::before( const std::string& before, const std::string& after ) const{
    if(this->position(before) == -1 || this->position(after) == -1){//if either before, after, or both strings are not in the list, return false by default
        return false;
    }
    else{//if they both exist, than use the position function and return appropriately
        return(this->position(before) < this-> position(after));
    }
}


bool List::get( int i, std::string& data ) const{
    if(i>=size() || i <0){//if i is outside the range of the list or negative (note use >= becase index starts at 0!)
        return(false);//return false by default
    }
    else{//otherwise, iterate throughout the list tracking the position
        ListNode *node = head;
        int pos=0;
        while(pos<i){//while the position is before the ith, get the next node
            //when we exit the loop, we will be at node (i)
            node = node-> getNext();
            pos++;
        }
        //set data to the string in the node
        data = node -> getElement();
    }
    return(true);
}

string List::min() const{
    if(head == nullptr)
        return("");//if the list is empty, return empty string
    else{
        string min = head->getElement();//set the min to the first string in the list
        ListNode *node = head;//create a node to iterate
        while(node != nullptr){//iterate through the list
            //for every element we encounter, if it is smaller than the current min than set min
            if(node-> getElement() < min){
                min = node->getElement();
            }
            node = node-> getNext();
        }
        //After iterating thorgh the whole list return the minimum
        return(min);
    }
}

void List::removeAllBiggerThan( const std::string& data ){
    ListNode * node = head;//create node to iterate
    ListNode * priornode = nullptr;//create node that should be prior

        while( node != nullptr )
        {
            if (node->getElement() > data)//if we encounter a node that should be removed
            {
                //check that priornode is not the nullptr
                if (priornode != nullptr)
                    //set our prior node next node to be the node after current node
                    priornode->setNext(node->getNext());
                else 
                    //if the current node is the head
                    head = node-> getNext();
                    //set our head to the node after current node
                
                ListNode *deletenode = node; //create a new node to delete to our current node
                node = node->getNext(); //set our node to the next node
                delete( deletenode );
            }
            else{ // if our node data is less than the data, than iterate the priornode and node
                priornode = node;
                node = node->getNext();
            }

        }
}



}


