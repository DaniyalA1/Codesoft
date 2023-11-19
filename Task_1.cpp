#include <iostream>
#include <ctime>
using namespace std;

// Function to generate a random number between 1 and 'max'
int generateRandomNumber(int max) {
    return (rand() % max) + 1;
}

int main(int argc, char** argv) {
    srand(time(NULL)); // Generate a random seed

    int remainingAttempts = 5; // Number of attempts allowed
    int guessedNumber;
    int proximity;
    int randomNumber = generateRandomNumber(10); // Generating random number between 1 and 10
    const string heartSymbol = "\u2764"; // Heart symbol

    while (remainingAttempts > 0) {
        // Display remaining attempts as hearts
        for (int i = 0; i < remainingAttempts; i++) {
            cout << heartSymbol;
        }
        cout << endl << "Enter your guess: ";
        cin >> guessedNumber;

        proximity = randomNumber - guessedNumber;

        if (proximity == 0) {
            break;
        } else if (proximity < 0) {
            cout << "Your guess is too high. Try Again!" << endl;
            remainingAttempts--;
        } else if (proximity > 0) {
            cout << "Your guess is too low. Try Again!" << endl;
            remainingAttempts--;
        }
    }

    if (remainingAttempts == 0) {
        cout << "You're out of attempts! The number was: " << randomNumber << endl;
    } else {
        cout << "Congratulations! You guessed the number: " << randomNumber << endl;
    }

    return 0;
}
