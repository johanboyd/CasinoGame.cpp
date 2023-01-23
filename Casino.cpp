#include <iostream>
#include <cstdlib>
#include <ctime>

int balance = 100;

void play() {
    std::cout << "You have $" << balance << "." << std::endl;
    std::cout << "How much would you like to bet? (Enter 0 to quit) ";
    int bet;
    std::cin >> bet;

    if (bet == 0) {
        std::cout << "Thanks for playing!" << std::endl;
        return;
    }
    if (bet > balance) {
        std::cout << "You don't have that much money." << std::endl;
        return;
    }

    balance -= bet;

    srand(time(0));
    int drawnCard = rand() % 13 + 1;

    std::cout << "The card is a " << drawnCard << "." << std::endl;
    std::cout << "Will the next card be higher or lower? (h/l) ";
    char guess;
    std::cin >> guess;

    int nextCard = rand() % 13 + 1;
    std::cout << "The next card is a " << nextCard << "." << std::endl;

    if ((guess == 'h' && nextCard > drawnCard) || (guess == 'l' && nextCard < drawnCard)) {
        std::cout << "Congratulations, you won $" << bet << "!" << std::endl;
        balance += bet * 2;
    } else {
        std::cout << "Sorry, you lost $" << bet << "." << std::endl;
    }
}

int main() {
    std::cout << "Welcome to the High-Low game!" << std::endl;

    while (balance > 0) {
        play();
    }

    std::cout << "You have no more money. Thanks for playing!" << std::endl;

    return 0;
}
