#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Course.h"
#include "Score.h"
#include "Student.h"
#include <algorithm>
#include <string>
#include <vector>

class Department {
  public:
    std::string name;              // Name of the department
    std::vector<Student> students; // Students belonging to the department
    std::vector<Course> courses;   // Courses offered by the department
    std::vector<Score> scores;     // Scores of students in the department

    // Constructor
    Department(const std::string &name) : name(name) {}

    // Mutators
    void addStudent(const Student &student) { students.push_back(student); }
    void removeStudent(const Student &student) {
        students.erase(std::remove(students.begin(), students.end(), student), students.end());
    }

    void addCourse(const Course &course) { courses.push_back(course); }
    void removeCourse(const Course &course) {
        courses.erase(std::remove(courses.begin(), courses.end(), course), courses.end());
    }

    void addScore(const Score &score) { scores.push_back(score); }
    void removeScore(const Score &score) {
        scores.erase(std::remove(scores.begin(), scores.end(), score), scores.end());
    }
};

#endif // DEPARTMENT_H
