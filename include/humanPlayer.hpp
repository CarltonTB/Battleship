#include "../include/player.hpp"
#pragma once

class HumanPlayer : public Player {
  public:
    void takeTurn();
    void doInitialShipPlacements();
};
