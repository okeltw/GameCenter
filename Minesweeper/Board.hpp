#ifndef __Board
#define __Board

#include <vector>
#include "Cell.hpp"

class Board
{
public:
  Board(int, int, int);
  ~Board();

  // Package for x,y coordinates for the cells
  struct Coords {
    int x;
    int y;
  };

  std::vector<std::vector<Cell*>> gameBoard; // What the player sees
  int flagsRemaining;                       // Number of flags remaining (= number of mines at start)
  int numMines;                             // Number of mines hidden in the board

  int test(Coords); // Used to test (click) a coordinate.
  int flag(Coords); // Used to flag a coordinate.
  void print();     // Prints the playing gameBoard.
  void printFull(); // Prints the full board.

private:
  std::vector<Coords> mines;                // A list of mine coordinates

  void generateMines(int,int, int);      // Generates the mines
  bool validateMine(Coords);  // Validates that a given mine coordinate is correct

  // Dimensions
  int maxX;
  int maxY;
};
#endif /* end of include guard:  */
