#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;    
};
int main()
{
        Node* head = NULL;
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
        cout<<"\nLinked List: ";
        current = head;\
        while(current!=NULL){
            cout<<current->data<<" ";
            current = current->next;
        }
    }
