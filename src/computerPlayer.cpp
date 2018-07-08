#include "../include/computerPlayer.hpp"
#include "../include/coordinates.hpp"
#include "../include/action.hpp"
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

void ComputerPlayer::takeTurn(Board* opponentBoard){
  if(!isSmartOpponent){
    int xCoord = rand()%10;
    int yCoord = rand()%10;
    //action action with the random coordinates
    Coordinates targetCoords(xCoord,yCoord);
    Action* action = new Action(targetCoords,opponentBoard);
    action->takeAction();
    actionHistory.push_back(action);
  }
}

void ComputerPlayer::doInitialShipPlacements(){
  int xCoord, yCoord;
  string direction;
  bool validShipPlacement;
  for(Ship *ship : shipList){
    validShipPlacement = false;
    while(!validShipPlacement){
      xCoord = rand()%10;
      yCoord = rand()%10;
      direction = getRandomCompassDirection();
      Coordinates placementCoordinates(xCoord,yCoord);
      validShipPlacement = board->placeShip(ship, placementCoordinates, direction);
    }
  }
}
