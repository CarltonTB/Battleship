#include <iostream>
#include <string>
#include <vector>
#include <stddef.h>
#include "../include/utils.hpp"
#include "../include/ship.hpp"
#include "../include/space.hpp"
#include "../include/board.hpp"
#include "../include/coordinates.hpp"
#include "../include/game.hpp"
#include "../include/humanPlayer.hpp"
#include "../include/action.hpp"
#include <cstdlib>

using namespace std;

int main() {
  // vector<int> v;
  // Ship myShip("hello world",4);
  // Ship *myShipPtr = &myShip;
  // myShip.takeHit();
  // Space mySpace;
  // Board board(10,10);
  // Coordinates coordinates(0,3);
  //
  // board.placeShip(myShipPtr, coordinates, "south");
  // cout << mySpace.isEmpty() << endl;
  // cout << myShip.hp << endl;
  // cout << board.printPlayerBoardState() << endl;
  //
  // cout << board.isValidPlacement(myShipPtr, coordinates, "north") << endl;
  // cout << board.isValidPlacement(myShipPtr, coordinates, "south") << endl;
  // cout << board.isValidPlacement(myShipPtr, coordinates, "east") << endl;
  // cout << board.isValidPlacement(myShipPtr, coordinates, "west") << endl;
  // cout << board.ships[0].name << endl;
  // cout << board.allShipsSunk() << endl;
  //
  // vector<string> tokens = stringCommaTokenize("hello,world");
  //
  // cout << tokens[0] << endl;
  // cout << tokens[1] << endl;
  // Game game = Game();
  // game.initializeGame();
  // game.player2->doInitialShipPlacements();
  // int xCoord = rand()%10;
  // int yCoord = rand()%10;
  // Coordinates targetCoords(xCoord,yCoord);
  // Action* action = new Action(targetCoords,game.player2->board);
  // action->takeAction();
  // cout << game.player2->board->printPlayerBoardState() << endl;


  // Initializing, setting up, and playing the game:
  Game game = Game();
  game.initializeGame();
  bool startGame = game.setupGameBoards();
  if(startGame){
    game.playGame();
  } else {
    return 0;
  }
}
