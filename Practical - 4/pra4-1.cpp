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

    // 1. Insert critical patient at front
    void insertFront(int token) {
        Node* newNode = new Node(token);
        newNode->next = head;
        head = newNode;
    }

    // 2. Insert routine patient at end
    void insertEnd(int token) {
        Node* newNode = new Node(token);

        // If queue is empty
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

    // 3. Insert patient at a specific position
    void insertAtPosition(int token, int position) {

        if (position <= 1) {     // Position 1 means front
            insertFront(token);
            return;
        }

        Node* newNode = new Node(token);
        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        // If position is greater than current length, insert at the end
        if (temp == nullptr) {
            insertEnd(token);
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;

        cout << "Queue: ";

        while (temp != nullptr) {
            cout << temp->token << " ";
            temp = temp->next;
        }
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
    cout << "----------------------\n";

    cout << "\nCritical patient (Token 101) added at front:\n";
    queue.insertFront(101);
    queue.display();

    cout << "\nRoutine patient (Token 102) added at end:\n";
    queue.insertEnd(102);
    queue.display();

    cout << "\nRoutine patient (Token 103) added at end:\n";
    queue.insertEnd(103);
    queue.display();

    cout << "\nCritical patient (Token 104) added at front:\n";
    queue.insertFront(104);
    queue.display();

    cout << "\nPriority patient (Token 105) inserted at position 3:\n";
    queue.insertAtPosition(105, 3);
    queue.display();

    // Position (20) greater than length
    cout << "\nPriority patient (Token 106) inserted at position 20:\n";
    queue.insertAtPosition(106, 20);
    queue.display();

    return 0;
}