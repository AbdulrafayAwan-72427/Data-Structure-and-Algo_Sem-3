#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& str)
{
    size_t n = str.length();

    // Stack sized to the input, so any length string is safe
    char* stack = new char[n + 1];
    int top = -1;

    // Step 1: Push every character into stack
    for (size_t i = 0; i < n; i++)
    {
        top++;
        stack[top] = str[i];
    }

    // Step 2: Compare string with stack (reverse order)
    // Only half needs checking - the second half mirrors the first
    bool result = true;
    for (size_t i = 0; i < n / 2; i++)
    {
        if (str[i] != stack[top])
        {
            result = false;
            break;
        }

        top--;
    }

    delete[] stack;
    return result;
}

int main()
{
    string str;

    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str))
        cout << "\"" << str << "\" is a Palindrome" << endl;
    else
        cout << "\"" << str << "\" is NOT a Palindrome" << endl;

    return 0;
}