#include "../include/player.hpp"
#include "../include/board.hpp"


Player::Player(){
  Board* initBoard = new Board(10,10);
  board = initBoard;
}
