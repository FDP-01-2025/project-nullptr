#include <iostream>
#include <string>
#include <vector>
#include "src\stealmaze.cpp"
#include "src\hiddentreasure.cpp"
#include "src\hangman.cpp"
#include "src\main_mnswp.cpp"
using namespace std;
int main(){
int lifes=3;
bool passed;
        //MINESWEPPER
    while (lifes > 0) {
        passed = playminesweeper();  
        if (passed) {
            break;
        } else {
            lifes--;
            cout << "You got  " << lifes  << " tries left\n";
        }
    }

    if (lifes == 0) {
        cout << "GAME OVER\n";
        return 0;
    }
    //MUSEUM STEAL
    while (lifes > 0) {
        passed = playhiddentreasure();  
        if (passed) {
            break;
        } else {
            lifes--;
            cout << "You got  " << lifes  << " tries left\n";
        }
    }

    if (lifes == 0) {
        cout << "GAME OVER\n";
        return 0;
    }
    
    while (lifes > 0) {
        passed = playstealmaze();  
        if (passed) {
            break;
        } else {
            lifes--;
            cout << "You got  " << lifes  << " tries left\n";
        }
    }

    if (lifes == 0) {
        cout << "GAME OVER\n";
        return 0;
    }
    //BANKS STEAL
    while (lifes > 0) {
        passed = playhangman();  
        if (passed) {
            break;
        } else {
            lifes--;
            cout << "You got  " << lifes  << " tries left\n";
        }
    }

    if (lifes == 0) {
        cout << "GAME OVER\n";
        return 0;
    }
cout << "The bool works";
}