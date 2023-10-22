#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    
    srand(static_cast<unsigned>(time(nullptr)));
    int secretNumber = rand() % 100 + 1;
    
    int userGuess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Challenge!" << endl;

    while (true) {
        cout << "Take a guess (between 1 and 100): ";
        cin >> userGuess;
        attempts++;

        if (userGuess < 1 || userGuess > 100) {
            cout << "Please guess a number between 1 and 100." << endl;
        } else if (userGuess < secretNumber) {
            cout << "Your guess is too low. Try a higher number." << endl;
        } else if (userGuess > secretNumber) {
            cout << "Your guess is too high. Try a lower number." << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
            break;
        }
    }

    return 0;
}
