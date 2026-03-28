#include "../include/Student.h"
#include <iostream>

using namespace std;

Student::Student(string name, int age, float grade) {
    this->name = name;
    this->age = age;
    
    if (grade >= 0 && grade <= 5) {
        this->grade = grade;
    } else {
        this->grade = 0;
    }
}

string Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}

float Student::getGrade() const {
    return grade;
}

void Student::setGrade(float grade) {
    if (grade >= 0 && grade <= 5) {
        this->grade = grade;
    }
}

void Student::display() const {
    cout << "Nombre: " << name << endl;
    cout << "Edad: " << age << endl;
    cout << "Promedio: " << grade << endl;
}