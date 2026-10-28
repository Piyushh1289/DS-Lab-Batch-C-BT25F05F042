
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *head = NULL;

// INSERT AT BEGINNING
void insertBeginning(int value)
{
    Node *newNode = new Node;

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

// INSERT AT END
void insertEnd(int value)
{
    Node *newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// INSERT AT MIDDLE / POSITION
void insertMiddle(int value, int position)
{
    if (position <= 1)
    {
        insertBeginning(value);
        return;
    }

    if (head == NULL)
    {
        cout << "List is empty! Invalid position.\n";
        return;
    }

    Node *temp = head;

    for (int i = 1; i < position - 1; i++)
    {
        if (temp->next == NULL)
        {
            cout << "Invalid position!\n";
            return;
        }

        temp = temp->next;
    }

    Node *newNode = new Node;

    newNode->data = value;
    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// DELETE FROM BEGINNING
void deleteBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }

    Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
}

// DELETE FROM END
void deleteEnd()
{
    if (head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev == NULL)
        head = NULL;
    else
        temp->prev->next = NULL;

    delete temp;
}

// DELETE FROM MIDDLE / POSITION
void deleteMiddle(int position)
{
    if (head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }

    if (position <= 1)
    {
        deleteBeginning();
        return;
    }

    Node *temp = head;

    for (int i = 1; i < position; i++)
    {
        if (temp == NULL)
        {
            cout << "Invalid position!\n";
            return;
        }

        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Invalid position!\n";
        return;
    }

    temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

// DISPLAY FORWARD
void displayForward()
{
    if (head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }

    Node *temp = head;

    cout << "Forward: ";

    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// DISPLAY BACKWARD
void displayBackward()
{
    if (head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    cout << "Backward: ";

    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }

    cout << "NULL\n";
}

// MAIN FUNCTION
int main()
{
    int choice, value, position;

    while (true)
    {
        cout << "\n===== DOUBLY LINKED LIST =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at Middle / Position\n";
        cout << "3. Insert at End\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from Middle / Position\n";
        cout << "6. Delete from End\n";
        cout << "7. Display Forward\n";
        cout << "8. Display Backward\n";
        cout << "9. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 9)
        {
            cout << "Program terminated.\n";
            break;
        }

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                insertMiddle(value, position);
                break;

            case 3:
                cout << "Enter value: ";
                cin >> value;
                insertEnd(value);
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                cout << "Enter position: ";
                cin >> position;
                deleteMiddle(position);
                break;

            case 6:
                deleteEnd();
                break;

            case 7:
                displayForward();
                break;

            case 8:
                displayBackward();
                break;

            default:
                cout << "Invalid choice!\n";
        }
    }

    // Free remaining nodes
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}