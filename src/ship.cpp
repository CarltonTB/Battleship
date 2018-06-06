#include "../include/ship.hpp"

void Ship::takeHit(){
  hp--;
}

bool Ship::isSunk(){
  return hp <= 0;
}

Ship::Ship(){
  hp = 0;
  length = 0;
  name="";
}

Ship::Ship(int initialHp, int intitialLength){
  hp = initialHp;
  length = intitialLength;
  name="";
}

Ship::Ship(string shipName, int initialHp, int intitialLength){
  hp = initialHp;
  length = intitialLength;
  name=shipName;
}
