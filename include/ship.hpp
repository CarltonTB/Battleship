#pragma once

class Ship{
  public:
    int hp;
    int length;
    void takeHit();
    bool isSunk();
    Ship();
    Ship(int initialHp, int intitialLength);
};
