#include <iostream>
using namespace std;

int main()
{
    int stack[5];
    int top = -1;
    int value;

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter value: ";
        cin >> value;

        top++;
        stack[top] = value;
    }

    cout << "\nStack:\n";

    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << endl;
    }

    return 0;
}