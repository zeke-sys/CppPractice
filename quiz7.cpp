#include <iostream>
#include <iomanip> // for std::setprecision

using namespace std;

int main() {
    //This program reads two integers from a user and computes the sum of all odd numbers between them, inclusive.

    int num1, num2;
    int sum = 0;

    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    // Ensure num1 is less than or equal to num2
    if (num1 > num2) {
        swap(num1, num2);
    }

    // Calculate the sum of odd numbers between num1 and num2, inclusive
    for (int i = num1; i <= num2; ++i) {
        if (i % 2 != 0) { // Check if the number is odd
            sum += i;
        }
    }

    cout << "The sum of all odd numbers between " << num1 << " and " << num2 << " is: " << sum << endl;


    return 0;
}