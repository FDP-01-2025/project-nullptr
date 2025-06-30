#include <iostream>
#include <vector>

//declaring functions here!!!
void hangman_intro();
void display_misses(int misses);
void display_status(vector<char> incorrect, string ANS);
void end_game(string ANS, string CODEWORD);