#include "Board.hpp"
#include <iostream>

using namespace std;
int main(){
  cout << "Hello from main.\n";
  Board *board = new Board(5,5,2);
  board->print();
  return 0;
}
