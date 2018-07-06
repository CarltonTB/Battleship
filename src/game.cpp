#include "../include/game.hpp"

bool Game::gameOver(){
  return (this->player1->board->allShipsSunk()) || (this->player2->board->allShipsSunk());
}

void Game::initializeGame(){
  //TODO: write this method

}

void Game::startGame(){
  //TODO: write this method

}

void Game::endGame(){
  //TODO: write this method

}
