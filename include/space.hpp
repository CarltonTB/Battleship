#include "../include/ship.hpp"
#pragma once

class Space{
  public:
    bool firedUpon;
    Ship* ship; // == nullptr if there is no ship occupying the space
    bool isEmpty();
    bool shipWasHit();
    Space();
    Space(Ship *occupant);
};
