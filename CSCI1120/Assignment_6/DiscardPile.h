// Name:       Ankhbayar Enkhtaivan
// Student ID: 1155185142
// Email:      1155185142@link.cuhk.edu.hk

#ifndef DISCARDPILE_H
#define DISCARDPILE_H

#include "Deck.h"

class DiscardPile : public Deck
{
public:
    DiscardPile();
    Card* top() const;
    void stack(Card* card);
};

#endif // DISCARDPILE_H