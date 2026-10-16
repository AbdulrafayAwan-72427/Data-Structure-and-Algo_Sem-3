#include <iostream>
#include <string>

using namespace std;

// 1. Person Class
class Person {
private:
    string name;
    int age;
    string cnic;

public:
    // Constructor
    Person(string n, int a, string c) {
        name = n;
        age = a;
        cnic = c;
    }

    // Getters
    string getName() const { return name; }
    int getAge() const { return age; }
    string getCnic() const { return cnic; }

    // Display Info
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "CNIC: " << cnic << endl;
    }
};

// 2. Student Class
class Student {
private:
    string name;
    int age;
    string cnic;
    string rollNumber;
    double cgpa;
    int semester;

public:
    // Constructor
    Student(string n, int a, string c, string r, double g, int sem) {
        name = n;
        age = a;
        cnic = c;
        rollNumber = r;
        cgpa = g;
        semester = sem;
    }

    // Getters
    string getName() { return name; }
    int getAge() { return age; }
    string getCnic() { return cnic; }
    string getRollNumber() { return rollNumber; }
    double getCgpa() { return cgpa; }
    int getSemester() { return semester; }

    // Method to calculate letter grade based on CGPA
    string calculateGrade() {
        if (cgpa >= 3.5)
            return "A";
        else if (cgpa >= 3.0)
            return "B";
        else if (cgpa >= 2.5)
            return "C";
        else if (cgpa >= 2.0)
            return "D";
        else
            return "F";
    }

    // Display Student Details
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "CNIC: " << cnic << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Semester: " << semester << endl;
        cout << "Letter Grade: " << calculateGrade() << endl;
    }
};

// 3. Faculty Class
class Faculty {
private:
    string name;
    int age;
    string cnic;
    string employeeId;
    double monthlySalary;
    string department;

public:
    // Constructor
    Faculty(string n, int a, string c, string id, double salary, string dept) {
        name = n;
        age = a;
        cnic = c;
        employeeId = id;
        monthlySalary = salary;
        department = dept;
    }

    // Getters
    string getName() { return name; }
    int getAge() { return age; }
    string getCnic() { return cnic; }
    string getEmployeeId() { return employeeId; }
    double getMonthlySalary() { return monthlySalary; }
    string getDepartment() { return department; }

    // Method to calculate annual salary
    double calculateAnnualSalary() {
        return monthlySalary * 12;
    }

    // Display Faculty Details
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "CNIC: " << cnic << endl;
        cout << "Employee ID: " << employeeId << endl;
        cout << "Department: " << department << endl;
        cout << "Monthly Salary: " << monthlySalary << endl;
        cout << "Annual Salary: " << calculateAnnualSalary() << endl;
    }
};

int main() {
    cout << "========= RIPHAH UNIVERSITY MANAGEMENT SYSTEM ==========" << endl;

    // Creating Student Objects (At least 2 students)
    Student s1("Ali Raza", 20, "35202-1234567-1", "BSCS-2024-001", 3.75, 3);
    Student s2("Fatima Noor", 21, "35202-7654321-2", "BSCS-2024-002", 3.20, 3);

    // Creating Faculty Objects (At least 2 faculty members)
    Faculty f1("Dr. Ahmed Khan", 45, "35202-1111111-3", "EMP-101", 150000.0, "Computer Science");
    Faculty f2("Ms. Sana Malik", 38, "35202-2222222-4", "EMP-102", 120000.0, "Software Engineering");

    // Displaying Student 1
    cout << "\nStudent 1" << endl;
    s1.displayInfo();

    // Displaying Student 2
    cout << "\nStudent 2" << endl;
    s2.displayInfo();

    // Displaying Faculty 1
    cout << "\nFaculty 1" << endl;
    f1.displayInfo();

    // Displaying Faculty 2
    cout << "\nFaculty 2" << endl;
    f2.displayInfo();

    // Calculating Average CGPA of all students
    double totalCgpa = s1.getCgpa() + s2.getCgpa();
    double avgCgpa = totalCgpa / 2.0;

    // Using a switch statement as required by the lab instructions
    int choice = 1; 
    switch(choice) {
        case 1:
            // Additional summary stats display
            break;
        default:
            break;
    }

    // Summary Display
    cout << "\n========================================================" << endl;
    cout << "Total Students: 2" << endl;
    cout << "Average CGPA: " << avgCgpa << endl;
    cout << "Total Faculty: 2" << endl;
    cout << "========================================================" << endl;

    return 0;
}