#include "../include/player.hpp"


class Game{
  public:
    Player player1;
    Player player2;
    Game();
    bool gameOver();
    void initializeGame();
    void startGame();
    void endGame();

};
