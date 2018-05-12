#include "../include/ship.hpp"

void Ship::takeHit(){
  hp--;
}

Ship::Ship(int initialHp, int intitialLength){
  hp = initialHp;
  length = intitialLength;
}
