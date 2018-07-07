#include "../include/player.hpp"
#include "../include/board.hpp"


Player::Player(){
  Board initBoard = Board(10,10);
  board = &initBoard;
}
