#ifndef MINESWEEPERGAME_H
#define MINESWEEPERGAME_H


#include <iostream>
using namespace std;

struct Cell // Structure to represent each cell
{
   bool hasMine; //True if the cell contains a mine
   bool revealed;//True if the player reveals the cell
   bool hasFlag; //True if the player puts a flag on a cell
   int MinesNear; //Number of mines around the selected cell
};

//Global variables (can be used on all functions)
extern int SIZE; //Board size (6x6)
extern int Mines_Number; //Number of mines around the board
extern Cell grid[6][6]; // Game board (array for 36 cells)
extern bool GameOver; // True when the game ends(win or lose)
extern bool Victory;//True when the player wins

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