/*
    CS250 Program 1
    Program to assign seats on a plane, given number of rows and seats
    Author: Braden Seeber
    Due Date: 9/25/2024
*/
#include <iostream>
#include <vector>
#include <stdexcept>  // For exceptions
#include <cassert>    // For assertions

using namespace std;

// Function to display the seating chart
void displaySeating(const vector<vector<char>>& seating, int seatsPerRow) {
    cout << "Seating Chart:" << endl;

    // Display the seat letters at the top
    cout << "    ";
    for (int i = 0; i < seatsPerRow; ++i) {
        cout << char('A' + i) << "   ";
    }
    cout << endl;

    // Display the rows and seats along side
    for (int i = 0; i < seating.size(); ++i) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < seatsPerRow; ++j) {
            cout << seating[i][j] << "   ";
        }
        cout << endl;
    }
}

// Function to initialize the seating chart with unassigned seats
vector<vector<char>> initializeSeating(int rows, int seatsPerRow) {
    return vector<vector<char>>(rows, vector<char>(seatsPerRow, '0'));
}

int main() {
    int rows, seatsPerRow;

    // Ask for the number of rows and seats per row
    cout << "Enter the number of rows: " << endl;
    cin >> rows;
    cout << "Enter the number of seats per row: " << endl;
    cin >> seatsPerRow;

    // Simple assertion: number of rows and seats must be positive
    assert(rows > 0 && seatsPerRow > 0);

    // Initialize the seating chart
    vector<vector<char>> seating = initializeSeating(rows, seatsPerRow);

    char continueBooking = 'y';
    while (continueBooking == 'y') {
        displaySeating(seating, seatsPerRow);

        int row;
        char seatLetter;
        cout << "Enter the row number (1-" << rows << "): " << endl;
        cin >> row;

        cout << "Enter the seat letter (A-" << char('A' + seatsPerRow - 1) << "): " << endl;
        cin >> seatLetter;

        // Exception handling for invalid seat letter input
        try {
            if (seatLetter < 'A' || seatLetter >= 'A' + seatsPerRow) {
                throw invalid_argument("Invalid seat letter, enter a valid letter.");
            }

            // Convert the seat letter to an index, so A is 0, B is 1, etc.
            int seatIndex = seatLetter - 'A';

            // Check if the seat is available
            if (seating[row - 1][seatIndex] == '0') {
                // Assign the seat
                seating[row - 1][seatIndex] = 'X';
                cout << "Seat assigned" << endl;
            } else {
                cout << "Seat is taken. Try another seat." << endl;
            }
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
            continue;  // Ask for input again after catching the exception
        }

        // Ask if the user wants to book another seat
        cout << "Do you want to book another seat? (y/n): ";
        cin >> continueBooking;
    }

    // Final seating chart
    displaySeating(seating, seatsPerRow);

    return 0;
}
