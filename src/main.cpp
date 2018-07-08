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
#include <ctime>

using namespace std;

int main() {
  srand(time(0));
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
