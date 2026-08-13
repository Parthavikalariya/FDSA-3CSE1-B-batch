#include <iostream>
#include <string>
using namespace std;

// Iterative Linear Search
int iterativeSearch(string plates[], int n, string target) {
    for (int i = 0; i < n; i++) {
        if (plates[i] == target) {
            return i; 
        }
    }
    return -1;  // Not found
}

// Recursive Linear Search
int recursiveSearch(string plates[], int n, string target, int index) {
    if (index == n)
        return -1;   // Not found

    if (plates[index] == target)
        return index;   // Found

    return recursiveSearch(plates, n, target, index + 1);
}

int main() {
    int n;
    cout << "Enter number of license plates: ";
    cin >> n;

    string plates[n];

    cout << "Enter license plates:\n";
    for (int i = 0; i < n; i++) {
        cin >> plates[i];
    }

    string target;
    cout << "Enter target license plate: ";
    cin >> target;

    int result1 = iterativeSearch(plates, n, target);
    int result2 = recursiveSearch(plates, n, target, 0);

    cout << "---------------------------------------------------\n";

    if (result1 != -1)
        cout << "Iterative Search: Found at position " << result1 + 1 << endl;
    else
        cout << "Iterative Search: Not Found" << endl;

    cout << "---------------------------------------------------\n";

    if (result2 != -1)
        cout << "Recursive Search: Found at position " << result2 + 1 << endl;
    else
        cout << "Recursive Search: Not Found" << endl;

    cout << "---------------------------------------------------\n";
    
    return 0;
}