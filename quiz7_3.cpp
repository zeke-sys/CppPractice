#include <iostream>
#include <limits> // for std::numeric_limits
#include <string> // for std::string
#include <stdexcept> // for std::invalid_argument

using namespace std;

//Write a program that reads in a sequence of integers from the user and prints the number of even and odd inputs. 
//The user will enter Q to indicate the end of the sequence. Note that the sequence could be of any length.

int main() {
    string input;
    int evenCount = 0;
    int oddCount = 0;

    cout << "Enter integers and type Q to quit: " << endl;

    while (true) {
        cin >> input;

        // Check if the user wants to quit
        if (input == "Q" || input == "q") {
            break;
        }

        // Convert input to integer
        try {
            int number = stoi(input);
            if (number % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        } catch (const invalid_argument&) {
            cout << "Invalid input. Please enter an integer or 'Q' to quit." << endl;
        }
    }

    cout << "Number of evens is " << evenCount << endl;
    cout << "Number of odds is " << oddCount << endl;

    return 0;
}