#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of issues books: ";
    cin >> n;

    int arr[n];

    cout << "Enter book IDs: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Duplicate book IDs: ";

    for (int i = 0; i < n; i++)
    {

        bool found = false;

        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            continue;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                cout << arr[i] << " ";
                break;
            }
        }
    }

    return 0;
}