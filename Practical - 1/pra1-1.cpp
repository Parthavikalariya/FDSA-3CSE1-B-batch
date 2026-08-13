#include <iostream>
using namespace std;

int main() {
    int n, h;

    cout << "Enter number of bakery items: ";
    cin >> n;

    cout << "Enter number of hours: ";
    cin >> h;

    string name[n];

    cout << "\nEnter items:\n";
    for (int i = 0; i < n; i++){
        cin >> name[i];
    }

    h = h % n;

    cout << "\nAfter " << h << " hours:\n";
    cout << "---------------------------\n";

    for (int i = h; i < n; i++){
        cout << name[i] << "\n";
    }

    for (int i = 0; i < h; i++){
        cout << name[i] << "\n";
    }

    cout << "---------------------------\n";

    return 0;
}