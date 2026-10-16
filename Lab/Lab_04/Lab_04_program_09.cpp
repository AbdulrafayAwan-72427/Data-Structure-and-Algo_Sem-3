#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
class LinkedList{
private:
    Node* head;
public:
    LinkedList(){
        head = NULL;
    }
    void append(int value){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL){
            head = newNode;
        }
        else{
            Node* current = head;
            while (current->next != NULL){
                current = current->next;
            }
            current->next = newNode;
        }
    }
    void insert(int position, int value){
        Node* newNode = new Node;
        newNode->data = value;
        if (position == 1){
            newNode->next = head;
            head = newNode;
        }
        else{
            Node* current = head;
            for (int i = 1; i < position - 1; i++){
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
void remove(int position) {
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    else {
        Node* current = head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }

        Node* temp = current->next;          // Keep track of the node we want to delete
        current->next = temp->next;    // Unlink the node from the list
        delete temp;                   // Free the memory
    }
}

    void display(){
        Node* current = head;
        while (current != NULL){
            cout << current->data << " ";
            current = current->next;
        }
    }
};
int main(){
    LinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    cout << "Original List: ";
    list.display();
    list.insert(3, 25);
    cout << "\nAfter Insert: ";
    list.display();
    list.remove(3);
    cout << "\nAfter Deletion: ";
    list.display();
    return 0;
}