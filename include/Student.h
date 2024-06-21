#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class Student {
  public:
    int id;           // Unique identifier for the student
    std::string name; // Student's name

    // Constructor
    Student() {
        id = 0;
        name = "";
    }
    Student(int id, const std::string &name) {
        this->id = id;
        this->name = name;
    }

    // Operator overload
    bool operator==(const Student &other) const { return id == other.id; }
    friend std::ostream &operator<<(std::ostream &os, const Student &student) {
        os << "Student ID: " << student.id << ", Name: " << student.name;
        return os;
    }
};

#endif // STUDENT_H
