#include "blackjack.h" // <>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

// Function that shuffles the deck to create 
void shuffleDeck(vector<Card>& deck) {
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
void showHand(const string& name, const vector<Card>& hand, bool hideSecondCard = false) {
    cout << name << "'s hand: ";
    for (size_t i = 0; i < hand.size(); ++i) {
        if (hideSecondCard && i == 1) {
            cout << "[**] ";
        } else {
            cout << "[" << hand[i].rank << hand[i].suit << "] ";
        }
    }
    cout << endl;
}

//Function for the player's turn
bool playerTurn(vector<Card>& playerHand, vector<Card>& deck) {
    while (true) {
        int total = calculateHandValue(playerHand);
        showHand("Player", playerHand, false);
        cout << "\nYour total: " << total << endl;

        if (total == 21){
            cout << "Blackjack!" << endl;
            return true;
        }

        if (total > 21) {
            return false;
        }

        char choice;
        cout << "\nDo you want to [H]it or [S]tand?" << endl;
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
    }
    showHand("Dealer", dealerHand);
    cout << "\nDealer total: " << calculateHandValue(dealerHand) <<endl;
}

// Game's main function
int main() { // Renombrar a blackjack después

    cout << "Blackjack" << endl; // Por decorar
    int playerWins = 0;
    int dealerWins = 0;

    for (int roundCount = 0; roundCount < 5; roundCount++) {
        cout << "Round: " << roundCount + 1 << endl;
        srand(time(0));
        vector<Card> deck = createDeck();
        vector<Card> playerHand;
        vector<Card> dealerHand;

        dealInitialCards(deck, playerHand, dealerHand);

        showHand("Dealer", dealerHand, true);

        bool stillInGame = playerTurn(playerHand, deck);

        if (stillInGame && calculateHandValue(playerHand) < 21) {
            dealerTurn(dealerHand, deck);
        }   

        int playerTotal = calculateHandValue(playerHand);
        int dealerTotal = calculateHandValue(dealerHand);

        cout << endl;

        if (playerTotal > 21) {
            cout << "You busted! Dealer wins." << endl;
            dealerWins ++;
        } else if (dealerTotal > 21) {
            cout << "Dealer busted! You win!" << endl;
            playerWins ++;
        } else if (playerTotal > dealerTotal) {
            cout << "You win!" << endl;
            playerWins ++;
        } else if (playerTotal < dealerTotal) {
            cout << "Dealer wins!" << endl;
            dealerWins ++;
        } else {
            cout << "It's a tie!" << endl;
        }
        cout << endl;
    }

    cout << "\n=== Final Score ===\n";
    cout << "Player's Wins: " << playerWins << endl;
    cout << "Dealer's Wins: " << dealerWins << endl;

    if (playerWins > dealerWins) {
        cout << "You are the overall winner!" << endl;
    } else if (dealerWins > playerWins) {
        cout << "Dealer wins the match!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }
    return 0;
}