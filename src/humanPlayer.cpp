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
    bool validShipPlacement = false;
    while(!validShipPlacement){
      string coords;
      string direction;
      cout << "<Placing " + ship.name + " (length " + to_string(ship.length)+")>" << endl;
      cout << "Enter coordinates in the form: x,y for the desired position of the ship" << endl;
      cin >> coords;
      //TODO: validate coordinates in a loop
      cout << "Enter a heading direction for the ship (north, south, east, or west)" << endl;
      cin >> direction;
      //TODO: validate direction in a loop
      //if everything is valid, place the ship
      vector<string> tokenizeCoords = stringCommaTokenize(coords);
      Coordinates placementCoordinates(stoi(tokenizeCoords[0]),stoi(tokenizeCoords[1]));
      validShipPlacement = board->placeShip(&ship, placementCoordinates, direction);
      if(validShipPlacement){
        cout << "" << endl;
        cout << board->printPlayerBoardState() << endl;
        cout << "" << endl;
      } else {
        cout << "Placement location was invalid, please choose a different location" << endl;
      }
    }
  }
}
