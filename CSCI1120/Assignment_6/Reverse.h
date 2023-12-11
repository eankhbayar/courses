#ifndef REVERSE_H
#define REVERSE_H

#include "ActionCard.h"

// TODO:
// Define the Reverse class which inherits from ActionCard.
class Reverse : public virtual ActionCard {
    Reverse(Color c);
    virtual void play(GameState& uno) override;
};

#endif // REVERSE_H