#include "minesweepergame.h"
#include <cstdlib> // For random numbers
#include <ctime>   // For time functions


//Global variables (can be used on all functions)
int SIZE = 6; //Board size (6x6)
int Sensors_Number = 8; //Number of Sensors around the board
Cell grid[6][6]; // Game board (array for 36 cells)
bool GameOver = false; // True when the game ends(win or lose)
bool Victory = false;//True when the player wins


bool ValidCoordinates(int row, int col) {
    // Checks if the given coordinates are valid
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE;
}

int countSensorsNear(int row, int col) {
    // Function to count how many Sensors are near
    int counter = 0; // Start counting from 0 Sensors
    for (int i = -1; i <= 1; i++) {  // Check row above (-1), same row (0), row below (1)
        for (int j = -1; j <= 1; j++) {  // Check col left (-1), same col (0), col right (1)
            int newrow = row + i;  // Calculate neighbor's row position
            int newCol = col + j;  // Calculate neighbor's column position
            
            // If neighbor is valid position AND has a Sensors
            if (ValidCoordinates(newrow, newCol) && 
                grid[newrow][newCol].hasSensor) {
                counter++; // Adds 1 to the Sensors counter
            }
        }
    }
    return counter; // Returns total Sensors around the cell
}

void startGame() {
    // First Initialize all cells to default values
    for (int i = 0; i < SIZE; i++) { // loop through each row
        for (int j = 0; j < SIZE; j++) { // loop through each column
            grid[i][j].hasShield = false;   // No shields initially
            grid[i][j].hasSensor = false;   // NO Sensors initially
            grid[i][j].revealed = false;  // all cells hidden initially
            grid[i][j].SensorsNear = 0;     // No Sensors near calculated YET
        }
    }

    srand(time(0));                      // Initialize random generator with current time
    int SensorsPlaced = 0;                 // Counter for how many Sensors we've placed
    while (SensorsPlaced < Sensors_Number) { // Keep placing until we have 8 Sensors
        int row = rand() % SIZE;         // Random row (0 to 5)
        int col = rand() % SIZE;         // Random column (0 to 5)
    
        if (!grid[row][col].hasSensor) {   // If this cell doesn't already have a Sensors
            grid[row][col].hasSensor = true;  // Place a Sensor here
            SensorsPlaced++;                  // Increment our Sensors counter
        }
        // If cell already has Sensors, loop continues to try another position
    }
    
    // Third, calculate numbers for all non-Sensors cells
    for (int i = 0; i < SIZE; i++) {        // Loop through each row
        for (int j = 0; j < SIZE; j++) {    // Loop through each column
            if (!grid[i][j].hasSensor) {         // Only for cells that don't have Sensors
                grid[i][j].SensorsNear = countSensorsNear(i, j); // Count Sensors around this cell
            }
        }
    }
}

