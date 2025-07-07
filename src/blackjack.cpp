#include "blackjack.h" // <>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

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

// Function that gives colors the suits
string colorSuit(const string& suit) {
    if (suit == "H" || suit == "D") return "\033[31m" + suit + "\033[0m"; // Red
    return "\033[34m" + suit + "\033[0m"; // Blue
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

// Function that verificates if there is a natural blackjack
bool isBlackjack(const vector<Card>& hand) {
    return hand.size() == 2 && calculateHandValue(hand) == 21;
}

// Function that shows the hands
void showHand(const string& name, const vector<Card>& hand, bool hideSecondCard = false) {
    cout << "\033[93m" << name << "'s hand: \033[0m";
    for (size_t i = 0; i < hand.size(); ++i) {
        if (hideSecondCard && i == 1) {
            cout << "[**] ";
        } else {
            string coloredSuit = colorSuit(hand[i].suit);
            cout << "[" << hand[i].rank << coloredSuit << "] ";
        }
    }
    cout << endl;
}

//Function for the player's turn
bool playerTurn(vector<Card>& playerHand, vector<Card>& deck) {
    while (true) {
        int total = calculateHandValue(playerHand);
        showHand("Player", playerHand, false);
        cout << "\033[96m\nYour total: \033[0m" << total << endl;

        if (total == 21){
            cout << "\033[92m21!\033[0m" << endl;
            return true;
        }

        if (total > 21) {
            return false;
        }

        char choice;
        cout << "\033[33m\nDo you want to [H]it or [S]tand?\033[0m" << endl;
        cin >> choice;
        cin.clear();
        cin.ignore(10000, '\n');
        
        if (choice == 'H' || choice == 'h') {
            playerHand.push_back(deck.back());
            deck.pop_back();
        } else if (choice == 'S' || choice == 's') {
            break;
        } else {
            cout << "\033[31mInvalid choice, try again\033[33m" << endl;
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
    cout << "\033[96m\nDealer total: \033[0m" << calculateHandValue(dealerHand) <<endl;
}

// Game's main function
bool playblackjack() {

    srand(time(0));
    cout << "\033[32m";
    cout << R"(
    
     ____  _            _       _            _    
    | __ )| | __ _  ___| | __  | | __ _  ___| | __
    |  _ \| |/ _` |/ __| |/ /  | |/ _` |/ __| |/ /
    | |_) | | (_| | (__|   < |_| | (_| | (__|   < 
    |____/|_|\__,_|\___|_|\_\___/ \__,_|\___|_|\_\
    
    )";
    cout << "        Welcome to Blackjack - Beat the Dealer!\n";
    cout << "\033[0m\n";

    int playerWins = 0;
    int dealerWins = 0;

    for (int roundCount = 0; roundCount < 5; roundCount++) {
        cout << "\033[36mRound: \033[0m" << roundCount + 1 << endl;
        vector<Card> deck = createDeck();
        vector<Card> playerHand;
        vector<Card> dealerHand;

        dealInitialCards(deck, playerHand, dealerHand);

        bool playerBJ = isBlackjack(playerHand);
        bool dealerBJ = isBlackjack(dealerHand);

        if (playerBJ || dealerBJ) {
            showHand("Dealer", dealerHand);

            int playerTotal = calculateHandValue(playerHand);
            int dealerTotal = calculateHandValue(dealerHand);

            cout << "\n";

            if (playerBJ && dealerBJ) {
                cout << "\033[33mBoth have Blackjack! It's a tie!\033[0m" << endl;
            } else if (playerBJ) {
                cout << "\033[32mBlackjack! You win!\033[0m" << endl;
                showHand("Player", playerHand);
                playerWins++;
            } else {
                cout << "\033[31mDealer has Blackjack! Dealer wins!\033[0m" << endl;
                dealerWins++;
            }
        cout << endl;
        continue;
        }

        showHand("Dealer", dealerHand, true);

        bool stillInGame = playerTurn(playerHand, deck);

        if (stillInGame && calculateHandValue(playerHand) < 21) {
            dealerTurn(dealerHand, deck);
        }   

        int playerTotal = calculateHandValue(playerHand);
        int dealerTotal = calculateHandValue(dealerHand);

        cout << endl;

        if (playerTotal > 21) {
            cout << "\033[31mYou busted! Dealer wins.\033[0m" << endl;
            dealerWins ++;
        } else if (dealerTotal > 21) {
            cout << "\033[32mDealer busted! You win!\033[0m" << endl;
            playerWins ++;
        } else if (playerTotal > dealerTotal) {
            cout << "\033[32mYou win!\033[0m" << endl;
            playerWins ++;
        } else if (playerTotal < dealerTotal) {
            cout << "\033[31mDealer wins!\033[0m" << endl;
            dealerWins ++;
        } else {
            cout << "\033[33mIt's a tie!\033[0m" << endl;
        }
        cout << endl;
    }

    cout << "\033[36m\n=== Final Score ===\n\033[0m";
    cout << "\033[32mPlayer's Wins: \033[0m" << playerWins << endl;
    cout << "\033[31mDealer's Wins: \033[0m" << dealerWins << endl;

    if (playerWins > dealerWins) {
        cout << "\033[32mYou are the overall winner!\033[0m" << endl;
        return true;
    } else if (dealerWins > playerWins) {
        cout << "\033[31mDealer wins the match!\033[0m" << endl;
        return false;
    } else {
        cout << "\033[33mIt's a draw!\033[0m" << endl;
        return false;
    }
    return 0;
}