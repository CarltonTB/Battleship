#include "../include/coordinates.hpp"
#include "../include/board.hpp"
#include "../include/coordinates.hpp"
#pragma once

class Action{
  public:
    Coordinates shotCoordinates;
    Board *targetBoard;
    Action();
    //Player performingPlayer;
};
