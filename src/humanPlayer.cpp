#include "../include/humanPlayer.hpp"
#include "../include/utils.hpp"
#include "../include/coordinates.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::stoi;
using std::to_string;

HumanPlayer::HumanPlayer(){
  Board* initBoard = new Board(10,10);
  board = initBoard;
}

void HumanPlayer::takeTurn(){

}

void HumanPlayer::doInitialShipPlacements(){
  cout << "" << endl;
  cout << "These are your ships:" << endl;
  for(Ship ship : shipList){
    cout << ship.name + " (length " + to_string(ship.length)+")" << endl;
  }
  cout << "" << endl;
  cout << board->printPlayerBoardState() << endl;
  for(Ship ship : shipList){
    string coords;
    string direction;
    cout << "<Placing " + ship.name + " (length " + to_string(ship.length)+")>" << endl;
    cout << "Enter coordinates in the form: x,y for the desired position of the ship" << endl;
    cin >> coords;
    //validate coordinates in a loop
    cout << "Enter a heading direction for the ship (north, south, east, or west)" << endl;
    cin >> direction;
    //validate direction in a loop
    //if everything is valid, place the ship
    vector<string> tokenizeCoords = stringCommaTokenize(coords);
    Coordinates placementCoordinates(stoi(tokenizeCoords[0]),stoi(tokenizeCoords[1]));
    board->placeShip(&ship, placementCoordinates, direction);
    cout << "" << endl;
    cout << board->printPlayerBoardState() << endl;
    cout << "" << endl;

  }

}
