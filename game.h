#pragma once
#include <algorithm>
#include <tuple>
#include <vector>
#include "board.h"
#include "ai.h"
#include "common.h"

typedef std::vector<Board> BoardHistory;

class Game
{
public:
    Board board;

private:
    int player; // 1 = White vs Ai, -1 = Black vs Ai
    BoardHistory *boardhistory = new BoardHistory();
    Ai ai;

public:
    Game(int player);
    ~Game();

private:
    void gameLoop();
    void undoMove();
    std::tuple<bool, Move> trySelect(int row, int col, Move move);
    void reset();
    std::tuple<bool, Move> returnIfOnlyMove(const Move &move);
};