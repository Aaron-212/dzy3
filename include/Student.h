#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student {
  public:
    int id;                 // Unique identifier for the student
    std::string name;       // Student's name
    std::string department; // Student's department

    // Constructor
    Student() : id(0), name("") {}

    Student(int id, const std::string &name) : id(id), name(name) {}

    Student(int id, const std::string &name, const std::string &department)
        : id(id), name(name), department(department) {}

    // Database format output
    std::string to_db_string() const { return std::to_string(id) + ", '" + name + "', '" + department + "'"; }

    // Operator overload
    bool operator==(const Student &other) const { return id == other.id; }

    friend std::ostream &operator<<(std::ostream &os, const Student &student) {
        os << "Student ID: " << student.id << ", Name: " << student.name << ", Department: " << student.department;
        return os;
    }

    // cin overload
    friend std::istream &operator>>(std::istream &is, Student &student) {
        std::cout << "Enter student ID: ";
        is >> student.id;
        std::cout << "Enter student name: ";
        is.ignore();
        std::getline(is, student.name);
        std::cout << "Enter student department: ";
        std::getline(is, student.department);
        return is;
    }
};

#endif // STUDENT_H
