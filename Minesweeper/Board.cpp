#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <time.h>

#include "Board.hpp"
#include "Cell.hpp"

using namespace std;

void Board::generateMines(int sizeX, int sizeY, int mines){
  int mineCoordX, mineCoordY;
  Cell *toMine;
  for (int mine = 0; mine < mines; mine++){
    do{
      mineCoordX = rand() % sizeX;
      mineCoordY = rand() % sizeY;
      toMine = this->gameBoard[mineCoordX][mineCoordY];
    }while(toMine->isMine); // loop until the coordinate is no longer mined
    toMine->mine();

    int proxSetXMin = mineCoordX == 0 ? 0 : mineCoordX-1;
    int proxSetXMax = mineCoordX == sizeX-1 ? sizeX : mineCoordX+2;

    int proxSetYMin = mineCoordY == 0 ? 0 : mineCoordY-1;
    int proxSetYMax = mineCoordY == sizeY-1 ? sizeY : mineCoordY+2;

    for(int proxSetY = proxSetYMin; proxSetY < proxSetYMax; proxSetY++){
      for (int proxSetX = proxSetXMin; proxSetX < proxSetXMax; proxSetX++){
        this->gameBoard[proxSetX][proxSetY]->incProximity();
      }
    }
  }
}

// For each coordinate
//    Create a new Cell, assign it to the boards
// For each mine
//    Generate random coordinates
//    Tell cell it is a mine
//    increment the proximity of adjacent cells

Board::Board(int sizeX, int sizeY, int mines){
  // Store values
  this->maxX = sizeX;
  this->maxY = sizeY;
  this->numMines = mines;

  // Instantiate board
  vector<Cell*> column;
  for (int xCoord = 0; xCoord < sizeX; xCoord++){
    column.clear();
    for (int yCoord = 0; yCoord < sizeY; yCoord++){
      string temp = to_string(yCoord);
      Cell *newCell = new Cell();
      column.push_back(newCell);
    }
    this->gameBoard.push_back(column);
  }

  // Initialize seed
  srand (time(NULL));

  // Place mines
  generateMines(sizeX, sizeY, mines);
}

void Board::print(){
  for (int yCoord = 0; yCoord < maxY; yCoord++){
    for (int xCoord = 0; xCoord < maxX; xCoord++){
      cout << this->gameBoard[xCoord][yCoord]->display;
    }
    cout << endl;
  }
}

void Board::printFull(){
  Cell *toPrint;
  for (int yCoord = 0; yCoord < maxY; yCoord++){
    for (int xCoord = 0; xCoord < maxX; xCoord++){
      toPrint = this->gameBoard[xCoord][yCoord];
      if (toPrint->isMine)
        cout << 'x';
      else if (toPrint->isFlagged)
        cout << 'f';
      else
        cout << toPrint->proximity;
    }
    cout << endl;
  }
}

Board::~Board(){
  for (int yCoord = 0; yCoord < maxY; yCoord++){
    for (int xCoord = 0; xCoord < maxX; xCoord++){
      delete this->gameBoard[xCoord][yCoord];
    }
  }
}
