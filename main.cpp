#include <iostream>
#include <vector>
#include <hangman_fun.h> //declaring functions for HANGMAN
using namespace std;
int main() {

    //HANGMAN starts under this message!!!
    hangman_intro();

    string CODEWORD = "CODEWORDXD"; //first variable
    string ANS = "_ _ _ _ _ _ _ _ _ _";
    int misses = 0;
    vector<char> incorrect;
    bool guess = false;
    char letter;                    //last variable

    while (ANS != CODEWORD && misses<7)
    {
    display_misses(misses);
    display_status(incorrect, ANS);
    }




    //HANGMAN ends before this message!!!
return 0;
}