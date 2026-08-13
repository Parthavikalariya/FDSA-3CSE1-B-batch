#include <iostream>
using namespace std;

// Iterative Binary Search
int iterativeBinarySearch(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        else if (arr[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

// Recursive Binary Search
int recursiveBinarySearch(int arr[], int low, int high, int target)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;

    if (arr[mid] < target)
        return recursiveBinarySearch(arr, mid + 1, high, target);

    return recursiveBinarySearch(arr, low, mid - 1, target);
}

int main()
{
    int size;

    cout << "Enter number of book codes: ";
    cin >> size;

    int arr[size];

    cout << "Enter sorted book codes:\n";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    int target;
    cout << "Enter book code to search: ";
    cin >> target;

    int result1 = iterativeBinarySearch(arr, size, target);

    if (result1 != -1)
        cout << "\nIterative Search: Book code found at index " << result1 << endl;
    else
        cout << "\nIterative Search: Book code not found." << endl;

    int result2 = recursiveBinarySearch(arr, 0, size - 1, target);

    if (result2 != -1)
        cout << "Recursive Search: Book code found at index " << result2 << endl;
    else
        cout << "Recursive Search: Book code not found." << endl;

    return 0;
}