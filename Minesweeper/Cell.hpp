#ifndef __Cell
#define __Cell

class Cell {
public:
  Cell();           // Blank cell
  Cell(char);       // Blank cell with set display (DEBUG)
  Cell(bool);       // Set mine
  Cell(bool,bool);  // Set mine, flag

  char test();
  void flag();
  char display;
  void mine();
  void incProximity();

  bool isMine;
  bool isFlagged;
  int  proximity;
};

#endif
