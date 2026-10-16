#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Stack
{
private:
    Node *head;
    int count;

public:
    Stack()
    {
        head = NULL;
        count = 0;
    }

    // 2. Destructor
    ~Stack()
    {
        while (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool isEmpty()
    {
        return head == NULL;
    }
    void push(int value)
    {
        Node *newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        count++;

        cout << value << " pushed into stack." << endl;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot pop." << endl;
        }
        else
        {
            Node *temp = head;

            cout << temp->data << " popped from stack." << endl;

            head = head->next;

            delete temp;

            count--;
        }
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return -1;
        }

        return head->data;
    }

    int size()
    {
        return count;
    }
};

// Main function
int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "\nTop element: " << s.top() << endl;

    cout << "Stack size: " << s.size() << endl;

    s.pop();

    cout << "\nTop element after pop: " << s.top() << endl;

    cout << "Stack size: " << s.size() << endl;

    if (s.isEmpty())
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}