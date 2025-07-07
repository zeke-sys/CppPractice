#include <iostream>
#include <string>
#include <iomanip> // for std::setprecision

using namespace std;
int main() {
    const double rate1 = 0.10; // 10% tax rate
    const double rate2 = 0.25; // 15% tax rate
    const double rate3 = 0.30; // 30% tax rate

    // Define the tax brackets for single and married filing jointly
    // These thresholds are based on the tax brackets for the year 2023
    const double rate1_single_threshold = 32000.0; // Single threshold for 10% tax rate
    const double rate1_married_threshold = 64000.0; // Married threshold for 10% tax rate
    const double rate2_single_threshold = 80000.0; // Single threshold for 15% tax rate
    const double rate2_married_threshold = 160000.0; // Married threshold for 15% tax rate
    const double rate3_single_threshold = 200000.0; // Single threshold for 30% tax rate
    const double rate3_married_threshold = 400000.0; // Married threshold for 30% tax rate

    double tax1 = 0.0; // Tax for single filer
    double tax2 = 0.0; // Tax for married filing jointly

    double income;
    cout << "Enter your income: ";
    cin >> income;

    cout << "Please enter your filing status (s for single, m for married filing jointly): ";
    char filingStatus;
    cin >> filingStatus;

    // Calculate tax based on filing status
    if (filingStatus == 's') {
        if (income <= rate1_single_threshold) {
            tax1 = income * rate1; // 10% tax rate
        } else if (income <= rate2_single_threshold) {
            tax1 = (rate1_single_threshold * rate1) + ((income - rate1_single_threshold) * rate2); // 15% tax rate
        } else if (income <= rate3_single_threshold) {
            tax1 = (rate1_single_threshold * rate1) + ((rate2_single_threshold - rate1_single_threshold) * rate2) + ((income - rate2_single_threshold) * rate3); // 30% tax rate
        } else {
            cout << "Income exceeds the maximum threshold for single filers." << endl;
            return 0;
        }
    } else if (filingStatus == 'm') {
        if (income <= rate1_married_threshold) {
            tax2 = income * rate1; // 10% tax rate
        } else if (income <= rate2_married_threshold) {
            tax2 = (rate1_married_threshold * rate1) + ((income - rate1_married_threshold) * rate2); // 15% tax rate
        } else if (income <= rate3_married_threshold) {
            tax2 = (rate1_married_threshold * rate1) + ((rate2_married_threshold - rate1_married_threshold) * rate2) + ((income - rate2_married_threshold) * rate3); // 30% tax rate
        } else {
            cout << "Income exceeds the maximum threshold for married filing jointly." << endl;
            return 0;
        }
    } else {
        cout << "Invalid filing status entered." << endl;
        return 0;
    }
    // Output the calculated tax
    cout << fixed << setprecision(2); // Set precision for output
    if (filingStatus == 's') {
        cout << "Your tax as a single filer is: $" << tax1 << endl;
    } else if (filingStatus == 'm') {
        cout << "Your tax as a married couple filing jointly is: $" << tax2 << endl;
    }

    /* Output the total tax
    double totalTax = (filingStatus == 's') ? tax1 : tax2; // Determine total tax based on filing status
    cout << "Total tax owed: $" << totalTax << endl; // Output the total tax owed
    */

    return 0; // Return success

}