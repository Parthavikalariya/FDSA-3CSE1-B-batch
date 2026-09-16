#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = NULL;
        next = NULL;
    }
};

class Playlist {
    Node* head;
    Node* tail;

public:
    Playlist() {
        head = NULL;
        tail = NULL;
    }

    // Insert at beginning
    void insertBeginning(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        cout << "Song added at beginning.\n";
        display();
    }

    // Insert at end
    void insertEnd(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        cout << "Song added at end.\n";
        display();
    }

    // Insert after specific song
    void insertAfter(string target, string song) {
        Node* temp = head;

        while (temp != NULL && temp->song != target) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Song not found.\n";
            return;
        }

        Node* newNode = new Node(song);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        else {
            tail = newNode;
        }

        temp->next = newNode;

        cout << "Song inserted after " << target << ".\n";
        display();
    }

    // Delete first song
    void deleteFirst() {
        if (head == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* temp = head;

        if (head == tail) {
            head = tail = NULL;
        }
        else {
            head = head->next;
            head->prev = NULL;
        }

        delete temp;

        cout << "First song removed.\n";
        display();
    }

    // Count songs
    int countSongs() {
        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // Display songs
    void display() {
        if (head == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* temp = head;

        cout << "Playlist: ";

        while (temp != NULL) {
            cout << temp->song;

            if (temp->next != NULL)
                cout << " <-> ";

            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {

    Playlist p;
    int choice;
    string song, target;

    do {
        cout << "\n1. Add at Beginning";
        cout << "\n2. Add at End";
        cout << "\n3. Insert After Song";
        cout << "\n4. Delete First Song";
        cout << "\n5. Count Songs";
        cout << "\n6. Display Playlist";
        cout << "\n0. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter song name: ";
            cin >> song;
            p.insertBeginning(song);
            break;

        case 2:
            cout << "Enter song name: ";
            cin >> song;
            p.insertEnd(song);
            break;

        case 3:
            cout << "Enter current song: ";
            cin >> target;

            cout << "Enter new song: ";
            cin >> song;

            p.insertAfter(target, song);
            break;

        case 4:
            p.deleteFirst();
            break;

        case 5:
            cout << "Total Songs = "
                 << p.countSongs() << endl;
            break;

        case 6:
            p.display();
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