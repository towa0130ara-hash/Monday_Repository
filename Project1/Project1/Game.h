#pragma once

#include "Config.h"
#include "Player.h"
#include "Cpu.h"

class Game
{
private:
    int deck[DECK_SIZE];
    int remaining;

    Player player;
    Cpu cpu;

public:
    Game();

    void Start();

private:
    void CreateDeck();
    int DrawCard();

    void DealInitialCards();

    void PlayerTurn();
    void CpuTurn();

    void ShowPlayer();
    void ShowCpu();

    void Judge();
};