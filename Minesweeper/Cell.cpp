#include <iostream>
#include "Cell.hpp"

Cell::Cell(){
  isMine = false;
  isFlagged = false;
  display = '-';
  proximity=0;
}

Cell::Cell(char disp){
  isMine = false;
  isFlagged = false;
  display = disp;
  proximity = 0;
  std::cout << "Display set to:" << disp << "\nWhat was actually set:" << display << "\n\n";
}

Cell::Cell(bool mined){
  isMine = mined;
  isFlagged = false;
  display = '-';
  proximity = 0;
}

Cell::Cell(bool mined, bool flagged){
  isMine = mined;
  isFlagged = flagged;
  display = '-';
  proximity = 0;
}

char Cell::test(){
  if (this->isFlagged)
    display = 'f';
  else if (this->isMine)
    display = 'x';
  else
    display = this->proximity;

  return display;
}

void Cell::mine(){
  this->isMine = !(this->isMine);
}

void Cell::flag(){
  this->isFlagged = !(this->isFlagged);
}

void Cell::incProximity(){
  this->proximity++;
}
