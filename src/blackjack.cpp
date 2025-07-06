#include "blackjack.h" // <>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

// Function to shuffle the deck
void shuffleDeck(vector<Card>& deck) {
    srand(time(0));
    for (int i = 0; i < deck.size(); ++i) {
        int j = rand() % deck.size();
        swap(deck[i], deck[j]);
    }
}

vector<Card> createDeck() {
    vector<Card> deck;
    vector<string> suits = {"S", "H", "D", "C"}; // Spade, Heart, Diamond, Club
    vector<string> ranks = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    for (const auto& suit : suits) {
        for (int i = 0; i < ranks.size(); i++) {
            int value;
            if (ranks[i] == "A") value = 11;
            else if (ranks[i] == "J" || ranks[i] == "Q" || ranks[i] == "K") value = 10;
            else value = stoi(ranks[i]); //String to int

            deck.push_back({ranks[i], suit, value});
        }
    }

    shuffleDeck(deck);
    return deck;
}

void dealInitialCards(vector<Card>& deck, vector<Card>& playerHand, vector<Card>& dealerHand) {
    playerHand.push_back(deck.back()); deck.pop_back();
    dealerHand.push_back(deck.back()); deck.pop_back();
    playerHand.push_back(deck.back()); deck.pop_back();
    dealerHand.push_back(deck.back()); deck.pop_back();
}

void showHand(const string& name, const vector<Card>& hand) {
    cout << name << "'s hand: ";
    for (const auto& card : hand) {
        cout << "[" << card.rank << card.suit << "] ";
    }
    cout << endl;
}


int main() { // Renombrar a blackjack después
    vector<Card> deck = createDeck();
    vector<Card> playerHand;
    vector<Card> dealerHand;

    dealInitialCards(deck, playerHand, dealerHand);

    showHand("Player", playerHand);
    showHand("Dealer", dealerHand); // Más adelante podrías ocultar la segunda carta

    return 0;
}