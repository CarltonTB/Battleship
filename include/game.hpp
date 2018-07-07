#include "../include/computerPlayer.hpp"
#include "../include/humanPlayer.hpp"



class Game{
  public:
    HumanPlayer player1;
    ComputerPlayer player2;
    Game();
    bool gameOver();
    void initializeGame();
    void printShipArt();
    void startGame();
    void endGame();
};
