#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "Board.hpp"

Board::Coords Board::generateMine(int maxX, int maxY){
  Coords newMine;
  int xCoord, yCoord;

  newMine.x = rand() % maxX;
  newMine.y = rand() % maxY;

  return newMine;
}

bool Board::validateMine(Board::Coords toValidate){
  bool isValid = false;

  if(numMines == 0) // No mines
    return true;

  // If we cannot find the mine coordinate in the vector
  if(find(this->mines.begin(), this->mines.end(), toValidate) == this->mines.end()){
    // TODO: if mines are in a block, return false (poor game condition)
    return true;
  }
  else {
    return false;
  }

  return isValid;
}

Board::Board(int sizeX, int sizeY, int mines)
{
  // TODO: input validation

  // Set random number generator seed
  srand(time(NULL));

  struct Board::Coords coordinate;
  for (int i=1; i<=mines; i++)
  {
      do {
        coordinate = generateMine(sizeX, sizeY);
      } while(!this->validateMine(coordinate));

      this->mines.push_back(coordinate);
  }
}

void Board::print(){
  std::cout << "Hello from Board.";
}
