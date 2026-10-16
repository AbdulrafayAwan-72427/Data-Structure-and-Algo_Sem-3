#include <iostream>

using namespace std;

// CLASS: StudentList (ADT)
class StudentList
{
private:
    int rollNumbers[10];
    int size;

public:
    // Constructor
    StudentList()
    {
        size = 0;
    }

    // Get current length
    int getLength()
    {
        return size;
    }

    // Add at the end
    void add(int roll)
    {
        if (size < 10)
        {
            rollNumbers[size] = roll;
            size++;
        }
    }

    // Insert at position (1-based)
    void insert(int position, int roll)
    {
        for (int i = size; i > position - 1; i--)
        {
            rollNumbers[i] = rollNumbers[i - 1];
        }
        rollNumbers[position - 1] = roll;
        size++;
    }

    // Delete at position (1-based)
    void deleteElement(int position)
    {
        for (int i = position - 1; i < size - 1; i++)
        {
            rollNumbers[i] = rollNumbers[i + 1];
        }
        size--;
    }

    // Search for a roll number
    int search(int roll)
    {
        for (int i = 0; i < size; i++)
        {
            if (rollNumbers[i] == roll)
            {
                return i + 1;
            }
        }
        return -1;
    }

    // Display all roll numbers
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << rollNumbers[i] << " ";
        }
    }
};

// MAIN PROGRAM
int main()
{
    StudentList list;

    cout << "========== STUDENT RECORD MANAGEMENT SYSTEM ==========" << endl;

    // Add students
    int n;
    cout << "\nHow many students do you want to add? ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int roll;
        cout << "Enter roll number: ";
        cin >> roll;
        list.add(roll);
    }

    // Display list
    cout << "\n--- Student Roll Numbers" << endl;
    list.display();
    cout << "\nLength: " << list.getLength() << endl;

    // Delete
    int deletePosition;
    cout << "\nEnter position to delete: ";
    cin >> deletePosition;
    list.deleteElement(deletePosition);
    cout << "After Delete: ";
    list.display();
    cout << "\nLength: " << list.getLength() << endl;

    // Search
    int searchRoll;
    cout << "\nEnter roll number to search: ";
    cin >> searchRoll;

    int searchPosition = list.search(searchRoll);

    if (searchPosition != -1)
    {
        cout << "Roll number found at position: " << searchPosition << endl;
    }
    else
    {
        cout << "Roll number not found" << endl;
    }

    // Insert
    int insertPosition;
    int insertRoll;

    cout << "\nEnter position to insert: ";
    cin >> insertPosition;
    cout << "Enter roll number to insert: ";
    cin >> insertRoll;

    list.insert(insertPosition, insertRoll);
    cout << "After Insert: ";
    list.display();
    cout << "\nLength: " << list.getLength() << endl;

    cout << "\n========================================================" << endl;
    cout << "Final Length of List: " << list.getLength() << endl;
    cout << "========================================================" << endl;

    return 0;
}