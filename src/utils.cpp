#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using std::string;
using std::vector;
using std::stringstream;
using std::cout;
using std::endl;
/*
This file is for misc. utility functions.
*/
int addInts(int x, int y){
  return x+y;
}

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
