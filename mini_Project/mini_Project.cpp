#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

struct Employee {
    int id;
    string name;
    double salary;
};

class PayrollSystem {
private:
    Employee* employees;
    int capacity;
    int size;

    void resize() {
        capacity *= 2;
        Employee* temp = new Employee[capacity];
        for (int i = 0; i < size; i++) {
            temp[i] = employees[i];
        }
        delete[] employees;
        employees = temp;
    }

public:
    PayrollSystem(int initialCap = 2) {
        capacity = initialCap;
        size = 0;
        employees = new Employee[capacity];
    }

    ~PayrollSystem() {
        delete[] employees;
    }

    void addEmployee(int id, const string& name, double salary) {
        if (size == capacity) {
            resize();
        }
        employees[size].id = id;
        employees[size].name = name;
        employees[size].salary = salary;
        size++;
        cout << "Employee added successfully.\n";
    }

    // Linear search by Employee ID
    int searchEmployee(int id) const {
        for (int i = 0; i < size; i++) {
            if (employees[i].id == id) {
                return i;
            }
        }
        return -1;
    }

    // Sort by salary: Ascending (order = true) or Descending (order = false)
    void sortBySalary(bool ascending = true) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                bool condition = ascending ? (employees[j].salary > employees[j + 1].salary)
                                           : (employees[j].salary < employees[j + 1].salary);
                if (condition) {
                    Employee temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
        cout << "Sorted by salary (" << (ascending ? "Low to High" : "High to Low") << ").\n";
    }

    void display() const {
        if (size == 0) {
            cout << "No employee records found.\n";
            return;
        }
        cout << "\n--------------------------------------------------\n";
        cout << left << setw(10) << "ID" << setw(25) << "Name" << setw(15) << "Salary" << "\n";
        cout << "--------------------------------------------------\n";
        for (int i = 0; i < size; i++) {
            cout << left << setw(10) << employees[i].id
                 << setw(25) << employees[i].name
                 << fixed << setprecision(2) << setw(15) << employees[i].salary << "\n";
        }
        cout << "--------------------------------------------------\n";
    }
};

int main() {
    PayrollSystem sys(2);
    int choice;

    do {
        cout << "\n--- Employee Payroll Menu ---\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All\n";
        cout << "3. Search by ID\n";
        cout << "4. Sort by Salary (Ascending)\n";
        cout << "5. Sort by Salary (Descending)\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            double sal;
            while (true) {
                cout << "Enter ID (positive integer): ";
                if (cin >> id && id > 0) {
                    break;
                }
                cout << "Error: ID must be a positive integer.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Enter Name: "; cin.ignore(); getline(cin, name);
            while (true) {
                cout << "Enter Salary (positive number): ";
                if (cin >> sal && sal > 0) {
                    break;
                }
                cout << "Error: Salary must be a positive number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            sys.addEmployee(id, name, sal);
        } else if (choice == 2) {
            sys.display();
        } else if (choice == 3) {
            int id;
            while (true) {
                cout << "Enter ID to search (positive integer): ";
                if (cin >> id && id > 0) {
                    break;
                }
                cout << "Error: ID must be a positive integer.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            int idx = sys.searchEmployee(id);
            if (idx != -1) cout << "Employee found at index: " << idx << "\n";
            else cout << "Employee not found.\n";
        } else if (choice == 4) {
            sys.sortBySalary(true);
            sys.display();
        } else if (choice == 5) {
            sys.sortBySalary(false);
            sys.display();
        }
    } while (choice != 6);

    return 0;
}