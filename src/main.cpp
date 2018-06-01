#include <iostream>
#include <string>
#include <vector>
#include <stddef.h>
#include "../include/utils.hpp"
#include "../include/ship.hpp"
#include "../include/space.hpp"
#include "../include/board.hpp"
#include "../include/coordinates.hpp"
using namespace std;

int main() {
  cout << "Hello world!" << endl;
  //cout << addInts(1,1) << endl;
  //vector<vector<int>> v;
  vector<int> v;
  Ship myShip(4,3);
  Ship *myShipPtr = &myShip;
  myShip.takeHit();
  Space mySpace;
  Board board(10,10);
  Coordinates coordinates(0,3);

  board.placeShip(myShipPtr, coordinates, "south");
  cout << mySpace.isEmpty() << endl;
  cout << myShip.hp << endl;
  cout << board.printState() << endl;

  cout << board.isValidPlacement(myShipPtr, coordinates, "north") << endl;
  cout << board.isValidPlacement(myShipPtr, coordinates, "south") << endl;
  cout << board.isValidPlacement(myShipPtr, coordinates, "east") << endl;
  cout << board.isValidPlacement(myShipPtr, coordinates, "west") << endl;




  // int i;
  // cout << "Please enter an integer value: ";
  // cin >> i;
  // cout << "The value you entered is " << i;
  // cout << " and its double is " << i*2 << ".\n";
  return 0;
}
