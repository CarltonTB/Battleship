#include "../include/computerPlayer.hpp"

ComputerPlayer::ComputerPlayer(){
  Board* initBoard = new Board(10,10);
  board = initBoard;
  isSmartOpponent = false;
}

void ComputerPlayer::takeTurn(){

}

void ComputerPlayer::doInitialShipPlacements(){

}
