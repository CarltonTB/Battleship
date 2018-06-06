#pragma once
#include <string>
using std::string;

class Ship{
  public:
    string name;
    int hp;
    int length;
    void takeHit();
    bool isSunk();
    Ship();
    Ship(int initialHp, int intitialLength);
    Ship(string name, int initialHp, int intitialLength);
};
