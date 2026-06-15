#include <iostream>
#include "student-grade.h"
using namespace std;

int main() {
    int choice;

    loadFromFile();

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            sortStudents();
            break;
        case 5:
            cout << "\nExiting program...\n";
            break;
        default:
            cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}