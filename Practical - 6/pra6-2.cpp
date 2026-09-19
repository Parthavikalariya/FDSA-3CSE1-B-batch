#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> history;

    history.push("Home");

    int choice;
    string page;

    while (true) {
        cout << "\n1. Visit Page";
        cout << "\n2. Back";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter page name: ";
            cin >> page;

            history.push(page);

            cout << "Current Page: " << history.top() << endl;
        }

        else if (choice == 2) {

            if (history.size() > 1) {
                history.pop();
                cout << "Current Page: " << history.top() << endl;
            }
            else {
                cout << "No previous page available." << endl;
                cout << "Current Page: " << history.top() << endl;
            }
        }

        else if (choice == 3) {
            cout << "Browser closed.";
            break;
        }

        else {
            cout << "Invalid choice.";
        }
    }

    return 0;
}