#include <iostream>
#include <string>
using namespace std;

// Singly Circular Linked List

class SNode {
public:
    string name;
    SNode* next;

    SNode(string n) {
        name = n;
        next = NULL;
    }
};

class SinglyCircular {
    SNode* head;

public:
    SinglyCircular() {
        head = NULL;
    }

    // Join at end
    void join(string name) {

        SNode* newNode = new SNode(name);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        }
        else {
            SNode* temp = head;

            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Delete student
    void leave(string name) {

        if (head == NULL) {
            cout << "Circle is empty.\n";
            return;
        }

        // Only one student
        if (head->next == head && head->name == name) {
            delete head;
            head = NULL;
            return;
        }

        // Delete head
        if (head->name == name) {

            SNode* last = head;

            while (last->next != head) {
                last = last->next;
            }

            SNode* temp = head;

            head = head->next;

            last->next = head;

            delete temp;

            return;
        }

        SNode* temp = head;

        while (temp->next != head &&
               temp->next->name != name) {

            temp = temp->next;
        }

        if (temp->next == head) {
            cout << "Student not found.\n";
            return;
        }

        SNode* del = temp->next;

        temp->next = del->next;

        delete del;
    }

    void display() {

        if (head == NULL) {
            cout << "Circle is empty.\n";
            return;
        }

        SNode* temp = head;

        cout << "Singly Circular: ";

        do {
            cout << temp->name << " -> ";
            temp = temp->next;

        } while (temp != head);

        cout << "(Back to "
             << head->name << ")\n";
    }
};

// Doubly Circular Linked List

class DNode {
public:
    string name;
    DNode* prev;
    DNode* next;

    DNode(string n) {
        name = n;
        prev = NULL;
        next = NULL;
    }
};

class DoublyCircular {
    DNode* head;

public:

    DoublyCircular() {
        head = NULL;
    }

    // Join at end
    void join(string name) {

        DNode* newNode = new DNode(name);

        if (head == NULL) {

            head = newNode;

            head->next = head;
            head->prev = head;
        }

        else {

            DNode* last = head->prev;

            last->next = newNode;

            newNode->prev = last;
            newNode->next = head;

            head->prev = newNode;
        }
    }

    // Delete student
    void leave(string name) {

        if (head == NULL) {
            cout << "Circle is empty.\n";
            return;
        }

        DNode* temp = head;

        do {

            if (temp->name == name) {

                // Only one node
                if (temp->next == temp) {

                    delete temp;
                    head = NULL;

                    return;
                }

                temp->prev->next = temp->next;

                temp->next->prev = temp->prev;

                if (temp == head) {
                    head = temp->next;
                }

                delete temp;

                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Student not found.\n";
    }

    void display() {

        if (head == NULL) {
            cout << "Circle is empty.\n";
            return;
        }

        DNode* temp = head;

        cout << "Doubly Circular: ";

        do {

            cout << temp->name << " <-> ";

            temp = temp->next;

        } while (temp != head);

        cout << "(Back to "
             << head->name << ")\n";
    }
};

int main() {

    SinglyCircular singly;
    DoublyCircular doubly;

    int choice;
    string name;

    do {

        cout << "\n1. Join Student";
        cout << "\n2. Leave Student";
        cout << "\n3. Display";
        cout << "\n0. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:

            cout << "Enter student name: ";
            cin >> name;

            singly.join(name);
            doubly.join(name);

            singly.display();
            doubly.display();

            break;

        case 2:

            cout << "Enter student name: ";
            cin >> name;

            singly.leave(name);
            doubly.leave(name);

            singly.display();
            doubly.display();

            break;

        case 3:

            singly.display();
            doubly.display();

            break;

        case 0:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}