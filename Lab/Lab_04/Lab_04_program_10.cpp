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
    void input(){
        Node* current = NULL;
        int n;
        cout<<"How many nodes you wanr to Create? ";
        cin>>n;
        for(int i = 1;i <= n;i++){
            Node* newNode = new Node; //alocate memory
            cout<<"Enter data for: "<<i<<" Node"<<endl;
            cin>>newNode->data;
            newNode->next = NULL;
            if(head ==NULL){
                head = newNode;
                current = newNode;
            }
            else{
                current->next = newNode;
                current = newNode;
            }
        }
        cout<<"Enter 1 to insert an element in the Linked List. "<<endl;
        cout<<"Enter 2 to delete an element in the Linked List. "<<endl;
        cout<<"Enter 3 to append an element in the Linked List. "<<endl;
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the position that you want the element to be inserted: ";
                int position;
                cin>>position;
                cout<<"Enter the value to be inserted: ";
                int value;
                cin>>value;
                insert(position,value);
            break;
            case 2:
                cout<<"Enter the position that you want the element to be deleted: ";
                int position_to_del;
                cin>>position_to_del;
                remove(position_to_del);
            break;
            case 3:
                cout<<"Enter the value to be appended: ";
                int value_to_append;
                cin>>value_to_append;
                append(value_to_append);
            break;
            default:
                cout<<"invalid input. ";
                
        }
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
            };
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

    list.input();
    list.display();
    return 0;
}