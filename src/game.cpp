#include "../include/game.hpp"
#include "../include/computerPlayer.hpp"
#include "../include/humanPlayer.hpp"
#include "../include/utils.hpp"
#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::stoi;

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
    while (getline(myfile,line) ){
      vector<string> tokenized = stringCommaTokenize(line);
      player1.shipList.push_back(Ship(tokenized[0],stoi(tokenized[1])));
      player2.shipList.push_back(Ship(tokenized[0],stoi(tokenized[1])));
    }
    myfile.close();
  }
  else{
    cout << "Error: unable to open ships.txt file\n";
  }
}

void Game::printShipArt(){
  string line;
  ifstream myfile ("shipArt.txt");
  if (myfile.is_open()){
    while (getline(myfile,line) ){
      cout << line << endl;
    }
    myfile.close();
  }
  else{
    cout << "Error: unable to open shipArt.txt file\n";
  }
}


void Game::startGame(){
  //TODO: write this method
  cout << "                             ";
  cout << "Welcome to Battleship!" << endl;
  cout << "" << endl;
  this->printShipArt();
  //TODO: implement the below methods
  player1.doInitialShipPlacements();
  player2.doInitialShipPlacements();


}

void Game::endGame(){
  //TODO: write this method

}
