#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

Game::Game()
{
    remaining = DECK_SIZE;

    CreateDeck();

    srand(static_cast<unsigned int>(time(nullptr)));
}

// 山札を作る
void Game::CreateDeck()
{
    int index = 0;

    for (int value = MIN_CARD_VALUE; value <= MAX_CARD_VALUE; value++)
    {
        for (int i = 0; i < SAME_CARD_COUNT; i++)
        {
            deck[index] = value;
            index++;
        }
    }
}

// カードを引く
int Game::DrawCard()
{
    if (remaining <= 0)
    {
        return 0;
    }

    int index = rand() % remaining;

    int card = deck[index];

    // 最後のカードを空いた場所へ移動
    deck[index] = deck[remaining - 1];

    remaining--;

    return card;
}

// ゲーム開始
void Game::Start()
{
    cout << "==========================================\n";
    cout << "               CARD GAME\n";
    cout << "==========================================\n\n";

    DealInitialCards();

    PlayerTurn();

    // Playerがバーストした場合
    if (player.GetTotal() >= BURST_SCORE)
    {
        Judge();
        return;
    }

    CpuTurn();

    Judge();
}

// 最初のカードを配る
void Game::DealInitialCards()
{
    for (int i = 0; i < INITIAL_CARD_COUNT; i++)
    {
        player.AddCard(DrawCard());
    }

    for (int i = 0; i < INITIAL_CARD_COUNT; i++)
    {
        cpu.AddCard(DrawCard());
    }

    cout << "カードを2枚ずつ配りました\n\n";

    ShowPlayer();
    ShowCpu();

    cout << "\n";
}

// Playerターン
void Game::PlayerTurn()
{
    while (true)
    {
        cout << "----------------------------\n";
        cout << "Playerのターン\n";
        cout << "----------------------------\n";

        ShowPlayer();

        int total = player.GetTotal();

        cout << "Playerの合計: " << total << "\n\n";

        // 21になった
        if (total == WIN_SCORE)
        {
            cout << "Playerは21になりました！\n";
            cout << "CPUのターンへ移ります\n\n";

            return;
        }

        // 22以上になった
        if (total >= BURST_SCORE)
        {
            cout << "Playerはバーストしました！\n";
            return;
        }

        int input;

        cout << "カードを引きますか？\n";
        cout << "0 : Yes\n";
        cout << "1 : No\n";
        cout << "> ";

        cin >> input;

        if (input == 0)
        {
            int card = DrawCard();

            player.AddCard(card);

            cout << "\n";
            cout << card << "のカードを引きました\n\n";
        }
        else if (input == 1)
        {
            cout << "\nPlayerはカードを引きません\n";
            cout << "CPUのターンへ移ります\n\n";

            return;
        }
        else
        {
            cout << "\n0か1を入力してください\n\n";
        }
    }
}

// CPUのターン
void Game::CpuTurn()
{
    cout << "============================\n";
    cout << "        CPUのターン\n";
    cout << "============================\n\n";

    while (true)
    {
        int cpuTotal = cpu.GetTotal();
        int playerTotal = player.GetTotal();

        cout << "CPUの合計: " << cpuTotal << "\n";

        // CPUが21
        if (cpuTotal == WIN_SCORE)
        {
            cout << "CPUは21になりました。\n";
            return;
        }

        // CPUがバースト
        if (cpuTotal >= BURST_SCORE)
        {
            cout << "CPUはバーストしました\n";
            return;
        }

        // CPUがカードを引く
        if (cpu.ShouldDraw(playerTotal))
        {
            int card = DrawCard();

            cpu.AddCard(card);

            cout << "CPUは " << card << " を引きました\n\n";
        }
        else
        {
            cout << "CPUはカードを引きません\n\n";
            return;
        }
    }
}

void Game::ShowPlayer()
{
    cout << "Playerのカード: ";

    for (int i = 0; i < player.GetCardCount(); i++)
    {
        cout << player.GetCard(i) << " ";
    }

    cout << "\n";
}

void Game::ShowCpu()
{
    cout << "CPUのカード: ";

    for (int i = 0; i < cpu.GetCardCount(); i++)
    {
        cout << cpu.GetCard(i) << " ";
    }

    cout << "\n";
}
// 勝敗判定
void Game::Judge()
{
    int playerTotal = player.GetTotal();
    int cpuTotal = cpu.GetTotal();

    cout << "\n";
    cout << "============================\n";
    cout << "          最終結果\n";
    cout << "============================\n\n";

    ShowPlayer();
    ShowCpu();

    cout << "\n";

    cout << "Player : " << playerTotal << "\n";
    cout << "CPU    : " << cpuTotal << "\n\n";

    // Playerがバースト
    if (playerTotal >= BURST_SCORE)
    {
        cout << "PLAYERのバースト\n";
        cout << "CPUの勝ちです\n\n";
    }

    // CPUがバースト
    else if (cpuTotal >= BURST_SCORE)
    {
        cout << "CPUのバースト\n";
        cout << "PLAYERの勝ちです\n\n";
    }

    // 引き分け
    else if (playerTotal == cpuTotal)
    {
        cout << "引き分けです\n";
    }

    // Player勝利
    else if (playerTotal > cpuTotal)
    {
        cout << "Playerの勝ちです\n";
    }

    // CPU勝利
    else
    {
        cout << "CPUの勝ちです\n";
    }
}