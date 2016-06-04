#include "Cell.hpp"

Cell::Cell(bool mined){
  isMine = mined;
  display = '-';
}

Cell::Cell(bool mined, bool flagged){
  isMine = mined;
  isFlagged = flagged;
  display = '-';
}

char Cell::test(){
  if (this->isFlagged)
    display = 'f';
  else if (this->isMined)
    display = 'x'
  else
    display = this->numNearMines;

  return display;
}

void Cell::mine(){
  this->isMined = !(this->isMined);
}

void Cell::flag(){
  this->isFlagged = !(this->isFlagged);
}
