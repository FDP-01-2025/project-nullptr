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

    for (int i = 0; i < length; i++) {
        int index = rand() % characters.size();
        sequence += characters[index];
    }

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
void guessVerification (const string& secret, const string& guess, string& partialResult, string& discardedChars){
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
        bool found = false;
        for (int k = 0; k < secret.length(); k++) { // Verification for a right character in the wrong position
            if (!usedSecret[k] && guess[j] == secret[k]){
                missPlaced ++;
                usedSecret[k] = true;
                misplacedChars += guess[j];
                found = true;
                break;
            }
        }
        if (!found){
            if (discardedChars.find(guess[j]) == string::npos) {
                discardedChars += guess[j];
                discardedChars += ' ';
            }
        }
    }
    cout << "\033[32mCharacters placed in the correct position: \033[0m" << wellPlaced <<endl;
    cout << "\033[33mCharacters guessed but in a wrong position: \033[0m" << missPlaced <<endl;
    cout << "\033[33mCharacters in wrong position: \033[0m" << misplacedChars <<endl;
    cout << "\033[31mCharacters discarded (not in sequence): \033[0m" << discardedChars << endl;
    cout << "Sequence: " << partialResult <<endl;
    
}

// Main game's function
int alphnumbseq() {
    int length = 5;

    cout << "\033[32m";
    cout << R"(
    
      ____          _      ____                 _             
     / ___|___   __| | ___| __ ) _ __ ___  __ _| | _____ _ __ 
    | |   / _ \ / _` |/ _ \  _ \| '__/ _ \/ _` | |/ / _ \ '__|
    | |__| (_) | (_| |  __/ |_) | | |  __/ (_| |   <  __/ |   
     \____\___/ \__,_|\___|____/|_|  \___|\__,_|_|\_\___|_|   
    
    )";
    cout << "        Welcome to CodeBreaker - Crack the code!\n";
    cout << "-----------------------------------------------------------\n\n";
    cout << "\033[0m";
    for (int roundCount = 0; roundCount < 3; roundCount++){
    string S_sequence = secretSequence(length);
    string P_guess;
    string partialResult(S_sequence.length(), '_');
    string discardedChars = " ";
    int attemptCount = 0;
    bool won = false;
    cout << "====================================================================" << endl;
    cout << "\033[36mRound: \033[0m" << roundCount + 1 <<endl;
    while (attemptCount < 10){
        cout << "\033[36mAttempt: \033[0m" << attemptCount + 1 << " \033[36mof\033[0m 10" << endl;
        P_guess = playerGuess(length);
        attemptCount ++;
        guessVerification (S_sequence, P_guess, partialResult, discardedChars);

        if (P_guess == S_sequence){
            cout << "\033[32mYOU WON\033[0m" << endl;
            won = true;
            break;
        }
    }

    if (!won){
        cout << "\033[31mYou ran out of attempts, the correct sequence was: \033[0m" << S_sequence << endl;
    }

    }
    return 0;
}