#include <iostream>
#include <string>
#include <vector>
#include "src\stealmaze.cpp"
#include "src\hiddentreasure.cpp"
#include "src\hangman.cpp"
#include "src\main_mnswp.cpp"
#include "src\alphnumbseq.h"
#include "src\blackjack.cpp"
using namespace std;
int main(){
int lifes=3;
bool passed;
char any;
    
    cout<<"          You are a retired thief, once the best of them all.\n";                    //story intro
    cout<<"  You served time in prison and now your son is sick and in need of surgery.\n";
    cout<<"You decide to put your skills to use one last time, for a good cause this time.\n";
    cout<<"                       [Input any button to continue]\n";                            //instructions to continue

    cin>>any;

    cout<<"              You decide to do a heist on three places run by very rich people\n";
    cout<<"Your first objective is the Big Western Casino, you meet someone there who will take you to the money\n";
    cout<<"   'If you want your money you must beat me in my favorite game! Blackjack it is!' He says... \n";
    cout<<"      You crack your knuckles and put your game face on. It's blackjack! Try to sum 21!\n";
    cout<<"                           [Input any button to start the game]\n";

    cin>>any;

    //CASINO
     while (lifes > 0) {
        passed = playblackjack();  
        if (passed) {
            break;
        } else {
            lifes--;
            cout << "You got  " << lifes  << " tries left\n";
        }
    }

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

    while (lifes > 0) {
        passed = alphnumbseq();  
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
    
    cout<<"You found the treasure but this place is huge... there must be more!\n";
    cout<<"                      Explore a bit!\n";
    cout<<"           [Input any button to start the game]\n";                            //instructions to continue

    cin>>any;

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

    cout<<"You crack the code with ease and step into the safe, the money is at the far back and- Woah! Wait!\n";
    cout<<"       You see a very tiny beam of red light cutting through the room... Lasers?!\n";
    cout<<"     You'll have to deactivate them somehow... ba careful not to step through one!\n";
    cout<<"                         It's just like that game Minesweeper!\n";
    cout<<"                             [Input any button to continue]\n";
    cin>>any;

        //LASERS
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
        cout << " GAME OVER\n";
        return 0;
    }
    cout<<"You run out of the bank as the alarm is triggered, no one has the speed to chase you and you escape with ease\n";
    cout<<"              You count the money... It's more than enough for your son!\n";
    cout<<"    You might be a criminal, thief. But you're first and foremost a good father... :)\n";
    cout<<"                           [Input any button to end the game]\n";
    
    cin>>any;

    cout<<"Thanks for playing our game! :D\n";

    return 0;
}