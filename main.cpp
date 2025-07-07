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
#include "src\intromenu.h"
using namespace std;

struct saveData {
    int lives;
    int currentStage;
};

void saveProgress(const saveData& data) {
    ofstream file("gameSaveFile.txt");
    if (file.is_open()) {
        file << data.lives << endl;
        file << data.currentStage << endl;
        file.close();
    }
}

bool loadProgress(saveData& data) {
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

int main() {
    saveData data = {3, 0};
    char option;

    cout << "Do you want to load a saved game? [Y]es  [N]o: ";
    cin >> option;

    if (option == 'Y' || option == 'y') {
        if (loadProgress(data)) {
            cout << "Game loaded.\n";
        } else {
            cout << "Save file not found. Starting new game.\n";
        }
    }

    int lives = data.lives;
    int stage = data.currentStage;
    bool passed;

    if (stage == 0) {
        passed = intromenu();
        if (!passed) return 0;
        stage = 1;
        promptToSave(lives, stage);
    }

    while (lives > 0 && stage == 1) {
        passed = playblackjack();
        if (passed) {
            stage = 2;
            promptToSave(lives, stage);
            break;
        } else {
            lives--;
            cout << "You got " << lives << " tries left\n";
        }
    }
    if (lives == 0) return cout << "GAME OVER\n", 0;

    while (lives > 0 && stage == 2) {
        passed = alphnumbseq();
        if (passed) {
            stage = 3;
            promptToSave(lives, stage);
            break;
        } else {
            lives--;
            cout << "You got " << lives << " tries left\n";
        }
    }
    if (lives == 0) return cout << "GAME OVER\n", 0;

    while (lives > 0 && stage == 3) {
        passed = playhiddentreasure();
        if (passed) {
            stage = 4;
            promptToSave(lives, stage);
            break;
        } else {
            lives--;
            cout << "You got " << lives << " tries left\n";
        }
    }
    if (lives == 0) return cout << "GAME OVER\n", 0;

    while (lives > 0 && stage == 4) {
        passed = playstealmaze();
        if (passed) {
            stage = 5;
            promptToSave(lives, stage);
            break;
        } else {
            lives--;
            cout << "You got " << lives << " tries left\n";
        }
    }
    if (lives == 0) return cout << "GAME OVER\n", 0;

    while (lives > 0 && stage == 5) {
        passed = playhangman();
        if (passed) {
            stage = 6;
            promptToSave(lives, stage);
            break;
        } else {
            lives--;
            cout << "You got " << lives << " tries left\n";
        }
    }
    if (lives == 0) return cout << "GAME OVER\n", 0;

    while (lives > 0 && stage == 6) {
        passed = playminesweeper();
        if (passed) {
            stage = 7;
            cout << "Congratulations, you completed the game!!!\n";
            remove("gameSaveFile.txt");
            break;
        } else {
            lives--;
            cout << "You got " << lives << " tries left\n";
        }
    }
    if (lives == 0) return cout << "GAME OVER\n", 0;

    return 0;
}
