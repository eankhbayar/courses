// Name:       Ankhbayar Enkhtaivan
// Student ID: 1155185142
// Email:      1155185142@link.cuhk.edu.hk

#include <iostream>
#include "Skip.h"

using namespace std;

Skip::Skip(Color c) : ActionCard(c, Action::Skip) {
}

void Skip::play(GameState& uno) {
    Card::play(uno);
    *(uno.turnSkipped) = true;
}