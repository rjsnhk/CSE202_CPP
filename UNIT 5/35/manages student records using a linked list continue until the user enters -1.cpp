#include <iostream>
using namespace std;

// Define the structure for a node in the linked list
struct Node {
    int data;
    Node* next;
};

// Function to add an element to the linked list
Node* addElement(Node* head, int element) {
    Node* newNode = new Node;
    newNode->data = element;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    return head;
}

// Function to display the elements in the linked list
void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int element;

    // cout << "Enter elements (Enter -1 to stop): ";
    while (cin >> element && element != -1) {
        if (element > 0) {
            head = addElement(head, element);
        } else {
            cout << "Invalid input. Please enter positive numbers." << endl;
        }
    }

    // cout << "Output: ";
    displayList(head);

    return 0;
}

