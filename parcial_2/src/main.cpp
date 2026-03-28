#include <iostream>
#include <vector>
#include "../include/Student.h"

using namespace std;

int main() {
    vector<Student> students;

    string name;
    int age;
    float grade;

    for (int i = 0; i < 2; i++) {
        cout << "Ingrese nombre: ";
        cin >> name;

        cout << "Ingrese edad: ";
        cin >> age;

        cout << "Ingrese promedio (0-5): ";
        cin >> grade;

        Student s(name, age, grade);
        students.push_back(s);
    }

    cout << "\n--- Lista de estudiantes ---\n";

    for (const auto& s : students) {
        s.display();
        cout << "----------------------\n";
    }

    return 0;
}