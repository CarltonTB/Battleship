#include "../include/space.hpp"
#include "../include/board.hpp"
#include "../include/coordinates.hpp"
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::string;

Board::Board(int width, int height){
  vector<vector<Space>> initializedBoard;
  for(int i = 0; i < height; i++){
    vector<Space> boardRow;
    for(int j = 0; j < width; j++){
      Space space;
      boardRow.push_back(space);
    }
    initializedBoard.push_back(boardRow);
  }
  xDimension = width;
  yDimension = height;
  board = initializedBoard;
}

bool Board::isValidPlacement(Ship *ship, Coordinates startCoordinates, string direction){
  bool valid = false;
  int distanceToTop = std::abs(this->yDimension - startCoordinates.y + 1);
  int distanceToBot = startCoordinates.y + 1;
  int distanceToRight = std::abs(this->xDimension - startCoordinates.x + 1);
  int distanceToLeft = startCoordinates.x + 1;
  if(direction == "north"){
    if(ship->length <= distanceToTop){
      valid = true;
    }
  }
  else if(direction == "south"){
    if(ship->length <= distanceToBot){
      valid = true;
    }
  }
  else if(direction == "east"){
    if(ship->length <= distanceToRight){
      valid = true;
    }
  }
  else if(direction == "west"){
    if(ship->length <= distanceToLeft){
      valid = true;
    }
  }
  if(!valid){
    cout << "You can't place a ship there!" << endl;
  }
  return valid;
}

bool Board::placeShip(Ship *ship, Coordinates startCoordinates, string direction){
  //Returns true if it was successful, false if it fails
  bool isValidPlacement = this->isValidPlacement(ship, startCoordinates, direction);
  bool wasPlaced = false;
  int yPlacement = std::abs(this->yDimension-1 - startCoordinates.y);
  int xPlacement = startCoordinates.x;
  if(isValidPlacement){
    //place the ship
    if(direction == "north"){
      for(int i = 0; i<ship->length; i++){
        board[yPlacement-i][xPlacement].ship = ship;
      }
      wasPlaced = true;
      ships.push_back(*ship);
    }
    else if(direction == "south"){
      for(int i = 0; i<ship->length; i++){
        board[yPlacement+i][xPlacement].ship = ship;
      }
      wasPlaced = true;
      ships.push_back(*ship);
    }
    else if(direction == "east"){
      for(int i = 0; i<ship->length; i++){
        board[yPlacement][xPlacement+i].ship = ship;
      }
      wasPlaced = true;
      ships.push_back(*ship);
    }
    else if(direction == "west"){
      for(int i = 0; i<ship->length; i++){
        board[yPlacement][xPlacement-i].ship = ship;
      }
      wasPlaced = true;
      ships.push_back(*ship);
    }
  }
  return wasPlaced;
}

string Board::printPlayerBoardState(){
  //Print the state of the board
  string boardState;
  boardState += "          ";
  boardState += "Y";
  boardState += "\n\n";
  int j = yDimension-1;
  for(vector<Space> row : board){
    //Add the y axis coordinates on the side of the board
    boardState += "          ";
    boardState += std::to_string(j);
    boardState += "  ";
    for(Space space : row){
      if(space.isEmpty() && !space.firedUpon){
        boardState += ". ";
      }
      else if(space.shipWasHit()){
        boardState += "X ";
      }
      else if(!space.isEmpty() && !space.firedUpon){
        boardState += "O ";
      }
      else if(space.isEmpty() && space.firedUpon){
        boardState += "* ";
      }
      else{
        boardState += "INVALID BOARD STATE";
      }
    }
    j--;
    boardState += "\n";
  }
  //Add the x axis coordinates on the bottom of the board
  boardState += "\n";
  boardState += "             ";
  for(int i = 0; i < xDimension; i++){
    boardState += std::to_string(i);
    boardState += " ";
  }
  boardState += " X";
  boardState += "\n";
  return boardState;
}

string Board::printOpponentBoardState(){
  //Print the state of the board, but only show spaces where you have fired
  string boardState;
  boardState += "          ";
  boardState += "Y";
  boardState += "\n\n";
  int j = yDimension-1;
  for(vector<Space> row : board){
    //Add the y axis coordinates on the side of the board
    boardState += "          ";
    boardState += std::to_string(j);
    boardState += "  ";
    for(Space space : row){
      if(space.shipWasHit()){
        boardState += "X ";
      }
      else if(space.isEmpty() && space.firedUpon){
        boardState += "* ";
      }
      else{
        boardState += ". ";
      }
    }
    j--;
    boardState += "\n";
  }
  //Add the x axis coordinates on the bottom of the board
  boardState += "\n";
  boardState += "             ";
  for(int i = 0; i < xDimension; i++){
    boardState += std::to_string(i);
    boardState += " ";
  }
  boardState += " X";
  boardState += "\n";
  return boardState;
}

bool Board::allShipsSunk(){
  bool allSunk = true;
  for(Ship ship : ships){
    if(ship.hp > 0){
      allSunk = false;
    }
  }
  return allSunk;
}
