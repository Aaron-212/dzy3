#ifndef COURSE_H
#define COURSE_H

#include <iostream>

class Course {
  public:
    int id;           // Unique identifier for the course
    std::string name; // Name of the course
    int credits;      // Number of credits for the course

    // Constructor
    Course() {
        id = 0;
        name = "";
        credits = 0;
    }
    Course(int id, const std::string &name, int credits) {
        this->id = id;
        this->name = name;
        this->credits = credits;
    }

    // Operator== overload
    bool operator==(const Course &rhs) const { return id == rhs.id; }
    friend std::ostream &operator<<(std::ostream &os, const Course &course) {
        os << "Course ID: " << course.id << ", Name: " << course.name << ", Credits: " << course.credits;
        return os;
    }
};

#endif // COURSE_H
