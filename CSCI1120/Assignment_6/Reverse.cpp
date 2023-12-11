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
}