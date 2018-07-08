#include "../include/computerPlayer.hpp"
#include "../include/coordinates.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::stoi;
using std::to_string;


ComputerPlayer::ComputerPlayer(){
  Board* initBoard = new Board(10,10);
  board = initBoard;
  isSmartOpponent = false;
}

void ComputerPlayer::takeTurn(){

}

void ComputerPlayer::doInitialShipPlacements(){
  int xCoord, yCoord;
  string direction;
  bool validShipPlacement;
  for(Ship *ship : shipList){
    cout << ship->name + " (length " + to_string(ship->length)+")" << endl;
  }
  for(Ship *ship : shipList){
    validShipPlacement = false;
    while(!validShipPlacement){
      xCoord = rand()%10;
      yCoord = rand()%10;
      direction = getRandomCompassDirection();
      Coordinates placementCoordinates(xCoord,yCoord);
      validShipPlacement = board->placeShip(ship, placementCoordinates, direction);
      cout << "placement attempt" << endl;
    }
  }
}
