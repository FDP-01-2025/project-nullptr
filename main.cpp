#include <iostream>
#include <vector>
#include "hangman_fun.cpp"
using namespace std;
int main() {

    //HANGMAN starts under this message!!!
    hangman_intro(); //quick intro to the game

    string CODEWORD = "CODEWORDXD"; //first variable
    string ANS = "__________";
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


    for(int i=0; i<CODEWORD.length(); i++)
    {
        if(letter==CODEWORD[i])
        {
            ANS[i] = letter;            //if the user inputs a correct letter then his guess is true
            guess = true;
        }
    }
    if(guess){
        cout<<"Correct guess!" <<endl;
    }
    else {
        cout<<"Incorrect guess!" <<endl;
        incorrect.push_back(letter);
        misses++;
    }
    guess = false;
    }

    hangman_outro(ANS, CODEWORD);

    //HANGMAN ends before this message!!!
return 0;
}