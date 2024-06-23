#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

class Course {
  public:
    int id;           // Unique identifier for the course
    std::string name; // Name of the course
    int credits;      // Number of credits for the course

    // Constructor
    Course() : id(0), name(""), credits(0) {}

    Course(int id, const std::string &name, int credits) : id(id), name(name), credits(credits) {}

    // Database format output
    std::string to_db_string() const { return std::to_string(id) + ", '" + name + "', " + std::to_string(credits); }

    // Operator== overload
    bool operator==(const Course &rhs) const { return id == rhs.id; }

    friend std::ostream &operator<<(std::ostream &os, const Course &course) {
        os << "Course ID: " << course.id << ", Name: " << course.name << ", Credits: " << course.credits;
        return os;
    }

    // cin overload
    friend std::istream &operator>>(std::istream &is, Course &course) {
        std::cout << "Enter course ID: ";
        is >> course.id;
        std::cout << "Enter course name: ";
        is.ignore();
        std::getline(is, course.name);
        std::cout << "Enter course credits: ";
        is >> course.credits;
        return is;
    }
};

#endif // COURSE_H
