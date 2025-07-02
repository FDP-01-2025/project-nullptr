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

// Function that verificates if the player has guessed a character and if it's in the right position
void guessVerification (const string& secret, const string& guess, string& partialResult){
    int wellPlaced = 0;
    int missPlaced = 0;
    vector <bool> usedSecret(secret.length(), false);
    vector <bool> usedGuess(guess.length(), false);
    string misplacedChars = " ";

    for (int i = 0; i < secret.length(); i++) { // Verification for a right character in the right position
        if (guess[i]==secret[i]){
            wellPlaced ++;
            partialResult[i] = guess[i];
            usedSecret[i] = true;
            usedGuess[i] = true;
        }
    }
    for (int j = 0; j < guess.length(); j++) {
        if (usedGuess[j]){
            continue;
        }
        for (int k = 0; k < secret.length(); k++) { // Verification for a right character in the wrong position
            if (!usedSecret[k] && guess[j] == secret[k]){
                missPlaced ++;
                usedSecret[k] = true;
                misplacedChars += guess[j];
                break;
            }
        }
    }
    cout << "Characters placed in the correct position: " << wellPlaced <<endl;
    cout << "Characters guessed but in a wrong position: " << missPlaced <<endl;
    cout << "Characters in wrong position: " << misplacedChars <<endl;
    cout << "Sequence: " << partialResult <<endl;
    
}

// Main game's function
int alphnumbseq() {
    int length = 5;
    string S_sequence = secretSequence(length);
    string P_guess;
    string partialResult(S_sequence.length(), '_');

    do{
        P_guess = playerGuess(length);
        guessVerification (S_sequence, P_guess, partialResult);
    }while (P_guess != S_sequence);
    cout << "YOU WON" << endl;

    cout << "-----Alphanumeric sequence-----" << endl; // Placeholder name
   
    return 0;
}