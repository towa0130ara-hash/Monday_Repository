#pragma once

//カードの種類
const int MIN_CARD_VALUE = 1;
const int MAX_CARD_VALUE = 11;

//同じ数字のカードの枚数
const int SAME_CARD_COUNT = 4;

//カードの総枚数
const int DECK_SIZE = 44;

//最初に配るカード枚数
const int INITIAL_CARD_COUNT = 2;

// 勝利条件
const int WIN_SCORE = 21;

// バーストする点数
const int BURST_SCORE = 22;

// CPUが必ずカードを引く点数
const int CPU_DRAW_SCORE = 15;
