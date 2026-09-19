#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;

    if (op == '*' || op == '/')
        return 2;

    if (op == '^')
        return 3;

    return 0;
}

int main() {
    string infix, postfix = "";
    stack<char> st;

    cout << "Enter infix expression: ";
    getline(cin, infix);

    for (char ch : infix) {

        // Ignore spaces
        if (ch == ' ')
            continue;

        // If operand, directly add to postfix
        if (isalnum(ch)) {
            postfix += ch;
        }

        // Opening bracket
        else if (ch == '(') {
            st.push(ch);
        }

        // Closing bracket
        else if (ch == ')') {

            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }

            // Remove '('
            if (!st.empty()) {
                st.pop();
            }
        }

        // Operator
        else {
            while (!st.empty() &&
                   st.top() != '(' &&
                   precedence(st.top()) >= precedence(ch)) {

                postfix += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    // Add remaining operators
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}