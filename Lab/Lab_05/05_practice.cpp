#include <iostream>
using namespace std;

int main()
{
    int stackArray[5];
    int stackSize = 5;
    int top = -1;
    int num = 20;
    if (top == stackSize - 1)
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        top++;
        stackArray[top] = num;

        cout << num << " pushed into stack" << endl;
    }

    cout << "Top element: "
         << stackArray[top] << endl;

    if (top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Popped element: "
             << stackArray[top] << endl;

        top--;
    }

    if (top == -1)
    {
        cout << "Stack is now empty" << endl;
    }
    else
    {
        cout << "Top element after Pop: "
             << stackArray[top] << endl;
    }

    return 0;
}