#include <iostream>
#include "Player.h"

using namespace std;

int Player::count = 0; 

Player::Player() {
    count++;
    name = "Player " + to_string(count);
}

string Player::getName() const {
    return name;
}

void Player::setName(string name_) {
    name = name_;
}

int Player::drawCard(DrawPile* drawPile, int n) {
    int d = drawPile->draw(hand, n);
    if (d == 0) {
        cout << "No more cards on draw pile!" << endl;
    }
    else {
        cout << name << " drawn " << d << " card(s)." << endl;
    }
    return d;
}

void Player::printHand(bool flipped) {
    // TODO:
    // Print all cards in the player's hand in one line.
    // If flipped is true, print the front of each card, e.g. [R1], [GS], [WD]
    // Otherwise, print the back of each card, i.e., "[Uno]".

    for(int i = 0; i < this->handSize(); i++){
        if(flipped){
            cout << "[" << hand[i]->toString() << "] ";
        }else{
            cout << "[Uno] ";
        }
    }
    cout << endl;
}

int Player::handSize() const {
    return int(hand.size());
}

int Player::handPoints() const {
    // TODO:
    // Compute and return the sum of values of all cards in hand 

    int sum = 0;
    for(int i = 0; i < this->handSize(); i++){
        sum += int(this->hand[i]->getValue());
    }
    return sum;
}

void Player::playCard(int idx, GameState& uno) {
    // TODO:
    // Locate the card at index idx and play it, 
    // i.e. call its play() function

    Card* card = this->hand[idx];

    // Move the card from hand to discard pile
    uno.discardPile->stack(card);
    hand.erase(hand.begin() + idx);
}

Color Player::mostFrequentColor() {
    // TODO:
    // Return the color that appears most frequently in the hand.
    // Exclude wild (draw 4) cards in this search.
    // If more than one color are equally most frequent, select the color
    // to return in this order: Red, Yellow, Green, Blue.

    int red = 0;
    int yellow = 0;
    int green = 0;
    int blue = 0;

    for(int i = 0; i < this->handSize(); i++){
        if(this->hand[i]->getColor() == Color::Red){
            red++;
        }else if(this->hand[i]->getColor() == Color::Yellow){
            yellow++;
        }else if(this->hand[i]->getColor() == Color::Green){
            green++;
        }else if(this->hand[i]->getColor() == Color::Blue){
            blue++;
        }else if(this->hand[i]->getColor() == Color::Wild){
            continue;
        }
    }

    if(red >= yellow && red >= green && red >= blue){
        return Color::Red;
    }else if(yellow >= red && yellow >= green && yellow >= blue){
        return Color::Yellow;
    }else if(green >= red && green >= yellow && green >= blue){
        return Color::Green;
    }else if(blue >= red && blue >= yellow && blue >= green){
        return Color::Blue;
    }
}

