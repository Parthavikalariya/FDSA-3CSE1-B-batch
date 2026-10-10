#include <iostream>
using namespace std;

int main() {
    int table[10];
    for (int i = 0; i < 10; i++)
        table[i] = -1;

    int n, id;
    cout << "Enter number of student IDs: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> id;

        int h1 = id % 10;
        int h2 = 7 - (id % 7);
        int j = 0;

        while (j < 10) {
            int index = (h1 + j * h2) % 10;

            if (table[index] == -1) {
                table[index] = id;
                break;
            }
            j++;
        }

        if (j == 10)
            cout << "Hash table full for ID " << id << endl;
    }

    cout << "Hash table:\n";
    for (int i = 0; i < 10; i++)
        cout << i << ": " << table[i] << endl;

    return 0;
}
