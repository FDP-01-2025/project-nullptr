#include "minesweepergame.h"
#include <cstdlib> // For random numbers
#include <ctime>   // For time functions


//Global variables (can be used on all functions)
int SIZE = 6; //Board size (6x6)
int Mines_Number = 8; //Number of mines around the board
Cell grid[6][6]; // Game board (array for 36 cells)
bool GameOver = false; // True when the game ends(win or lose)
bool Victory = false;//True when the player wins


bool ValidCoordinates(int row, int col) {
    // Checks if the given coordinates are valid
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE;
}

int countMinesNear(int row, int col) {
    // Function to count how many mines are near
    int counter = 0; // Start counting from 0 mines
    for (int i = -1; i <= 1; i++) {  // Check row above (-1), same row (0), row below (1)
        for (int j = -1; j <= 1; j++) {  // Check col left (-1), same col (0), col right (1)
            int newrow = row + i;  // Calculate neighbor's row position
            int newCol = col + j;  // Calculate neighbor's column position
            
            // If neighbor is valid position AND has a mine
            if (ValidCoordinates(newrow, newCol) && 
                grid[newrow][newCol].hasMine) {
                counter++; // Adds 1 to the mine counter
            }
        }
    }
    return counter; // Returns total mines around the cell
}

void startGame() {
    // First Initialize all cells to default values
    for (int i = 0; i < SIZE; i++) { // loop through each row
        for (int j = 0; j < SIZE; j++) { // loop through each column
            grid[i][j].hasFlag = false;   // No flags initially
            grid[i][j].hasMine = false;   // NO mines initially
            grid[i][j].revealed = false;  // all cells hidden initially
            grid[i][j].MinesNear = 0;     // No mines near calculated YET
        }
    }

    srand(time(0));                      // Initialize random generator with current time
    int minesPlaced = 0;                 // Counter for how many mines we've placed
    while (minesPlaced < Mines_Number) { // Keep placing until we have 8 mines
        int row = rand() % SIZE;         // Random row (0 to 5)
        int col = rand() % SIZE;         // Random column (0 to 5)
    
        if (!grid[row][col].hasMine) {   // If this cell doesn't already have a mine
            grid[row][col].hasMine = true;  // Place a mine here
            minesPlaced++;                  // Increment our mine counter
        }
        // If cell already has mine, loop continues to try another position
    }
    
    // Third, calculate numbers for all non-mine cells
    for (int i = 0; i < SIZE; i++) {        // Loop through each row
        for (int j = 0; j < SIZE; j++) {    // Loop through each column
            if (!grid[i][j].hasMine) {         // Only for cells that don't have mines
                grid[i][j].MinesNear = countMinesNear(i, j); // Count mines around this cell
            }
        }
    }
}

void displayGrid(bool showMines) {
    // showMines = true when game ends to reveal all mines
    cout << endl; 
    
     cout << "    ";
    for (int i = 0; i < SIZE; i++) {    // Print column numbers (0 1 2 3 4 5)
       cout << " " << i << " ";
    }
    cout << endl;                       // New line after column numbers
    
    for (int i = 0; i < SIZE; i++) {        // Loop through each row
        cout << "  " << i << " ";           // Print row number at start of each line
        for (int j = 0; j < SIZE; j++) {    // Loop through each column in this row
            if (showMines && grid[i][j].hasMine) {         // If we're showing mines AND this cell has one
                cout << " * ";                              // Show mine symbol (*)
            } else if (grid[i][j].hasFlag) {               // Else if cell has a flag
                cout << " S ";                              // Show flag symbol (F)
            } else if (grid[i][j].revealed) {              // Else if cell is revealed
                if (grid[i][j].MinesNear == 0) {       // If no mines around
                    cout << "   ";                          // Show empty space
                } else {                                    // If there are mines around
                    cout << " " << grid[i][j].MinesNear << " "; // Show the number
                }
            } else {                                        // Else cell is hidden
                cout << " # ";                              // Show hidden symbol
            }
        }
        cout << endl;                                       // New line after each row
    }
    cout << endl;                                           // Extra line for spacing
}

