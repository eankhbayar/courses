#include <iostream>
#include "cctype"
#include "WildCard.h"
#include "WildDraw4.h"
#include "Bot.h"

using namespace std;

WildCard::WildCard() : ActionCard(Color::Wild, Action::ChgColor) {
    setValue(Value::W);
}

bool WildCard::match(Card* top ) {
    // TODO:
    // Add one statement here to complete the color matching logic 
    // for this card type
    return true;
}

void WildCard::play(GameState& uno) {
    // TODO:
    // Check if the "this" pointer is aiming at a WildDraw4 object.
    // If not, call the superclass Card's play() function.
    // (This check is to skip redundant superclass Card's play() call 
    //  for WildDraw4 since it's been called in Draw2's play().)
    // Hint: use dynamic_cast<>().

    if(dynamic_cast<WildDraw4*>(this) == nullptr){
        Card::play(uno);
    }

    int id = *uno.turn;
    Player* currentPlayer = uno.players[id];
    Bot* botPlayer = dynamic_cast<Bot*>(currentPlayer);
    Color selectedColor;
    char selectedColor_;

    if(botPlayer != nullptr) {
        // If the player is a bot, use the mostFrequentColor() function.
        selectedColor = botPlayer->mostFrequentColor();
    } else {
        // If the player is a human, prompt for color selection.
        cout << "Enter a color [R, Y, G, B]: ";
        cin >> selectedColor_;


        while(selectedColor_ != 'R' && selectedColor_ != 'Y' && selectedColor_ != 'G' && selectedColor_ != 'B') {
            cout << "Invalid option! Enter a color [R, Y, G, B]: ";
            cin >> selectedColor_;
        }
    }

    if(selectedColor_ == 'R') {
        selectedColor = Color::Red;
    } else if(selectedColor_ == 'Y') {
        selectedColor = Color::Yellow;
    } else if(selectedColor_ == 'G') {
        selectedColor = Color::Green;
    } else if(selectedColor_ == 'B') {
        selectedColor = Color::Blue;
    }

    // Set color of this card to the selected color.
    setColor(selectedColor);

    cout << "Color changed to " << COLORS[int(getColor())] << "!" << endl;

    // TODO:
    // Change color from Wild to the color selected by the player.
    // First, get the pointer to the current player via GameState struct.
    // Check if it points to a Bot object. Hint: use dynamic_cast<>().
    // If so, use the mostFrequentColor() function of the Player class
    // to select a color to change.
    // Otherwise (i.e., for a Man object), prompt the user to enter a 
    // single character, valid choice in [R, Y, G, B], to select a color
    // to change. Show error message "Invalid option!" if the user input 
    // is not one of the 4 letters.
    // Set color of this card to the selected color.
}

string WildCard::toString() {
    // TODO:
    // Return a string representation of this card with color code shown as 'W'

    if(this->getAction() == Action::Draw4){
        return "[WD]";
    }
    if(this->getAction() == Action::ChgColor){
        return "[WC]";
    }
}