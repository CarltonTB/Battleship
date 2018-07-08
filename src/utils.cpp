#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using std::string;
using std::vector;
using std::stringstream;
using std::cout;
using std::endl;
using std::stoi;
#include <cstdlib>

/*
This file is for misc. utility functions.
*/

vector<string> stringCommaTokenize(string str){
  vector<string> result;
  stringstream ss(str);

  while(ss.good()){
    string substr;
    getline(ss,substr,',' );
    result.push_back(substr);
  }
  return result;
}

bool validateCoordinatesFromUser (string coords){
  bool valid = true;
  vector<string> tokenizedCoords = stringCommaTokenize(coords);
  if(coords.length() != 3 || tokenizedCoords.size() != 2){
    return false;
  }
  if(stoi(tokenizedCoords[0]) < 0 || stoi(tokenizedCoords[0]) > 9){
    valid = false;
  }
  if(stoi(tokenizedCoords[1]) < 0 || stoi(tokenizedCoords[1]) > 9){
    valid = false;
  }
  return valid;
}

bool validateDirectionFromUser(string direction){
  return (direction == "north") || (direction == "south") || (direction == "east") || (direction == "west");
}

string getRandomCompassDirection(){
  int random = (rand()%10)/3;
  string dir;
  if(random == 0){
    dir = "north";
  }
  else if(random == 1){
    dir = "south";
  }
  else if(random == 2){
    dir = "east";
  }
  else{
    dir = "west";
  }
  return dir;
}
