#include "../include/board.hpp"
#include "../include/coordinates.hpp"
#pragma once

class Action{
  public:
    Coordinates shotCoordinates;
    Board *targetBoard;
    bool shotHit;
    Action();
    Action(Coordinates coordinates, Board *board, bool hit);
    //Player performingPlayer;
};
