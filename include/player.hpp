#include "../include/board.hpp"
#include "../include/action.hpp"
#include "../include/coordinates.hpp"
#include <vector>
#include <string>
using std::vector;
using std::string;
#pragma once

class Player{
  public:
    vector<Action> actionHistory;
    Board *board;
    Player(Board *initBoard);
};
