#include <iostream>
#include <vector>
#include "hangman_fun.h"
using namespace std;

int misses = 1;

//defining functions here!!!

void hangman_intro()
{
    cout<<"AHORCADO/n";
    cout<<"-------------------/n";
    cout<<"Objetivo: Salva a x de ser ahorcado, introduce la clave letra por letra./n";
    cout<<"-------------------/n";
}

void display_misses(int misses)
{
    if (misses==1)
    {
     cout<<"1 MISS! 3 ATTEMPT REMAINING!" <<endl;
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