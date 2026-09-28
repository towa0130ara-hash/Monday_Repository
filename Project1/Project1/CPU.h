#pragma once

#include "Config.h"

class Cpu
{
private:
    int* cards;

    int cardCount;
    int total;

public:
    Cpu();
    ~Cpu();

    void AddCard(int card);

    int GetTotal() const;
    int GetCardCount() const;
    int GetCard(int index) const;

    bool ShouldDraw(int playerTotal) const;
};