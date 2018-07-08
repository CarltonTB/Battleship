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
      bool validCoords = false;
      bool validDirection = false;
      cout << "<Placing " + ship.name + " (length " + to_string(ship.length)+")>" << endl;
      while(!validCoords){
        cout << "Enter coordinates in the form: x,y for the desired position of the ship" << endl;
        cin >> coords;
        validCoords = validateCoordinatesFromUser(coords);
      }
      while(!validDirection){
        cout << "Enter a heading direction for the ship in all lowercase (north, south, east, or west)" << endl;
        cin >> direction;
        validDirection = validateDirectionFromUser(direction);
      }
      //if everything is valid, place the ship
      vector<string> tokenizedCoords = stringCommaTokenize(coords);
      Coordinates placementCoordinates(stoi(tokenizedCoords[0]),stoi(tokenizedCoords[1]));
      validShipPlacement = board->placeShip(&ship, placementCoordinates, direction);
      if(validShipPlacement){
        cout << "" << endl;
        cout << board->printPlayerBoardState() << endl;
        cout << "" << endl;
      } else {
        cout << "Your chosen placement location was invalid. Please choose a different location" << endl;
      }
    }
  }
}
