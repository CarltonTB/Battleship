#include <iostream>
#include <string>
#include "../include/utils.hpp"
#include "../include/ship.hpp"
using namespace std;

int main() {
  cout << "Hello world!" << endl;
  //cout << addInts(1,1) << endl;
  Ship myShip(2,5);
  myShip.takeHit();
  cout << myShip.hp << endl;
  // int i;
  // cout << "Please enter an integer value: ";
  // cin >> i;
  // cout << "The value you entered is " << i;
  // cout << " and its double is " << i*2 << ".\n";
  return 0;
}
