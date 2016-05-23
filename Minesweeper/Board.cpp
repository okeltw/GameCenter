#include <iostream>
#include "Board.hpp"

Coords generateMine();      // Generates a mine coordinate
bool validateMine(Coords);  // Validates that a given mine coordinate is correct

Board::Board(int sizeX, int sizeY, int mines){
  // TODO: input validation

  for (int i=1; i<=mines; i++){

  }
}

void Board::print(){
  std::cout << "Hello from Board.";
}
