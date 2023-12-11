#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Deck.h"

using namespace std;

Deck::Deck(bool fill) {
    if (fill) {
        for (int c = int(Color::Red); c <= int(Color::Blue); c++) {
            // Create number cards
            for (int v = int(Value::N0); v <= int(Value::N9); v++) {
                cards.push_back(new Card(Color(c), Value(v)));
            }
            // Create action cards
            for (int i = 0; i < 2; i++) {
                cards.push_back(new Reverse(Color(c)));
                cards.push_back(new Skip(Color(c)));
                cards.push_back(new Draw2(Color(c)));
            }
        }
        // Create wild cards
        for (int i = 0; i < 4; i++) {
            cards.push_back(new WildCard());
            cards.push_back(new WildDraw4());
        }
    }
}

void Deck::shuffle() {
#ifdef _WIN32
    random_shuffle(cards.begin(), cards.end());
#else
    random_shuffle(cards.begin(), cards.end(), [](int n) { return std::rand() % n; });
#endif
}

void Deck::print() {
    // TODO: 
    // Print the string representations and their value points of 
    // all cards of the deck. List at most 10 cards per line.

    for(int i = 0; i < cards.size(); i++){
        int value = int(cards[i]->getValue());
        string str = cards[i]->toString();
        string value_str = to_string(value);
        if(i == cards.size() - 1){
            cout << setw(7) << left << string() + cards[i]->toString() + '=' + value_str;
        }else{
            cout << setw(8) << left << string() + cards[i]->toString() + '=' + value_str + " ";
        }
        // cout << "K";
        if((i+1) % 10 == 0 || i == cards.size()-1){
            cout << endl;
        }
    }

}
