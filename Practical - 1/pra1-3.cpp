#include <iostream>
#include <sstream>
#include <cctype>
using namespace std;

int main()
{
    string sentence, word, longestWord;
    int maxLength = 0;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    stringstream ss(sentence);

    while (ss >> word)
    {

        string clean = "";

        for (char ch : word)
        {
            if (isalnum(ch))
                clean += ch;
        }

        if (clean.length() > maxLength)
        {
            maxLength = clean.length();
            longestWord = clean;
        }
    }

    cout << "Longest word: " << longestWord << endl;
    cout << "Length: " << maxLength << endl;

    return 0;
}