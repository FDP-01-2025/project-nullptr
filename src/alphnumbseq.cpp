#include "alphnumbseq.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime> // Library that gets the current time to generate seeds for the sequence
#include <cstdlib> // Library that grants acces to srand() to generate the seeds

using namespace std;

// Function that generates a random sequence of numbers and letters
string secretSequence(int length) {
    string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string sequence = "";

    srand(time(0)); // Random seed for the sequence

    for (int i = 0; i < length; ++i) {
        int index = rand() % characters.length();
        sequence += characters[index];
    }

    cout << "Secuencia generada [BORRAR]: " << sequence << endl;
    return sequence;
}

// Function that reads the player's guess
string playerGuess (int length) {
    string guess;
    cout << "Guess the sequence (Use only capital letters and numbers. Do not use spaces)" <<endl;
    cin >> guess;
    return guess;
}

// Main game's function
int alphnumbseq() {
    int longitud = 5;
    string secuencia = secretSequence(longitud);
    string intento = playerGuess(longitud);;
    cout << "-----Alphanumeric sequence-----" << endl; // Placeholder name
   
    return 0;
}