#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;

    Node(int data) {
        value = data;
        next = NULL;
    }
};

void insertAtStart(int data, Node *&head) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data, Node *&head) {
    Node *newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void insertAtPosition(int data, Node *&head, int position) {
    Node *newNode = new Node(data);
    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node *current = head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void displayList(Node *head) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }
    Node *current = head;
    while (current != NULL) {
        cout << current->value << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

void updateValue(Node *&head, int position, int newValue) {
    Node *current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    current->value = newValue;
}

void deleteAtPosition(int position, Node *&head) {
    if (position == 0) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *current = head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
}

int main() {
    int userChoice;
    Node *head = NULL;
    int inputValue;

    do {
        cout << "--------- PLEASE SELECT OPTION ---------" << endl;
        cout << "Press : 1 Insert/create" << endl;
        cout << "Press : 2 Read/Select/Fetch/Access/Itreate/Transversal" << endl;
        cout << "Press : 3 Update" << endl;
        cout << "Press : 4 Delete" << endl;
        cout << "Press : 0 Exit the program" << endl;
        cout << "Enter above option: ";
        cin >> userChoice;
        cout<< "--------------------------"<< endl;

        switch (userChoice) {
        case 1: {
            int insertChoice;
            cout << "Choose an insertion option:" << endl;
            cout << "1: Insert at the start" << endl;
            cout << "2: Insert at the end" << endl;
            cout << "3: Insert at a any position" << endl;
            cout << "Enter your choice: ";
            cin >> insertChoice;
            cout<< "--------------------------" << endl;

            switch (insertChoice) {
            case 1:
                cout << "Enter the value to insert at the start: ";
                cin >> inputValue;
                insertAtStart(inputValue, head);
                break;
            case 2:
                cout << "Enter the value to insert at the end: ";
                cin >> inputValue;
                insertAtEnd(inputValue, head);
                break;
            case 3: {
                int position;
                cout << "Enter the value to insert: ";
                cin >> inputValue;
                cout << "Enter the position to insert at: ";
                cin >> position;
                insertAtPosition(inputValue, head, position);
                break;
            }
            default:
                cout << "Invalid option! Please try again." << endl;
                break;
            }
            break;
        }
        case 2:
            cout << "The current list is: " << endl;
            displayList(head);
            break;
        case 3: {
            int position;
            cout << "Enter the position to update: ";
            cin >> position;
            cout << "Enter the new value: ";
            cin >> inputValue;
            updateValue(head, position, inputValue);
            break;
        }
        case 4: {
            int position;
            cout << "Enter the position to delete: ";
            cin >> position;
            deleteAtPosition(position, head);
            break;
        }
        case 0:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid option! Please try again." << endl;
            break;
        }
    } while (userChoice != 0);

    return 0;
}