#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "hangman_fun.h"
using namespace std;

//declaring functions here!!!
void hangman_intro();
void display_misses(int misses);
void display_status(vector<char> incorrect, string ANS);
void end_game(string ANS, string CODEWORD);

//HANGMAN IS DOWN HERE
bool playhangman() {
    bool passgame;
    //HANGMAN starts under this message!!!
    hangman_intro(); //quick intro to the game

    const char* CODEWORDS[] = {"THIEF", "THEFT", "LOOTS", "FRAUD", "SNEAK", "CRIME", "CROOK", "BANKS"}; //first variable
    int size = sizeof(CODEWORDS) / sizeof(CODEWORDS[0]);
    srand(time(0));
    const char* CODEWORD = CODEWORDS[rand() %size];
    string ANS = "_____";
    int misses = 0;
    vector<char> incorrect;
    bool guess = false;
    char letter;                    //last variable

    while (ANS != CODEWORD && misses<4)
    {
    display_misses(misses);

    display_status(incorrect, ANS);

    cout<<"\n\nPlease enter your guess: " <<endl;
    cin>>letter;


    for(int i=0; i<strlen(CODEWORD); i++)
    {
        if(letter==CODEWORD[i])
        {
            ANS[i] = letter;            //if the user inputs a correct letter then his guess is true
            guess = true;
        }
    }
    if(guess){
        cout<<"\033[32mCorrect guess!\033[0m" <<endl;
    }
    else {
        cout<<"\033[31mIncorrect guess!\033[0m" <<endl;
        incorrect.push_back(letter);
        misses++;
    }
    guess = false;
    }

    passgame=hangman_outro(ANS, CODEWORD);
    if (passgame)
    {
        return true;
    }
    else if (!passgame)
    {
        return false;
    }
    
    //HANGMAN ends before this message!!!
}