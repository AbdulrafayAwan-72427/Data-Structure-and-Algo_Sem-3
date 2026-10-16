#include <iostream>

using namespace std;

// 1. Node Structure
struct Node {
    int data;
    Node* next;
};

// 2. Class: StudentLinkedList
class StudentLinkedList {
private:
    Node* head;

public:
    // Constructor
    StudentLinkedList() {
        head = NULL;
    }

    // Append (Add at End)
    void append(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Insert at a specific position (1-based)
    void insert(int position, int value) {
        Node* newNode = new Node;
        newNode->data = value;

        if (position == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 1; i < position - 1 && current != NULL; i++) {
                current = current->next;
            }
            if (current != NULL) {
                newNode->next = current->next;
                current->next = newNode;
            }
        }
    }

    // Remove at a specific position (1-based)
    void remove(int position) {
        if (head == NULL) return;

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            for (int i = 1; i < position - 1 && current != NULL; i++) {
                current = current->next;
            }
            if (current != NULL && current->next != NULL) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
            }
        }
    }

    // Search for a value (returns 1-based position or -1)
    int search(int value) {
        Node* current = head;
        int position = 1;
        while (current != NULL) {
            if (current->data == value) {
                return position;
            }
            current = current->next;
            position++;
        }
        return -1;
    }

    // Display the list
    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
    }

    // Destructor to free all allocated memory
    ~StudentLinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        cout << "All memory released successfully." << endl;
    }
};

// Main Program
int main() {
    cout << "========== STUDENT ROLL NUMBER MANAGEMENT ==========" << endl;

    StudentLinkedList list;

    // Add at least 5 roll numbers using append[cite: 50]
    list.append(101);
    list.append(102);
    list.append(103);
    list.append(104);
    list.append(105);

    // Display the list[cite: 50]
    cout << "Original List: ";
    list.display();
    cout << endl;

    // Insert a roll number at position 3 (value 999)[cite: 50, 51]
    list.insert(3, 999);
    cout << "After Insert (position 3, value 999): ";
    list.display();
    cout << endl;

    // Delete the roll number at position 2[cite: 50, 51]
    list.remove(2);
    cout << "After Delete (position 2): ";
    list.display();
    cout << endl;

    // Search for 103[cite: 50, 51]
    int pos1 = list.search(103);
    if (pos1 != -1) {
        cout << "Searching for 103. Found at position " << pos1 << endl;
    } else {
        cout << "Searching for 103... Not found" << endl;
    }

    // Search for 555[cite: 50, 51]
    int pos2 = list.search(555);
    if (pos2 != -1) {
        cout << "Searching for 555. Found at position " << pos2 << endl;
    } else {
        cout << "Searching for 555... Not found" << endl;
    }

    cout << "==========================================================" << endl;

    return 0;
}