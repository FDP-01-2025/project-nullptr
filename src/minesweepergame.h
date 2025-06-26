#ifndef MINESWEEPERGAME_H
#define MINESWEEPERGAME_H

struct Cell // Structure to represent each cell
{
   bool hasMine; //True if the cell contains a mine
   bool revealed;//True if the player reveals the cell
   bool hasFlag; //True if the player puts a flag on a cell
   int MinesNear; //Number of mines around the selected cell
};

//Global variables (can be used on all functions)
int SIZE = 6; //Board size (6x6)
int Mines_Number = 8; //Number of mines around the board
Cell grid[6][6]; // Game board (array for 36 cells)
bool GameOver = false; // True when the game ends(win or lose)
bool Victory = false;//True when the player wins

//Declaration of functions

bool ValidCoordinates(int row, int col); 
int countMinesNear(int row, int col); 
void startGame();
void displayGrid(bool showMines);
void checkVictory();
void revealCell(int row, int col);
void toggleFlag(int row, int col);
void playGame();



#endif 