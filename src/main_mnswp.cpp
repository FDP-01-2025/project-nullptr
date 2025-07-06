#include "mnswp_logic.cpp"
bool playminesweeper() {
    GameOver=false;
    Victory=false;
    startGame();
    return playGame();
}