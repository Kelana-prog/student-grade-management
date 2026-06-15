#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string id;
    string name;
    char grade;

public:
    // Setter function
    void setData(string i, string n, char g) {
        id = i;
        name = n;
        grade = g;
    }

    // Getter functions
    string getId() {
        return id;
    }

    string getName() {
        return name;
    }

    char getGrade() {
        return grade;
    }

    // Display function
    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Grade: " << grade << endl;
        cout << "----------------------\n";
    }
};

#endif