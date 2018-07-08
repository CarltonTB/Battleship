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
  // HumanPlayer* p1 = new HumanPlayer();
  // ComputerPlayer* p2 = new ComputerPlayer();
  player1=new HumanPlayer();
  player2=new ComputerPlayer();
}

bool Game::gameOver(){
  return (this->player1->board->allShipsSunk()) || (this->player2->board->allShipsSunk());
}

void Game::initializeGame(){
  //Read from the ships.txt file and setup each players ship list
  string line;
  ifstream myfile ("ships.txt");
  if (myfile.is_open()){
    while (getline(myfile,line) ){
      vector<string> tokenized = stringCommaTokenize(line);
      player1->shipList.push_back(new Ship(tokenized[0],stoi(tokenized[1])));
      player2->shipList.push_back(new Ship(tokenized[0],stoi(tokenized[1])));
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


bool Game::setupGameBoards(){
  cout << "                             ";
  cout << "Welcome to Battleship!" << endl;
  cout << "" << endl;
  this->printShipArt();
  //TODO: implement the below methods
  cout << "\n" << endl;
  cout << "Enter 'start' to being playing the game, or enter any other input to quit the game" << endl;
  string input;
  cin >> input;
  if(input == "start"){
    player1->doInitialShipPlacements();
    player2->doInitialShipPlacements();
    return true;
  }
  else{
    return false;
  }
}

void Game::playGame(){
  // uncomment the below line when playing for real and not developing/testing
  // cout << player2.board->printOpponentBoardState() << endl;
  cout << player2->board->printPlayerBoardState() << endl;
  cout << player1->board->printPlayerBoardState() << endl;
  while(!gameOver()){
    player1->takeTurn(player2->board);
    player2->takeTurn(player1->board);
    cout << player2->board->printPlayerBoardState() << endl;
    cout << player1->board->printPlayerBoardState() << endl;
    // for(Ship* ship : player2->board->ships){
    //   cout << "Ship name:" + ship->name + " | HP: " << ship->hp << endl;
    // }
  }
  endGame();
}

void Game::endGame(){
  //TODO: write this method
  //free up all allocated memory, end the program


}
