#ifndef __Cell
#define __Cell

class Cell {
public:
  Cell(bool);       // Set mine
  Cell(bool,bool);  // Set mine, flag

  char test();
  void flag();
  char display;

protected:
  void mine();

private:
  struct Proximity {
    bool mineNW;
    bool mineN;
    bool mineNE;
    bool mineE;
    bool mineSE;
    bool mineS;
    bool mineSW;
    bool mineW;
  };

  bool isMine;
  bool isFlagged;
  int numNearMines;
}

#endif
