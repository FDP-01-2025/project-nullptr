#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "src\stealmaze.cpp"
#include "src\hiddentreasure.cpp"
#include "src\hangman.cpp"
#include "src\main_mnswp.cpp"
#include "src\alphnumbseq.h"
#include "src\blackjack.cpp"
using namespace std;

struct saveData {
    int lives;
    int currentStage;
};

void saveProgress (const saveData& data) {
    ofstream file("gameSaveFile.txt");
    if (file.is_open()) {
        file << data.lives << endl;
        file << data.currentStage << endl;
        file.close();
    }
}

bool loadProgress (saveData& data) {
    ifstream file("gameSaveFile.txt");
    if (file.is_open()) {
        file >> data.lives;
        file >> data.currentStage;
        file.close();
        return true;
    }
    return false;
}

void promptToSave(int lives, int stage) {
    char saveOpt;
    cout << "Do you want to save your progress? [Y/N]: ";
    cin >> saveOpt;
    if (saveOpt == 'Y' || saveOpt == 'y') {
        saveProgress({lives, stage});
        cout << "Progress saved.\n";
    }
}

int main(){
    saveData data = {3, 0};
    char option;

    cout << "Do you want to load a saved game? [Y]es  [N]o" << endl;
    cin >> option;

    if (option == 'Y' || option == 'y') {
        if (loadProgress(data)) {
            cout << "Game loaded" << endl;
        } else {
            cout << "Save file not found. Starting a new game" << endl;
        }
    }

    int lives = data.lives;
    int stage = data.currentStage;
    bool passed;  
    
    //Blackjack
     while (lives > 0) {
        if (stage <= 0 && lives > 0) {
            passed = playblackjack();
            if (passed) {
                stage = 1;
                promptToSave (lives, stage);
                break;
            } else {
                lives--;
                cout << "You got " << lives << " tries left\n";
            }
        } else {
            break;
        }
    }
        //BANK MINIGAME?
    while (lives > 0) {
        if (stage == 1 && lives > 0) {
            passed = alphnumbseq();
            if (passed) {
                stage = 2;
                promptToSave (lives, stage);
                break;
            } else {
                lives--;
                cout << "You got " << lives << " tries left\n";
            }
        } else {
            break;
        }
    }

    if (lives == 0) {
        cout << "GAME OVER\n";
        return 0;
    }
    //MUSEUM STEAL
    while (lives > 0) {
        if (stage == 2 && lives > 0) {
            passed = playhiddentreasure();
            if (passed) {
                stage = 3;
                promptToSave (lives, stage);
                break;
            } else {
                lives--;
                cout << "You got " << lives << " tries left\n";
            }
        } else {
            break;
        }
    }

    if (lives == 0) {
        cout << "GAME OVER\n";
        return 0;
    }
    
    while (lives > 0) {
        if (stage == 3 && lives > 0) {
            passed = playstealmaze();
            if (passed) {
                stage = 4;
                promptToSave (lives, stage);
                break;
            } else {
                lives--;
                cout << "You got " << lives << " tries left\n";
            }
        } else {
            break;
        }
    }

    if (lives == 0) {
        cout << "GAME OVER\n";
        return 0;
    }
    //BANKS STEAL
    while (lives > 0) {
        if (stage == 4 && lives > 0) {
            passed = playhangman();
            if (passed) {
                stage = 5;
                promptToSave (lives, stage);
                break;
            } else {
                lives--;
                cout << "You got " << lives << " tries left\n";
            }
        } else {
            break;
        }
    }

    if (lives == 0) {
        cout << "GAME OVER\n";
        return 0;
    }
        //MINESWEPPER
    while (lives > 0) {
        if (stage == 5 && lives > 0) {
            passed = playminesweeper();
            if (passed) {
                stage = 6;
                promptToSave (lives, stage);
                break;
            } else {
                lives--;
                cout << "You got " << lives << " tries left\n";
            }
        } else {
            break;
        }
    }

    if (lives == 0) {
        cout << " GAME OVER\n";
        return 0;
    }
cout << "Congratulations, you completed the game!!!";
remove("gameSaveFile.txt");
return 0;
}