#include "../include/action.hpp"
#include "../include/coordinates.hpp"
#include "../include/board.hpp"
#include <cmath>



Action::Action(){
  shotCoordinates = Coordinates(-1,-1) ;
  targetBoard = nullptr;
  shotHit = false;
}

Action::Action(Coordinates coordinates, Board *board){
  int correctedY = std::abs(9 - coordinates.y);
  Coordinates correctedCoords(coordinates.x,correctedY);
  shotCoordinates = correctedCoords;
  targetBoard = board;
  shotHit = false;
}

void Action::takeAction(){
  targetBoard->board[shotCoordinates.y][shotCoordinates.x].firedUpon=true;
  if(targetBoard->board[shotCoordinates.y][shotCoordinates.x].ship!=nullptr){
    targetBoard->board[shotCoordinates.y][shotCoordinates.x].ship->takeHit();
    shotHit=true;
  }
}
