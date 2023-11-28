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
    // Apart from color matching, carry out action matching.
    // Check if top points to an ActionCard object. 
    // Hint: use dynamic_cast<>().
    // If so, check if this action matches top's action too.
    // Return true if either color or action matches.
}

string ActionCard::toString() {
    // TODO:
    // Print this action card in the form like [WC], [RS], [YD], etc.
}