#include "../include/space.hpp"

Space::Space(){
  firedUpon=false;
  ship = nullptr;
}

Space::Space(Ship *occupant){
  ship = occupant;
}

bool Space::isEmpty(){
  if(ship == nullptr){
    return true;
  }
  else{
    return false;
  }
}

bool Space::shipWasHit(){
  return !this->isEmpty() && firedUpon;
}
