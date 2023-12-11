// Name:       Ankhbayar Enkhtaivan
// Student ID: 1155185142
// Email:      1155185142@link.cuhk.edu.hk

#include <iostream>
#include <iomanip>
// You may add additional headers if needed

#include "Man.h"

using namespace std;

Man::Man() : Player() {
    setName(getName() + " (Man)");
}

int Man::pickCard(GameState& uno) {
    // TODO:
    // Show the hand of cards with selectable indexes
    // For each card in hand, print the card's string representation
    // with "[i]"" in front of it, where i is the index of the card
    // in the player's hand vector.
    // If the card cannot match the top of the discard pile, show 
    // "[x]" which means the card cannot be played.
    // Print at most 10 cards per line if there are many cards in hand.
    
    int count = 0;

    for(int i = 0; i < this->handSize(); i++){
        if(this->hand[i]->match(uno.discardPile->top())){
            count++;
            cout << "[" << i << "]" << this->hand[i]->toString() << " ";
        }else{
            cout << "[x]" << this->hand[i]->toString() << " ";
        }
        if((i+1) % 10 == 0){
            cout << endl;
        }
    }

    // Show the [D]raw option if draw pile still has cards.
    
    if(uno.drawPile->size() > 0){
        cout << "[D]raw" << endl;
    }

    // You may make an early return with PASSED if no matched cards in hand 
    // and draw pile is empty.

    if(count == 0 && uno.drawPile->size() == 0){
        return PASSED;
    }

    // Get user input for the option (selected card index or 'D' for draw).
    // Keep prompting until the option is valid.
    // If the input is 'D' (case-insensitive), draw 1 card from draw pile 
    // into this player's hand vector. The drawn card is added to the back
    // of the vector. 
    // If the drawn card is playable, return its index. Otherwise, return 
    // the constant DRAWN to mean a card has been drawn but not playable.
    // The caller seeing DRAWN returned should skip playing any card.
    // If the input is an integer that can index a playable card in hand, 
    // return the integer.
    //
    // Print error message "Invalid option!" for invalid index or incorrect 
    // input.
    //
    // Hint: read the user input as a string first. You can convert it to
    // integer later using an input string stream or the stoi() function.
    // The string stream method is preferred as it can detect non-integer input.

    string input;
    int index;

    while(true){
        cout << "Enter option: ";
        cin >> input;
        if(input == "D" || input == "d"){
            if(uno.drawPile->size() > 0){
                this->drawCard(uno.drawPile, 1);
                if(this->hand[this->handSize()-1]->match(uno.discardPile->top())){
                    cout << "Drawn " << this->hand[this->handSize()-1]->toString() << endl;
                    return this->handSize()-1;
                }else{
                    return DRAWN;
                }
            }else{
                cout << "Invalid option!" << endl;
            }
        }else{
            try{
                index = stoi(input);
                if(index >= 0 && index < this->handSize()){
                    if(this->hand[index]->match(uno.discardPile->top())){
                        return index;
                    }else{
                        cout << "Invalid option!" << endl;
                    }
                }else{
                    cout << "Invalid option!" << endl;
                }
            }catch(...){
                cout << "Invalid option!" << endl;
            }
        }
    }
}
