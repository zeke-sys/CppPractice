#include <iostream>
#include <iomanip> // for std::setprecision

using namespace std;

int main() {
    // Write a program that reads in a sequence of integers from the user and prints the largest and smallest integers in the sequence
    // The user will enter Q to indicate the end of the sequence.

    int number;
    int largest = INT_MIN; // Initialize to the smallest possible integer
    int smallest = INT_MAX; // Initialize to the largest possible integer

    cout << "Enter integers (type 'Q' to quit):" << endl;

    // Loop to read integers until the user enters 'Q'
    // Use a string to handle both integer input and the quit command
    while (true) {
        // Read input as a string to handle both integers and the quit command
        string input;
        cin >> input;

        // Check if the user wants to quit
        if (input == "Q" || input == "q") {
            break;
        }

        // Convert input to integer
        try {
            number = stoi(input);
        } catch (const invalid_argument&) {
            cout << "Invalid input. Please enter an integer or 'Q' to quit." << endl;
            continue;
        }

        // Update largest and smallest
        if (number > largest) {
            largest = number;
        }
        if (number < smallest) {
            smallest = number;
        }
    }
    // Check if any valid numbers were entered
    if (largest == INT_MIN && smallest == INT_MAX) {
        cout << "No valid integers were entered." << endl;
    } else if (largest == smallest) {
        cout << "All entered integers are the same: " << largest << endl;
    } else {
        cout << "Largest integer: " << largest << endl;
        cout << "Smallest integer: " << smallest << endl;
    }

    return 0; // End of main function
    
}