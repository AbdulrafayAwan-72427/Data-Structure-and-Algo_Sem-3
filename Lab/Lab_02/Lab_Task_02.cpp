#include <iostream>

using namespace std;

int main() {
    cout << "========== STUDENT MARKS MANAGEMENT SYSTEM ==========" << endl;

    int n;
    cout << "Enter number of students: ";
    cin >> n;

    // 1. Dynamic Array Creation using new operator
    int *marks = new int[n];

    // 2. Input Marks using pointer arithmetic
    cout << "Enter marks for " << n << " students:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Student " << (i + 1) << ": ";
        cin >> *(marks + i);
    }

    // 3. Display Marks using pointer arithmetic
    cout << "\nStudent Marks" << endl;
    for (int i = 0; i < n; i++) {
        cout << *(marks + i) << " ";
    }
    cout << endl;

    // 4. Search for a Mark using pointer traversal
    int searchMark;
    cout << "Enter mark to search: ";
    cin >> searchMark;

    bool found = false;
    int foundIndex = -1;
    for (int i = 0; i < n; i++) {
        if (*(marks + i) == searchMark) {
            found = true;
            foundIndex = i;
            break;
        }
    }

    if (found) {
        cout << "Mark found at index " << foundIndex << endl;
    } else {
        cout << "Mark not found" << endl;
    }

    // 5. Find Highest and Lowest Marks & 6. Calculate Average
    int highest = *marks;
    int lowest = *marks;
    double sum = *marks;

    for (int i = 1; i < n; i++) {
        int val = *(marks + i);
        sum += val;
        if (val > highest) {
            highest = val;
        }
        if (val < lowest) {
            lowest = val;
        }
    }

    double average = sum / n;

    // Display Statistics
    cout << "\nStatistics" << endl;
    cout << "Highest Mark: " << highest << endl;
    cout << "Lowest Mark: " << lowest << endl;
    cout << "Average Mark: " << average << endl;

    // 7. Free Memory using delete[]
    delete[] marks;
    cout << "Memory released successfully." << endl;
    cout << "================================================" << endl;

    return 0;
}