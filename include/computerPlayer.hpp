#include "../include/player.hpp"
#pragma once

class ComputerPlayer : public Player {
  public:
    bool isSmartOpponent;
    ComputerPlayer();
    void takeTurn(Board* opponentBoard);
    void doInitialShipPlacements();
};
