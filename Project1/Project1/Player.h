#pragma once

#include "Config.h"

class Player
{
private:
    int cards[DECK_SIZE] = {};
    int cardCount;
    int total;

public:
    Player();

    void AddCard(int card);

    int GetTotal() const;
    int GetCardCount() const;
    int GetCard(int index) const;
};