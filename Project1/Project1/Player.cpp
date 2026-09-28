#include "Player.h"

Player::Player()
{
    cardCount = 0;
    total = 0;
}

void Player::AddCard(int card)
{
    if (cardCount >= DECK_SIZE)
    {
        return;
    }

    cards[cardCount] = card;
    cardCount++;

    total += card;
}

int Player::GetTotal() const
{
    return total;
}

int Player::GetCardCount() const
{
    return cardCount;
}

int Player::GetCard(int index) const
{
    if (index < 0 || index >= cardCount)
    {
        return 0;
    }

    return cards[index];
}