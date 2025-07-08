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
    cout<<"Do you want to save your progress? [Y/N]: ";
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
    char any;

    //MENU
    if (stage == 0) 
    {
        passed = intromenu();
        if (!passed) return 0;
        stage = 1;
        promptToSave(lives, stage);
    }
    else

    cout<<"          You are a retired thief, once the best of them all.\n";                    //story intro
    cout<<"  You served time in prison and now your son is sick and in need of surgery.\n";
    cout<<"You decide to put your skills to use one last time, for a good cause this time.\n";
    cout<<"                       [Input any button to continue]\n";                            //instructions to continue

    cin>>any;

    //CASINO

    cout<<"              You decide to do a heist on three places run by very rich people\n";
    cout<<"Your first objective is the Big Western Casino, you meet someone there who will take you to the money\n";
    cout<<"   'If you want your money you must beat me in my favorite game! Blackjack it is!' He says... \n";
    cout<<"      You crack your knuckles and put your game face on. It's blackjack! Try to sum 21!\n";
    cout<<"                           [Input any button to start the game]\n";

    cin>>any;

    //Blackjack
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
    if (lives == 0) { cout << "GAME OVER\n"; return 0;}

    cout<<"                                'You got me, thief!' He says.\n";
    cout<<"                         'As promised, I'll take you to your money.'\n";
    cout<<"And so he did, leading you towards the back part of the casino, With long golden hallways and a single door.\n";
    cout<<"         The door had a screen and a small keyboard, you instantly know what this is about.\n";
    cout<<"                               [Input any button to continue]\n";                            //instructions to continue

    cin>>any;

    cout<<"    If you want the money you'll need to crack the code, pay close attention to the screen!\n";
    cout<<"You need to input the characters in sequence in the correct order. Piece of cake, riht? Good luck!\n";
    cout<<"                               [Input any button to continue]\n";                            //instructions to continue

    cin>>any;

        //CASINO 2
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
    if (lives == 0) { cout << "GAME OVER\n"; return 0;}

    cout<<"You got the money! Great job thief! This is a very good start.\n";
    cout<<"    Now you can move to the next area! The museum!\n";
    cout<<"           [Input any button to continue]\n";                            //instructions to continue

    cin>>any;

    cout<<"         A few days later you enter the museum at night...\n";
    cout<<"After a long search through those rooms you find a big one with... sand?\n";
    cout<<"     Is there really any treasure here? Only one way to find out!\n";
    cout<<"                      It's a treasure hunt!\n";
    cout<<"                [Input any button to start the game]\n";                            //instructions to continue

    cin>>any;

    // MUSEUM STEAL
    while (lives > 0 && stage ==3)
    {
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
    if (lives == 0) { cout << "GAME OVER\n"; return 0;}
    
    cout<<"You found the treasure but this place is huge... there must be more!\n";
    cout<<"                      Explore a bit!\n";
    cout<<"           [Input any button to start the game]\n";                            //instructions to continue

    cin>>any;

    //STEALMAZE
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
    if (lives == 0) { cout << "GAME OVER\n"; return 0;}

    cout<<"You run into the night with both treasures in your hands! You're unstoppable!\n";
    cout<<"                  [Input any button to continue]\n";
    cin>>any;

    //BANKS STEAL

    cout<<"You walk in the open street, the cold air hits you as you look up to the big 'B' in front of you\n";
    cout<<"          B as in BANK, the biggest of them all, and you're gonna do a heist on it\n";
    cout<<"                            [Input any button to continue]\n";                            //instructions to continue

    cin>>any;

    cout<<" You sneak in fairly easily and go down flights and flights of stairs until you hit the basement...\n";
    cout<<" There it was... The biggest safe you've ever seen, you could peep through a small hole and see...\n";
    cout<<"        Money! Tons of money! Almost yours! You just have to crack the code for the safe.\n";
    cout<<"        You turn to the digital lock and see a small stickman appearing... it's... hangman!\n";
    cout<<"\n";
    cout<<"          [HINT: Guess the codeword letter by letter, it's related to thievery and crime]\n";
    cout<<"                               [Input any button to continue]\n";

    cin>>any;

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
    if (lives == 0) { cout << "GAME OVER\n"; return 0;}

    cout<<"You crack the code with ease and step into the safe, the money is at the far back and- Woah! Wait!\n";
    cout<<"       You see a very tiny beam of red light cutting through the room... Lasers?!\n";
    cout<<"     You'll have to deactivate them somehow... ba careful not to step through one!\n";
    cout<<"                         It's just like that game Minesweeper!\n";
    cout<<"                             [Input any button to continue]\n";
    cin>>any;

    //LASERS

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
    if (lives == 0)  { cout << "GAME OVER\n"; return 0;}

    cout<<"You run out of the bank as the alarm is triggered, no one has the speed to chase you and you escape with ease\n";
    cout<<"              You count the money... It's more than enough for your son!\n";
    cout<<"    You might be a criminal, thief. But you're first and foremost a good father... :)\n";
    cout<<"                           [Input any button to end the game]\n";
    
    cin>>any;

    cout<<"Thanks for playing our game! :D\n";

    return 0;
}
