#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

struct Node {
    string patient;
    Node* next;

    Node(string p) {
        patient = p;
        next = NULL;
    }
};

class HospitalQueue {
private:
    Node* front;
    Node* rear;

public:
    HospitalQueue() {
        front = NULL;
        rear = NULL;
    }

    void arrive(string patient) {
        Node* newNode = new Node(patient);

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void attend() {
        if (front == NULL) {
            printf("Ward is empty. No patient to attend.\n");
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    void printFront() {
        if (front == NULL)
            printf("Current Front Patient: None\n");
        else
            printf("Current Front Patient: %s\n", front->patient.c_str());
    }
};

int main() {
    HospitalQueue q;

    int n;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        string operation;

        printf("\nEnter operation (arrive/attend): ");
        cin >> operation;

        if (operation == "arrive") {

            string patient;

            printf("Enter patient name: ");
            cin >> patient;

            q.arrive(patient);
        }
        else if (operation == "attend") {
            q.attend();
        }
        else {
            printf("Invalid operation!\n");
        }

        q.printFront();
    }

    return 0;
}