#include "../include/humanPlayer.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::stoi;

HumanPlayer::HumanPlayer(){
  Board* initBoard = new Board(10,10);
  board = initBoard;
}

void HumanPlayer::takeTurn(){

}

void HumanPlayer::doInitialShipPlacements(){
  cout << board->printPlayerBoardState() << endl;
}
