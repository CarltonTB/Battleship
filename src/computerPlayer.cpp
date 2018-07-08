#include "../include/computerPlayer.hpp"
#include "../include/coordinates.hpp"
#include <cstdlib>

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
  bool validShipPlacement = false;
  for(Ship ship : shipList){
    while(!validShipPlacement){
      xCoord = rand()%10;
      yCoord = rand()%10;
      direction = getRandomCompassDirection();
      Coordinates placementCoordinates(xCoord,yCoord);
      validShipPlacement = board->placeShip(&ship, placementCoordinates, direction);
    }
  }
}
