#include <iostream>
#include "ActionCard.h"

using namespace std;

ActionCard::ActionCard(Color c, Action a) : Card(c, Value::A), action(a) {
}

Action ActionCard::getAction() const {
    return action;
}

void ActionCard::setAction(Action a) {
    action = a;
}

bool ActionCard::match(Card* top) {
    // TODO:
    // Check if this color matches top's color. 

    if(this->getColor() == top->getColor()){
        return true;
    }
    
    ActionCard* actionCard = dynamic_cast<ActionCard*>(top);
    if(actionCard != nullptr){
        if(this->getAction() == actionCard->getAction()){
            return true;
        }
    }

    return false;
    
    // Apart from color matching, carry out action matching.
    // Check if top points to an ActionCard object. 
    // Hint: use dynamic_cast<>().
    // If so, check if this action matches top's action too.
    // Return true if either color or action matches.
}

string ActionCard::toString() {
    // TODO:
    // Print this action card in the form like [WC], [RS], [YD], etc.

    if(this->getColor() == Color::Wild){
        if(this->getAction() == Action::Draw4){
            return "[WD]";
        }
        if(this->getAction() == Action::ChgColor){
            return "[WC]";
        }
    }else{
        if(this->getAction() == Action::Skip){
            return "[" + COLORS[static_cast<int>(this->getColor())] + "S]";
        }
        if(this->getAction() == Action::Reverse){
            return "[" + COLORS[static_cast<int>(this->getColor())] + "R]";
        }
        if(this->getAction() == Action::Draw2){
            return "[" + COLORS[static_cast<int>(this->getColor())] + "D]";
        }
    }
}