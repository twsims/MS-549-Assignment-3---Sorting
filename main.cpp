#include "functions.h"
#include <iostream>

using namespace std;

int main() {
    srand(time(0));
    vector<int> array;
    int choice;

    do {
        displayMenu();
        cout << "Please make your selection: ";
        cin >> choice;

        // Input validation loop for menu choice
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) { // Check if the input is not a valid integer
            cin.clear(); // Clear the error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            cout << "Not an integer. Please enter an integer between 1 and 6.\n";
            continue; // Skip to the next iteration of the menu loop
        }

        switch (choice) {
        case 1: {
            int size;
            cout << "Enter array size: ";
            cin >> size;
            fillArray(array, size);
            cout << "Array filled with random values.\n";
            break;
        }
        case 2: {
            if (array.empty()) {
                cout << "Array is empty. Fill the array first.\n";
                break;
            }

            collectPerformanceData();
            break;
        }
        case 3: {
            printArray(array);
            break;
        }
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

