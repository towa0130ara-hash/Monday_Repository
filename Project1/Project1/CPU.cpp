#include "CPU.h"

Cpu::Cpu()
{
	cards = new int[DECK_SIZE];

	cardCount = 0;
	total = 0;
}

Cpu::~Cpu()
{
	delete[] cards;
}

void Cpu::AddCard(int card)
{
	if (cardCount>=DECK_SIZE)
	{
		return;
	}

	cards[cardCount] = card;

	cardCount++;

	total += card;
}

int Cpu::GetTotal()const
{
	return total;
}

int Cpu::GetCardCount()const
{
	return cardCount;
}

int Cpu::GetCard(int index)const
{
	if (index<0||index>=cardCount)
	{
		return 0;
	}
	return cards[index];
}

bool Cpu::ShouldDraw(int playerTotal)const
{
	//15i以下なら必ず引く
	if (total<=CPU_DRAW_SCORE)
	{
		return true;
	}

	//16以上でPlayerより小さいなら引く
	if (total<playerTotal)
	{
		return true;
	}

	//Player以上なら引かない
	return false;
}