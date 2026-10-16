#include <iostream>
#include <string>

using namespace std;

// 1. Node Class
class Node {
public:
    string url;
    Node* next;

    // Constructor
    Node(string u) {
        url = u;
        next = NULL;
    }
};

// 2. Class: BrowserHistory (Stack ADT using Linked List)
class BrowserHistory {
private:
    Node* head;
    int count;

public:
    // Constructor
    BrowserHistory() {
        head = NULL;
        count = 0;
    }

    // Destructor to free all nodes
    ~BrowserHistory() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        cout << "All memory released successfully." << endl;
    }

    // Check if empty
    bool isEmpty() {
        return head == NULL;
    }

    // Visit a new page (Push operation)
    void visit(string url) {
        Node* newNode = new Node(url);
        newNode->next = head;
        head = newNode;
        count++;
        cout << "Visited: " << url << endl;
    }

    // Back button (Pop operation)
    void back() {
        if (isEmpty()) {
            cout << "History is empty. Cannot go back." << endl;
        } else {
            Node* temp = head;
            cout << "Back button pressed. Removed: " << temp->url << endl;
            head = head->next;
            delete temp;
            count--;
        }
    }

    // Return the top URL (Current Page)
    string currentPage() {
        if (isEmpty()) {
            return "No pages";
        }
        return head->url;
    }

    // Return the number of pages in history
    int size() {
        return count;
    }

    // Display all pages from top to bottom
    void display() {
        if (isEmpty()) {
            cout << "History is now empty." << endl;
            return;
        }
        cout << "History (Top to Bottom)" << endl;
        Node* current = head;
        while (current != NULL) {
            cout << current->url << endl;
            current = current->next;
        }
    }
};

// Main Program
int main() {
    cout << "========== BROWSER HISTORY MANAGEMENT ==========" << endl;

    BrowserHistory history;

    // Visit at least 4 pages using visit()[cite: 68]
    history.visit("google.com");
    history.visit("youtube.com");
    history.visit("github.com");
    history.visit("stackoverflow.com");
    cout << endl;

    // Display the history[cite: 68]
    history.display();
    cout << endl;

    // Call back() once[cite: 68]
    history.back();
    cout << endl;

    // Display the history again[cite: 68]
    history.display();
    cout << endl;

    // Show the current page and the size[cite: 68]
    cout << "Current Page: " << history.currentPage() << endl;
    cout << "History Size: " << history.size() << endl;
    cout << endl;

    // Call back() until the stack is empty[cite: 68]
    history.back();
    history.back();
    history.back();
    cout << endl;

    // Verify that isEmpty() returns true[cite: 68]
    if (history.isEmpty()) {
        cout << "History is now empty." << endl;
    } else {
        cout << "History is not empty." << endl;
    }

    cout << "==========================================================" << endl;

    return 0;
}