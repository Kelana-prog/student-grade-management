#include <iostream>
#include <vector>
#include <cctype>
#include <fstream>
#include <sstream>
#include "student-grade.h"
#include "Student.h"

using namespace std;

// Global storage
vector<Student> students;


// ================= MENU =================
void showMenu() {
    cout << "\n===== Student Grade Management System =====\n";
    cout << "1. Add Student\n";
    cout << "2. Display Students\n";
    cout << "3. Search Student\n";
    cout << "4. Sort Students\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}


// ================= ADD =================
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

    if (grade != 'A' && grade != 'B' && grade != 'C' &&
        grade != 'D' && grade != 'F') {
        cout << "Invalid grade!\n";
        return;
    }

    Student s;
    s.setData(id, name, grade);
    students.push_back(s);

    cout << "Student added successfully!\n";
}


// ================= DISPLAY =================
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


// ================= SEARCH =================
void searchStudent() {
    if (students.empty()) {
        cout << "\nNo student records found.\n";
        return;
    }

    int choice;
    cout << "\nSearch by:\n";
    cout << "1. ID\n";
    cout << "2. Name\n";
    cout << "3. Grade\n";
    cout << "Enter choice: ";
    cin >> choice;

    bool found = false;

    if (choice == 1) {
        string searchId;
        cout << "Enter ID: ";
        cin >> searchId;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == searchId) {
                students[i].display();
                found = true;
            }
        }
    }

    else if (choice == 2) {
        string searchName;
        cout << "Enter name (or part of name): ";
        cin.ignore();
        getline(cin, searchName);

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getName().find(searchName) != string::npos) {
                students[i].display();
                found = true;
            }
        }
    }

    else if (choice == 3) {
        char searchGrade;
        cout << "Enter grade: ";
        cin >> searchGrade;

        searchGrade = toupper(searchGrade);

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getGrade() == searchGrade) {
                students[i].display();
                found = true;
            }
        }
    }

    if (!found) {
        cout << "\nNo matching student found.\n";
    }
}


// ================= QUICK SORT (ID) =================
int partitionID(vector<Student>& students, int low, int high, bool ascending) {
    string pivot = students[high].getId();
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if ((ascending && students[j].getId() < pivot) ||
            (!ascending && students[j].getId() > pivot)) {
            i++;
            swap(students[i], students[j]);
        }
    }

    swap(students[i + 1], students[high]);
    return i + 1;
}

void quickSortID(vector<Student>& students, int low, int high, bool ascending) {
    if (low < high) {
        int pi = partitionID(students, low, high, ascending);

        quickSortID(students, low, pi - 1, ascending);
        quickSortID(students, pi + 1, high, ascending);
    }
}


// ================= QUICK SORT (NAME) =================
int partitionName(vector<Student>& students, int low, int high, bool ascending) {
    string pivot = students[high].getName();
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if ((ascending && students[j].getName() < pivot) ||
            (!ascending && students[j].getName() > pivot)) {
            i++;
            swap(students[i], students[j]);
        }
    }

    swap(students[i + 1], students[high]);
    return i + 1;
}

void quickSortName(vector<Student>& students, int low, int high, bool ascending) {
    if (low < high) {
        int pi = partitionName(students, low, high, ascending);

        quickSortName(students, low, pi - 1, ascending);
        quickSortName(students, pi + 1, high, ascending);
    }
}


// ================= SORT =================
void sortStudents() {
    if (students.empty()) {
        cout << "\nNo student records to sort.\n";
        return;
    }

    int fieldChoice, orderChoice;

    cout << "\nSort by:\n";
    cout << "1. ID\n";
    cout << "2. Name\n";
    cout << "Enter choice: ";
    cin >> fieldChoice;

    cout << "\nOrder:\n";
    cout << "1. Ascending\n";
    cout << "2. Descending\n";
    cout << "Enter choice: ";
    cin >> orderChoice;

    bool ascending = (orderChoice == 1);

    if (fieldChoice == 1) {
        quickSortID(students, 0, students.size() - 1, ascending);
    }
    else if (fieldChoice == 2) {
        quickSortName(students, 0, students.size() - 1, ascending);
    }
    else {
        cout << "Invalid choice!\n";
        return;
    }

    cout << "\nStudents sorted successfully!\n";

    displayStudents();
}

// ================= LOAD DUMMY DATA =================
void loadFromFile() {
    ifstream file("students.txt");

    if (!file) {
        cout << "\nError opening file!\n";
        return;
    }

    string line;

    while (getline(file, line)) {
        string id, name, gradeStr;

        stringstream ss(line);

        // split by comma
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, gradeStr, ',');

        char grade = gradeStr[0];  // convert string to char

        Student s;
        s.setData(id, name, grade);

        students.push_back(s);
    }

    file.close();

    cout << "\nData loaded from file successfully!\n";
}
