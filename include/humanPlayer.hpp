#include "../include/player.hpp"
#pragma once

class HumanPlayer : public Player {
  public:
    HumanPlayer();
    void takeTurn(Board* opponentBoard);
    void doInitialShipPlacements();
};
