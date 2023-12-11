// Name:       Ankhbayar Enkhtaivan
// Student ID: 1155185142
// Email:      1155185142@link.cuhk.edu.hk

#ifndef DRAWPILE_H
#define DRAWPILE_H

#include "Deck.h"

class DrawPile : public Deck
{
public:
    DrawPile();
    int size() const;
    int draw(vector<Card*> &hand, int n = 1);
};

#endif // DRAWPILE_H