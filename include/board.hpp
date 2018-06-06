#include "../include/utils.hpp"
#include "../include/coordinates.hpp"
#include "../include/space.hpp"
#include "../include/ship.hpp"
#include <vector>
#include <string>
using std::vector;
using std::string;
#pragma once

class Board{
  public:
    vector<vector<Space>> board;
    vector<Ship> ships;
    int xDimension, yDimension;
    const vector<string> compass_directions = {"north", "south", "east", "west"};
    Board(int width, int height);
    bool isValidPlacement(Ship *ship, Coordinates startCoordinates, string direction);
    bool placeShip(Ship *ship, Coordinates startCoordinates, string direction);
    string printPlayerBoardState();
    string printOpponentBoardState();
    bool allShipsSunk();
};
