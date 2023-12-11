// Name:       Ankhbayar Enkhtaivan
// Student ID: 1155185142
// Email:      1155185142@link.cuhk.edu.hk

// TODO:
// Implement the Bot class

// For the pickCard method, perform the following:
// (1) show the hand in a hidden manner, i.e., print each card as [Uno], 
//     if debugMode is false. 
// (2) Pick the first card in hand, from left to right, that matches 
//     the top card of the discard pile. Return its index in hand.
// (3) If no playable card in hand, draw a card if draw pile still has cards.
// (4) Set the index to return to be the index of the last element in hand.
// (5) If debugMode in client side is true, print "Drawn [XX]" where [XX] is
//     the card drawn.
// (6) If the card drawn matches the discard pile's top, return the drawn 
//     card's index (last element in hand).
//     Otherwise, return the constant DRAWN.

#include <iostream>
#include "Bot.h"

using namespace std;

Bot::Bot() : Player() {
    setName(getName() + " (Bot)");
}

int Bot::pickCard(GameState& uno) {


    // (1) show the hand in a hidden manner, i.e., print each card as [Uno], 
    //     if debugMode is false. 
    if(!uno.debugMode){
        this->printHand(false);
    }else{
        this->printHand(true);
    }

    // (2) Pick the first card in hand, from left to right, that matches 
    //     the top card of the discard pile. Return its index in hand.
    for(int i = 0; i < this->handSize(); i++){
        if(this->hand[i]->match(uno.discardPile->top())){
            return i;
        }
    }

    // (3) If no playable card in hand, draw a card if draw pile still has cards.
    if(uno.drawPile->size() > 0){
        int drawn = drawCard(uno.drawPile, 1);
        if(uno.debugMode){
            cout << "Drawn " << hand[handSize()-1]->toString() << endl;
        }
        if(hand[handSize()-1]->match(uno.discardPile->top())){
            return handSize()-1;
        }
    }

    return DRAWN;
}