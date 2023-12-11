// Name:       Ankhbayar Enkhtaivan
// Student ID: 1155185142
// Email:      1155185142@link.cuhk.edu.hk

// TODO:
// Implement the Reverse class
#include <iostream>
#include "Reverse.h"
using namespace std;
Reverse::Reverse(Color c) : ActionCard(c, Action::Reverse) {
}
void Reverse::play(GameState& uno) {
    Card::play(uno);
    *(uno.delta) *= -1;
    if(uno.P == 2) {
        *(uno.turnSkipped) = (true);
    }
}