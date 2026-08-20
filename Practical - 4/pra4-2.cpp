#include <iostream>
using namespace std;

struct Node {
    int token;
    Node* next;

    Node(int t) {
        token = t;
        next = nullptr;
    }
};

class PatientQueue {
private:
    Node* head;

public:
    PatientQueue() {
        head = nullptr;
    }

    // Insert at front
    void insertFront(int token) {
        Node* newNode = new Node(token);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertEnd(int token) {
        Node* newNode = new Node(token);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Insert at specific position
    void insertAtPosition(int token, int position) {
        if (position <= 1) {
            insertFront(token);
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        // If position is greater than queue length
        if (temp == nullptr) {
            cout << "Invalid position! Patient not inserted.\n";
            return;
        }

        Node* newNode = new Node(token);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Forward traversal
    void displayForward() {
        Node* temp = head;

        cout << "Queue (Front to Back): ";

        while (temp != nullptr) {
            cout << temp->token << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Delete patient by token value
    void deleteByValue(int token) {
        // Empty queue
        if (head == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }

        // If first node contains the token
        if (head->token == token) {
            Node* temp = head;
            head = head->next;
            delete temp;

            cout << "Token " << token << " deleted.\n";
            return;
        }

        Node* current = head;

        // Find the node before the node to delete
        while (current->next != nullptr &&
               current->next->token != token) {
            current = current->next;
        }

        // Token not found
        if (current->next == nullptr) {
            cout << "Token " << token << " not found.\n";
            return;
        }

        // Delete the required node
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;

        cout << "Token " << token << " deleted.\n";
    }

    // Reverse printing using recursion
    void displayReverse(Node* node) {
        if (node == nullptr) {
            return;
        }

        // Go to the end first
        displayReverse(node->next);

        // Print while returning
        cout << node->token << " ";
    }

    // Public function for reverse printing
    void displayReverse() {
        cout << "Queue (Back to Front): ";

        displayReverse(head);

        cout << endl;
    }

    ~PatientQueue() {
        Node* temp;

        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    PatientQueue queue;

    cout << "Hospital Patient Queue\n";
    cout << "----------------------\n\n";

    // Insert patients
    queue.insertEnd(101);
    queue.insertEnd(102);
    queue.insertEnd(103);
    queue.insertFront(104);
    queue.insertAtPosition(105, 3);

    // Forward traversal
    cout << "Initial Queue:\n";
    queue.displayForward();

    // Delete patient
    cout << "\nDeleting Token 102...\n";
    queue.deleteByValue(102);

    // Display after deletion
    queue.displayForward();

    // Reverse printing
    cout << "\nEnd-of-day Audit:\n";
    queue.displayReverse();

    // Forward traversal again
    cout << "\nFull Queue:\n";
    queue.displayForward();

    return 0;
}