#include "../include/action.hpp"
#include "../include/coordinates.hpp"
#include "../include/board.hpp"



Action::Action(){
  shotCoordinates = Coordinates(-1,-1) ;
  targetBoard = nullptr;
  shotHit = false;
}

Action::Action(Coordinates coordinates, Board *board, bool hit){
  shotCoordinates = coordinates;
  targetBoard = board;
  shotHit = hit;
}