#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter maximum number of trays: ";
    cin >> n;

    int trays[100];
    int top = -1;

    int choice, tray;

    do {
        cout << "\n1. Place Tray (Push)";
        cout << "\n2. Take Tray (Pop)";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                if (top == n - 1) {
                    cout << "Error: Stack is full." << endl;
                }
                else {
                    cout << "Enter tray number: ";
                    cin >> tray;

                    top++;
                    trays[top] = tray;

                    cout << "Current Top Tray: "
                         << trays[top] << endl;
                }
                break;

            case 2:
                if (top == -1) {
                    cout << "Error: Stack is empty." << endl;
                }
                else {
                    cout << "Removed Tray: "
                         << trays[top] << endl;

                    top--;

                    if (top == -1)
                        cout << "No tray available." << endl;
                    else
                        cout << "Current Top Tray: "
                             << trays[top] << endl;
                }
                break;

            case 3:
                cout << "Program stopped." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }

    } while (choice != 3);

    return 0;
}