void displayGrid(bool showSensors) {
    // showSensors = true when game ends to reveal all Sensors
    cout << endl; 
    
     cout << "    ";
    for (int i = 0; i < SIZE; i++) {    // Print column numbers (0 1 2 3 4 5)
       cout << " " << i << " ";
    }
    cout << endl;                       // New line after column numbers
    
    for (int i = 0; i < SIZE; i++) {        // Loop through each row
        cout << "  " << i << " ";           // Print row number at start of each line
        for (int j = 0; j < SIZE; j++) {    // Loop through each column in this row
            if (showSensors && grid[i][j].hasSensor) {         // If we're showing Sensors AND this cell has one
                cout << " * ";                              // Show Sensors symbol (*)
            } else if (grid[i][j].hasShield) {               // Else if cell has a shield
                cout << " S ";                              // Show shield symbol (S)
            } else if (grid[i][j].revealed) {              // Else if cell is revealed
                if (grid[i][j].SensorsNear == 0) {       // If no Sensors around
                    cout << "   ";                          // Show empty space
                } else {                                    // If there are Sensors around
                    cout << " " << grid[i][j].SensorsNear << " "; // Show the number
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
    int revealedCells = 0;                  // Counter for revealed non-Sensors cells
    for (int i = 0; i < SIZE; i++) {        // Loop through each row
        for (int j = 0; j < SIZE; j++) {    // Loop through each column
            // If cell is revealed AND doesn't have a Sensors
            if (grid[i][j].revealed && !grid[i][j].hasSensor) {
                revealedCells++;            // Count this cell
            }
        }
    }
    
    // Win condition: all non-Sensors cells are revealed
    // Total cells = 36, Sensors = 8, so need to reveal 28 cells
    if (revealedCells == (SIZE * SIZE - Sensors_Number)) {
        Victory = true;                     // Player won
        GameOver = true;                    // Game is finished
        cout << "\033[32mCongratulations! You won the game!\033[0m\n"; // Victory message
    }
}

void revealCell(int row, int col) {
    // Safety checks: don't reveal if coordinates invalid, already revealed, or has shield
    if (!ValidCoordinates(row, col) ||     // Check if position is on the board
        grid[row][col].revealed ||          // Check if already revealed
        grid[row][col].hasShield) {           // Check if has shield (shieldged cells can't be revealed)
        return;                             // Exit function without doing anything
    }
    
    grid[row][col].revealed = true;         // Mark this cell as revealed
    
    // Check if player hit a Sensors (lose condition)
    if (grid[row][col].hasSensor) {
        GameOver = true;                    // Game ends
        cout << "\033[31mBOOM! You hit a sensor.\033[0m"; // Lose message
        displayGrid(true);                  // Show board with all Sensors visible
                  return;                  // Exit function
    }
    
    // Auto-reveal feature: if cell has 0 adjacent Sensors, reveal all neighbors
    if (grid[row][col].SensorsNear == 0) {
        for (int i = -1; i <= 1; i++) {    // Check all 8 directions around current cell
            for (int j = -1; j <= 1; j++) {
                revealCell(row + i, col + j); // RECURSION: call this function on neighbor
                // This creates a chain reaction that reveals large empty areas
            }
        }
    }
    
    checkVictory();                         // After revealing, check if player won
}

void toggleshield(int row, int col) {
    // Can't shield if coordinates invalid or cell already revealed
    if (!ValidCoordinates(row, col) ||     // Check if position is on board
        grid[row][col].revealed) {          // Check if already revealed
        return;                             // Exit without doing anything
    }
    
    // Toggle shield: if has shield, remove it; if no shield, add it
    grid[row][col].hasShield = !grid[row][col].hasShield; // ! operator flips true/false
}

bool playGame() {
    cout << "\033[31m"; //game title
    cout << "ooooo              .o.        .oooooo..o oooooooooooo ooooooooo.         ooooooooo.     .oooooo.     .oooooo.   ooo        ooooo "<<endl; 
    cout << "`888'             .888.      d8P'    `Y8 `888'     `8 `888   `Y88.       `888   `Y88.  d8P'  `Y8b   d8P'  `Y8b  `88.       .888' "<<endl;
    cout << " 888             .8''88.     Y88bo.       888          888   .d88'        888   .d88' 888      888 888      888  888b     d'888 "<<endl;
    cout << " 888            .8' `888.     `'Y8888o.   888oooo8     888ooo88P'         888ooo88P'  888      888 888      888  8 Y88. .P  888  "<<endl;
    cout << " 888           .88ooo8888.        `'Y88b  888          888`88b.           888`88b.    888      888 888      888  8  `888'   888  "<<endl;
    cout << " 888       o  .8'     `888.  oo     .d8P  888       o  888  `88b.         888  `88b.  `88b    d88' `88b    d88'  8    Y     888  "<<endl;
    cout << "o888ooooood8 o88o     o8888o 8""88888P'   o888ooooood8 o888o  o888o       o888o  o888o  `Y8bood8P'   `Y8bood8P'  o8o        o888o "<<endl;  
    cout << endl;
    cout << "        Welcome to LaserRoom - Turn off the sensors!\n";
    cout << "-----------------------------------------------------------\n\n"; 
    cout << "\033[0m";
    cout << endl;
    cout << "Commands:\n";                  // Instructions header
    cout << "R row col - Reveal cell\n";   // How to reveal
    cout << "F row col - Toggle shield\n";   // How to put a shield             
    
    while (!GameOver) {                     // Keep playing until game ends
        displayGrid(false);                 // Show current board (don't show Sensors)
        
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
        // Check if user wants to toggle a shield
        else if (command == 'F' || command == 'f') {
            cout << "Enter row and column: "; // Ask for coordinates
            cin >> row >> col;               // Read coordinates from user
            toggleshield(row, col);           // Call function to toggle shield
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