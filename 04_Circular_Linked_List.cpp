#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* last = nullptr;

// Insert at beginning
void insertBeginning(int data) {
    Node* newNode = new Node;
    newNode->data = data;

    if (last == nullptr) {
        last = newNode;
        newNode->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }

    cout << "Node inserted at beginning.\n";
}

// Insert at end
void insertEnd(int data) {
    Node* newNode = new Node;
    newNode->data = data;

    if (last == nullptr) {
        last = newNode;
        newNode->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    cout << "Node inserted at end.\n";
}

// Delete from beginning
void deleteBeginning() {
    if (last == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = last->next;

    if (last == temp) {
        last = nullptr;
    } else {
        last->next = temp->next;
    }

    delete temp;
    cout << "First node deleted.\n";
}

// Display
void display() {
    if (last == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = last->next;

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != last->next);

    cout << "(back to first node)\n";
}

int main() {
    int choice, data;

    do {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                insertBeginning(data);
                break;

            case 2:
                cout << "Enter data: ";
                cin >> data;
                insertEnd(data);
                break;

            case 3:
                deleteBeginning();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Program exited.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}