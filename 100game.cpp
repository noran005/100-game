#include <iostream>
using namespace std;

void game1() {
    // Initial setup
    cout << "100 Game" << endl;
    cout << "Initial score = 0" << endl;
    int score = 0;

    // Main game loop
    while (true) {
        // Iterate over players (1 and 2)
        for (int player : {1, 2}) {
            // Get input from the current player
            string input_number;
            cout << "Player " << player << ", enter a number (1-10): ";
            cin >> input_number;

            // Validate input to ensure it is a digit and within the allowed range
            while (input_number.find_first_not_of("0123456789") != string::npos || !(1 <= stoi(input_number) && stoi(input_number) <= 10)) {
                cout << "Invalid input. Please enter a valid number (1-10)." << endl;
                cout << "Player " << player << ", enter a number (1-10): ";
                cin >> input_number;
            }

            // Update the score based on the player's input
            score += stoi(input_number);

            // Check if the current player wins
            if (score == 100) {
                cout << "Score reached 100." << endl;
                cout << "Player " << player << " wins. Congrats!" << endl;
                return;
            }
                // Check if the score exceeds 100
            else if (score > 100) {
                cout << "Score exceeds 100. Player " << player << ", try again to ensure that the score doesn't exceed 100." << endl;

                // Adjust the score to be less than or equal to 100
                while (score > 100) {
                    // Subtract the last input to correct the score
                    score -= stoi(input_number);
                    // Get a new input from the player
                    cout << "Player " << player << ", enter a number (1-10): ";
                    cin >> input_number;

                    // Validate the new input
                    while (input_number.find_first_not_of("0123456789") != string::npos || !(1 <= stoi(input_number) && stoi(input_number) <= 10)) {
                        cout << "Invalid input. Please enter a valid number (1-10)." << endl;
                        cout << "Player " << player << ", enter a number (1-10): ";
                        cin >> input_number;
                    }

                    // Add the adjusted input to the score
                    score += stoi(input_number);
                }

                // Check if the player wins after adjustment
                if (score == 100) {
                    cout << "Score reached 100." << endl;
                    cout << "Player " << player << " wins. Congrats!" << endl;
                    return;
                }
            }
            else {
                // Print the score if it doesn't exceed 100
                cout << "Score: " << score << endl;
            }
        }
    }
}

int main() {
    // Run the game
    game1();

    return 0;
}
