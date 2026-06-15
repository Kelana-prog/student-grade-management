#include <iostream>
#include <vector>
#include <cctype>
#include "student-grade.h"
#include "Student.h"

using namespace std;

// Global storage
vector<Student> students;

// Menu
void showMenu() {
    cout << "\n===== Student Grade Management System =====\n";
    cout << "1. Add Student\n";
    cout << "2. Display Students\n";
    cout << "3. Search Student\n";
    cout << "4. Sort Students\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Add Student FUNCTION (fully working)
void addStudent() {
    string id, name;
    char grade;

    cout << "\nEnter Student ID: ";
    cin >> id;

    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Grade (A/B/C/D/F): ";
    cin >> grade;

    grade = toupper(grade);

    // Validate grade
    if (grade != 'A' && grade != 'B' && grade != 'C' &&
        grade != 'D' && grade != 'F') {
        cout << "Invalid grade! Student not added.\n";
        return;
    }

    Student s;
    s.setData(id, name, grade);

    students.push_back(s);

    cout << "Student added successfully!\n";
}

// Add Display Student FUNCTION (fully working)
void displayStudents() {
    if (students.empty()) {
        cout << "\nNo student records found.\n";
        return;
    }

    cout << "\n===== Student List =====\n";

    for (int i = 0; i < students.size(); i++) {
        students[i].display();
    }
}

// Placeholder functions
void searchStudent() {
    cout << "Function not implemented yet.\n";
}

void sortStudents() {
    cout << "Function not implemented yet.\n";
}