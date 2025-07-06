#ifndef HANGMAN_FUN_H 
#define HANGMAN_FUN_H 
#include <iostream>
#include <vector>
using namespace std;

int misses = 1;

//defining functions here!!!

void hangman_intro()    //quick intro to the game's objective
{
    cout<<"                    HANGMAN" <<endl;
    cout<<"              -------------------" <<endl;
    cout<<"Guess the code to unlock the safe and get the money!" <<endl;
    cout<<"          Input one letter at a time" <<endl;
    cout<<"              -------------------" <<endl;
}

void display_misses(int misses)     //A display with the amount of misses and the little hangman
{
    if (misses==0)
    {
    cout<<"========="  <<endl;
    cout<<"  +---+"  <<endl;
    cout<<"      |" <<endl;
    cout<<"      |" <<endl;
    cout<<"      |" <<endl;
    cout<<"      |" <<endl;
    cout<<"      |"  <<endl;
    cout<<"========="  <<endl;
    }
    else if (misses==1)
    {
    cout<<"2 MISSES! 2 ATTEMPTS REMAINING!!" <<endl;
    cout<<"========="  <<endl;
    cout<<"  +---+"  <<endl;
    cout<<"  |   |" <<endl;
    cout<<"      |" <<endl;
    cout<<"      |" <<endl;
    cout<<"      |" <<endl;
    cout<<"      |"  <<endl;
    cout<<"========="  <<endl;
    }
    else if (misses==2)
    {
    cout<<"2 MISSES! 2 ATTEMPTS REMAINING!!" <<endl;
    cout<<"========="  <<endl;
    cout<<"  +---+"  <<endl;
    cout<<"  |   |" <<endl;
    cout<<"  O   |" <<endl;
    cout<<"      |" <<endl;
    cout<<"      |" <<endl;
    cout<<"      |"  <<endl;
    cout<<"========="  <<endl;
    }
    else if (misses==3)
    {
    cout<<"3 MISSES! 1 ATTEMPT REMAINING!!!" <<endl;
    cout<<"========="  <<endl;
    cout<<"  +---+"  <<endl;
    cout<<"  |   |" <<endl;
    cout<<"  O   |" <<endl;
    cout<<" /|\\  |" <<endl;
    cout<<"      |" <<endl;
    cout<<"      |"  <<endl;
    cout<<"========="  <<endl;
    }
    else if (misses==4)
    {
    cout<<"G A M E   O V E R" <<endl;
    cout<<"========="  <<endl;
    cout<<"  +---+"  <<endl;
    cout<<"  |   |" <<endl;
    cout<<"  O   |" <<endl;
    cout<<" /|\\  |" <<endl;
    cout<<" / \\  |" <<endl;
    cout<<"      |"  <<endl;
    cout<<"========="  <<endl;
    }
}

void display_status(vector<char> incorrect, string ANS)  //will display the exact letters that the user input that are incorrect
{
    cout<<"Incorrect Guesses: " <<endl;
    for(int i=0; i<incorrect.size(); i++)
    {
        cout<<incorrect[i]<<" ";
    }
    
    cout<<"\nCODEWORD: " <<endl;

    for(int i=0; i<ANS.length(); i++)
    {
        cout<<ANS[i] <<" ";
    }
}

bool hangman_outro(string ANS, string CODEWORD)
{
    if(ANS==CODEWORD){
        cout<<"Good job! You saved x! You've earned (REWARD GOES HERE LOL)" <<endl;
        cout<<"Congrats!" <<endl;
        return true;
    }
    else{
        cout<<"You lost thief! The safe has been locked up for good! D:" <<endl;
        return false;
    }
}

#endif