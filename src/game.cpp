#include "../include/game.hpp"
#include "../include/computerPlayer.hpp"
#include "../include/humanPlayer.hpp"
#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;

Game::Game(){
  player1 = HumanPlayer();
  player2 = ComputerPlayer();

}

bool Game::gameOver(){
  return (this->player1.board->allShipsSunk()) || (this->player2.board->allShipsSunk());
}

void Game::initializeGame(){
  //Read from the ships.txt file and setup each players ship list
  string line;
  ifstream myfile ("ships.txt");
  if (myfile.is_open()){
    while ( getline (myfile,line) ){
      cout << line << '\n';

    }
    myfile.close();
  }
  else{
    cout << "Unable to open file\n";
  }
}

void Game::startGame(){
  //TODO: write this method

}

void Game::endGame(){
  //TODO: write this method

}
