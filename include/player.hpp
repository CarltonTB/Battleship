#include "../include/board.hpp"
#include "../include/action.hpp"
#include "../include/coordinates.hpp"
#include "../include/ship.hpp"
#include <vector>
#include <string>
using std::vector;
using std::string;
#pragma once

class Player{
  public:
    vector<Action> actionHistory;
    vector<Ship> shipList;
    Board *board;
    Player();
};
