//
//  Hand.cpp
//  Blackjack 
//
//  Created by Howard Stahl on 6/6/23.
//

#include "Hand.h"

//next two lines are additions
#include <iostream>
using namespace std;


namespace cs32
{

Hand::Hand( Card card1, Card card2 ) : mCard1( card1 ), mCard2( card2 )
{
    
}

Card Hand::getCard1() const
{
    return( mCard1 );
}

Card Hand::getCard2() const
{
    return( mCard2 );
}


// TODO CS 32 students need to complete this operation
Choice Hand::evaluateHand( Card dealerCard ) const
{
    // by default STAND
    Choice c = Choice::STAND;
    if(this -> isSoft() && this-> isPair()){//both cards are aces
        c = Choice::SPLIT;
    }
    else if(this -> isPair() && !this->isSoft()){//pair of not aces
        switch (this->getCard1().getFace()) {
            case Face::TEN:
            case Face::JACK:
            case Face::QUEEN:
            case Face::KING:
                c = Choice::STAND;
                break;
            case Face::NINE:
                if(dealerCard.getValue() == 7 || dealerCard.getValue() == 1 || dealerCard.getValue() == 10)
                    c = Choice::STAND;
                else
                    c = Choice::SPLIT;
                break;
            case Face::EIGHT:
                c = Choice::SPLIT;
                break;
            case Face::SEVEN:
                if(dealerCard.getValue() > 7 || dealerCard.getValue() == 1)
                    c = Choice::HIT;
                else
                    c = Choice:: SPLIT;
                break;
            case Face::SIX:
                if(dealerCard.getValue() == 2)
                    c = Choice::SPLITHIT;
                else if(dealerCard.getValue()<7 && dealerCard.getValue()>2 )
                    c = Choice::SPLIT;
                else
                    c = Choice::HIT;
                break;
            case Face::FIVE:
                if(dealerCard.getValue()<10 &&dealerCard.getValue()>1 )
                    c = Choice::DOUBLEHIT;
                else
                    c = Choice::HIT;
                break;
            case Face::FOUR:
                if (dealerCard.getValue() < 7 && dealerCard.getValue()>4)
                    c = Choice::SPLITHIT;
                else
                    c = Choice::HIT;
                break;
            case Face::THREE:
            case Face::DEUCE:
                if (dealerCard.getValue()<4 && dealerCard.getValue()>1)
                    c = Choice::SPLITHIT;
                else if(dealerCard.getValue()<8 && dealerCard.getValue()>3)
                    c = Choice::SPLIT;
                else
                    c = Choice::HIT;
                break;
            default:
                break;
        }
    }
    
    else if(this-> isSoft()){//one card is an ace
        switch (this-> returnNonAce().getFace()) {
            case Face::DEUCE:
            case Face::THREE:
                if(dealerCard.getValue()<7 && dealerCard.getValue()>4)
                    c = Choice::DOUBLEHIT;
                else
                    c = Choice::HIT;
                break;
            case Face::FOUR:
            case Face::FIVE:
                if(dealerCard.getValue()<7 && dealerCard.getValue()>3)
                    c = Choice::DOUBLEHIT;
                else
                    c = Choice::HIT;
                break;
            case Face::SIX:
                if(dealerCard.getValue()<7 && dealerCard.getValue()>2)
                    c = Choice::DOUBLEHIT;
                else
                    c = Choice::HIT;
                break;
            case Face::SEVEN:
                if(dealerCard.getValue()<7 && dealerCard.getValue()>2)
                    c = Choice::DOUBLESTAND;
                else if(dealerCard.getValue()==2 || dealerCard.getValue()==7 || dealerCard.getValue()==8)
                    c = Choice::STAND;
                else
                    c = Choice::HIT;
                break;
            case Face::EIGHT:
                c = Choice::STAND;
                break;
            default:
                break;
        }
    }
    
    else
        //case with no aces- based on the hand value
        switch (mCard1.getValue() + mCard2.getValue()) {
            case 8:
                c = Choice::HIT;
                break;
            case 9:
                if(dealerCard.getValue()>2 && dealerCard.getValue()<7)
                    c = Choice::DOUBLEHIT;
                else
                    c = Choice::HIT;
                break;
            case 10:
                if(dealerCard.getValue()>1 && dealerCard.getValue()<10)
                    c = Choice::DOUBLEHIT;
                else
                    c = Choice::HIT;
                break;
            case 11:
                c = Choice::DOUBLEHIT;
                break;
            case 12:
                if(dealerCard.getValue()>3 && dealerCard.getValue()<7)
                    c = Choice::STAND;
                else
                    c=Choice::HIT;
                break;
            case 13:
            case 14:
                if(dealerCard.getValue()>1 && dealerCard.getValue()<7)
                    c = Choice::STAND;
                else
                    c=Choice::HIT;
                break;
            case 15:
                if(dealerCard.getValue() == 10)
                    c = Choice::SURRENDERHIT;
                else if(dealerCard.getValue()>1 && dealerCard.getValue()<7)
                    c = Choice::STAND;
                else
                    c=Choice::HIT;
                break;
            case 16:
                if(dealerCard.getValue()>1 && dealerCard.getValue()<7)
                    c = Choice::STAND;
                else if(dealerCard.getValue()>6 && dealerCard.getValue()<9)
                    c = Choice::HIT;
                else
                    c=Choice::SURRENDERHIT;
                break;
            case 17:
                c = Choice::STAND;
            default:
                break;
        }
    
    return( c );
}

// TODO CS 32 students need to complete this operation
bool Hand::isPair() const
{
    return( mCard1.getFace() == mCard2.getFace() );
}

// TODO CS 32 students need to complete this operation
bool Hand::isSoft() const
{
    if(mCard1.getFace() == Face::ACE ||  mCard2.getFace()==Face::ACE){
        return(true);
    }
    else
        return( false );
}

//returns the non Ace card
//only used AFTER checking isSoft is true and isPair is false
Card Hand::returnNonAce() const
{
    if(mCard1.getFace() != Face::ACE ){
        return mCard1;
    }
    else
        return mCard2;
    
}


}
