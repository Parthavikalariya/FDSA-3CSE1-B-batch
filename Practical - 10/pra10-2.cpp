#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> shelves[10];
    int n, code;

    cout << "Enter number of books: ";
    cin >> n;

    cout << "Enter book codes:\n";
    for (int i = 0; i < n; i++) {
        cin >> code;
        int index = code % 10;
        shelves[index].push_back(code);
    }

    cout << "Shelf contents:\n";
    for (int i = 0; i < 10; i++) {
        cout << i << ": ";
        for (int code : shelves[i])
            cout << code << " ";
        cout << endl;
    }

    return 0;
}
