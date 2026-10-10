#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter maximum number of tokens: ";
    cin >> n;

    int queue[100];

    int front = -1;
    int rear = -1;

    int choice, token;

    do {
        cout << "\n1. Join (Issue Token)";
        cout << "\n2. Serve Token";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                // Queue Full
                if ((rear + 1) % n == front) {
                    cout << "Error: Token counter is full." << endl;
                }
                else {
                    cout << "Enter token number: ";
                    cin >> token;

                    // First token
                    if (front == -1) {
                        front = 0;
                        rear = 0;
                    }
                    else {
                        rear = (rear + 1) % n;
                    }

                    queue[rear] = token;

                    cout << "Current Front Token: "
                         << queue[front] << endl;
                }
                break;

            case 2:
                // Queue Empty
                if (front == -1) {
                    cout << "Error: Token counter is empty." << endl;
                }
                else {
                    cout << "Served Token: "
                         << queue[front] << endl;

                    // Only one token
                    if (front == rear) {
                        front = -1;
                        rear = -1;
                    }
                    else {
                        front = (front + 1) % n;
                    }

                    if (front != -1) {
                        cout << "Current Front Token: "
                             << queue[front] << endl;
                    }
                    else {
                        cout << "No token available." << endl;
                    }
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