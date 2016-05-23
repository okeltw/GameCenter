# GameCenter
Basic versions of games (self-written -- not downloaded), with the intent to write scripts to automatically solve them.


## Minesweeper
A classic game where the player is presented with a board size of their choosing and the goal of finding all of the "mines" (number of mines also submitted by user). The game is played by testing cells, which then provide information to the number of nearby mines. Testing a cell that has a mine results in failing the game.  Flags mark potential spots for mines, improving game experience.  The player wins when the number of untested spots (flagged or not) is equal to the set number of mines; that is, when all the mines have been identified.

### The Board
* - : An untested cell.
* 0 through 8 : the number of adjacent mines. The game will automatically expand adjacent cells when the number is zero.
* f : A flag.
* x : a mine. Finding this results in game loss.

### Commanding the game
* Use the provided UI to start a new game.  Use the subsequent options to configure to the desired difficulty.
* The matrix will then appear (all '-'s at this point)
* The following commands interact with the board:
  - t(x,x) : test cell at coordinate x,x.
  - f(x,x) : flag coordinate x,x.
  - concede : give up, and see the final board.

### Nerdy Stuff
[TODO - Expound, after the game is written]
This section contains the logic of the objects that make up the game.


#### The Board Object
A simple gameboard. Provides testing and flagging functionality.

#### The Minesweeper Object
Extends the board into a UI.  Provides new game, scorekeeping, and other functions.
