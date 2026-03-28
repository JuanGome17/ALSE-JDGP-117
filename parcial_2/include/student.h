#ifndef STUDENT_H
#define STUDENT_H

#include <string>

/**
 * @class Student
 * @brief Representa un estudiante con nombre, edad y promedio.
 */
class Student {
private:
    std::string name;
    int age;
    float grade;

public:
    /**
     * @brief Constructor de la clase Student
     */
    Student(std::string name, int age, float grade);

    /**
     * @brief Obtiene el nombre del estudiante
     */
    std::string getName() const;

    /**
     * @brief Obtiene la edad
     */
    int getAge() const;

    /**
     * @brief Obtiene el promedio
     */
    float getGrade() const;

    /**
     * @brief Modifica el promedio
     */
    void setGrade(float grade);

    /**
     * @brief Muestra la información del estudiante
     */
    void display() const;
};

#endif