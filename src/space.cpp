#include "../include/space.hpp"

Space::Space(){
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