void checkVictory() {
    int revealedCells = 0;                  // Counter for revealed non-mine cells
    for (int i = 0; i < SIZE; i++) {        // Loop through each row
        for (int j = 0; j < SIZE; j++) {    // Loop through each column
            // If cell is revealed AND doesn't have a mine
            if (grid[i][j].revealed && !grid[i][j].hasMine) {
                revealedCells++;            // Count this cell
            }
        }
    }
    
    // Win condition: all non-mine cells are revealed
    // Total cells = 36, mines = 8, so need to reveal 28 cells
    if (revealedCells == (SIZE * SIZE - Mines_Number)) {
        Victory = true;                     // Player won
        GameOver = true;                    // Game is finished
        cout << "\033[32mCongratulations! You won the game!\033[0m\n"; // Victory message
    }
}

void revealCell(int row, int col) {
    // Safety checks: don't reveal if coordinates invalid, already revealed, or has flag
    if (!ValidCoordinates(row, col) ||     // Check if position is on the board
        grid[row][col].revealed ||          // Check if already revealed
        grid[row][col].hasFlag) {           // Check if has flag (flagged cells can't be revealed)
        return;                             // Exit function without doing anything
    }
    
    grid[row][col].revealed = true;         // Mark this cell as revealed
    
    // Check if player hit a mine (lose condition)
    if (grid[row][col].hasMine) {
        GameOver = true;                    // Game ends
        cout << "\033[31mBOOM! You hit a sensor.\033[0m"; // Lose message
        displayGrid(true);                  // Show board with all mines visible
                  return;                  // Exit function
    }
    
    // Auto-reveal feature: if cell has 0 adjacent mines, reveal all neighbors
    if (grid[row][col].MinesNear == 0) {
        for (int i = -1; i <= 1; i++) {    // Check all 8 directions around current cell
            for (int j = -1; j <= 1; j++) {
                revealCell(row + i, col + j); // RECURSION: call this function on neighbor
                // This creates a chain reaction that reveals large empty areas
            }
        }
    }
    
    checkVictory();                         // After revealing, check if player won
}

void toggleFlag(int row, int col) {
    // Can't flag if coordinates invalid or cell already revealed
    if (!ValidCoordinates(row, col) ||     // Check if position is on board
        grid[row][col].revealed) {          // Check if already revealed
        return;                             // Exit without doing anything
    }
    
    // Toggle flag: if has flag, remove it; if no flag, add it
    grid[row][col].hasFlag = !grid[row][col].hasFlag; // ! operator flips true/false
}

bool playGame() {
    cout << "=== MINESWEEPER ===\n";       // Game title
    cout << "Commands:\n";                  // Instructions header
    cout << "R row col - Reveal cell\n";   // How to reveal
    cout << "F row col - Toggle shield\n";   // How to flag             
    
    while (!GameOver) {                     // Keep playing until game ends
        displayGrid(false);                 // Show current board (don't show mines)
        
        char command;                       // Variable to store user's command
        int row, col;                       // Variables to store coordinates
        
        cout << "Enter command: ";          // Prompt user
        cin >> command;                     // Read command from user
        
        // Check if user wants to reveal a cell
        if (command == 'R' || command == 'r') {
            cout << "Enter row and column: "; // Ask for coordinates
            cin >> row >> col;              // Read coordinates from user
            revealCell(row, col);           // Call function to reveal the cell
        } 
        // Check if user wants to toggle a flag
        else if (command == 'F' || command == 'f') {
            cout << "Enter row and column: "; // Ask for coordinates
            cin >> row >> col;               // Read coordinates from user
            toggleFlag(row, col);           // Call function to toggle flag
        } 
        // Handle invalid commands
        else {
            cout << "Invalid command. Use R or F.\n"; // Error message
        }
    } // End of while loop - game continues until gameOver becomes true
    if (Victory)
    {
        return true;
    }
    else 
        return false;
}