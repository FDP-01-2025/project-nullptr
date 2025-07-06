#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <vector>
#include <string>
using namespace std;

struct Card {
    string rank;
    string suit;
    int value;
};

struct Player {
    string name;
    vector<Card> hand;
    int score = 0;
};

int blackjack();

#endif