#include "../include/ship.hpp"
#pragma once

class Space{
  public:
    Ship* ship; //nullptr if there is no ship occupying it
    bool isEmpty();
    Space();
    Space(Ship *occupant);
};
