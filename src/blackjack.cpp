#include "blackjack.h" // <>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

// Function that shuffles the deck to create 
void shuffleDeck(vector<Card>& deck) {
    srand(time(0));
    for (int i = 0; i < deck.size(); ++i) {
        int j = rand() % deck.size();
        swap(deck[i], deck[j]);
    }
}

// Function that creates the deck
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

// Function that deals the initial cards
void dealInitialCards(vector<Card>& deck, vector<Card>& playerHand, vector<Card>& dealerHand) {
    playerHand.push_back(deck.back()); deck.pop_back();
    dealerHand.push_back(deck.back()); deck.pop_back();
    playerHand.push_back(deck.back()); deck.pop_back();
    dealerHand.push_back(deck.back()); deck.pop_back();
}

// Function that calculates the value of the hands
int calculateHandValue(const vector<Card>& hand) {
    int total = 0;
    int aceCount = 0;

    for (const Card& card : hand) {
        total += card.value;
        if (card.rank == "A") {
            aceCount ++;
        }
    }

    while (total > 21 && aceCount > 0) {
        total -= 10;
        aceCount --;
    }

    return total;
}

// Function that shows the hands
void showHand(const string& name, const vector<Card>& hand) {
    cout << name << "'s hand: ";
    for (const auto& card : hand) {
        cout << "[" << card.rank << card.suit << "] ";
    }
    cout << endl;
}

//Function for the player's turn
void playerTurn(vector<Card>& playerHand, vector<Card>& deck) {
    while (true) {
        int total = calculateHandValue(playerHand);
        showHand("Player", playerHand);
        cout << "\nYour total: " << total << endl;

        if (total > 21) {
            cout << "You busted" << endl;
            break;
        }

        char choice;
        cout << "Do you want to [H]it or [S]tand?" << endl;
        cin >> choice;
        cin.clear();
        cin.ignore(10000, '\n');
        
        if (choice == 'H' || choice == 'h') {
            playerHand.push_back(deck.back());
            deck.pop_back();
        } else if (choice == 'S' || choice == 's') {
            break;
        } else {
            cout << "Invalid choice, try again" << endl;
        }
    }
}

//Function for the dealer's turn
void dealerTurn(vector<Card>& dealerHand, vector<Card>& deck) {
    while (calculateHandValue(dealerHand) < 17) {
        dealerHand.push_back(deck.back());
        deck.pop_back();
        showHand("Dealer", dealerHand);
    }
    cout << "\nDealer total: " << calculateHandValue(dealerHand) <<endl;
}


int main() { // Renombrar a blackjack después
    vector<Card> deck = createDeck();
    vector<Card> playerHand;
    vector<Card> dealerHand;

    dealInitialCards(deck, playerHand, dealerHand);

    showHand("Dealer", dealerHand); // Ocultar la segunda carta xd

    playerTurn(playerHand, deck);

    if (calculateHandValue(playerHand) <= 21) {
        dealerTurn(dealerHand, deck);
    }   

    return 0;
}